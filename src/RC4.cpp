//
// Created by Ludwig Roger on 15/11/2018.
//

#include <thread>
#include <vector>
#include <algorithm>
#include "RC4.h"

RC4::RC4(std::string key, std::string content) {

    this->key                        = key;
    this->result                     = "";
    this->concurrentThreadsSupported = std::thread::hardware_concurrency(); // determine max supported threads number
    this->content                    = content;
}

void RC4::swap(unsigned int a, unsigned int b) {

    unsigned char tmp = this->S[a];
    this->S[a]  = this->S[b];
    this->S[b]  = tmp;
}

void RC4::KSA() {

    for(int i = 0; i < this->mod; i++){
        this->S[i] = i;
    }

    int j = 0;

    for(int i = 0; i < this->mod; i++){

        j = (j + this->S[i] + key[i % key.length()]) % this->mod;
        this->swap(this->S[i], this->S[j]);
    }

}

void RC4::compute(int min, int max){

    int i = 0;
    int j = 0;

    std::lock_guard<std::mutex> guard(this->lock);
    std::cout << "compute "<<  min << "-" << max << std::endl;

    for(int a = min; a < max; a++){

        i = ( i + 1) % this->mod;
        j = (j + this->S[i]) % this->mod;
        swap(i, j);

        unsigned char k = S[(S[i] + S[j]) % this->mod] ^ this->content[a];
        this->result += k;
    }

    std::cout << " state of the string " << this->result << std::endl;
}

std::string RC4::PRGA() {

    int content_length = this->content.length();

    if(content_length < 255){
        compute(0, content_length-1);
    }
    else {

        std::vector<std::thread> threads;

        int sub_content_length = content_length / this->concurrentThreadsSupported;
        int start_cursor       = 0;
        int end_cursor         = sub_content_length - 1;


        for (int i = 0; i < this->concurrentThreadsSupported; ++i) {
            if( i == this->concurrentThreadsSupported){
                threads.emplace_back( std::thread(&RC4::compute, this, start_cursor + sub_content_length, content_length-1 ));
                //threads.emplace_back( std::thread([this](start_cursor + sub_content_length, content_length-1){ compute(start_cursor + sub_content_length, content_length-1); } ));
            }
            else {
                threads.emplace_back( std::thread(&RC4::compute, this, start_cursor, end_cursor));
            }

            start_cursor += sub_content_length;
            end_cursor   += sub_content_length;
        }

        std::for_each(threads.begin(), threads.end(), [](std::thread& t){
            t.join();
            std::cout << "thread joined" << std::endl;
        });
    }
/*
    //THREAD 1
    int min1 = 0;
    int max1 = content_length/3;

    //THREAD 2
    int min2 = max1+1;
    int max2 = (content_length/3)*2;

    //THREAD 3
    int min3 = max2+1;
    int max3 = content_length;

    std::thread t1(&RC4::compute, this, min1, max1);
    std::thread t2(&RC4::compute, this, min2, max2);
    std::thread t3(&RC4::compute, this, min3, max3);

    t1.join();
    t2.join();
    t3.join();
*/
    return result;
}


