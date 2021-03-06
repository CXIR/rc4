//
// Created by Ludwig Roger on 15/11/2018.
//

#include <thread>
#include "RC4.h"

using namespace std;

RC4::RC4(string key){
    this->key = key;
}

void RC4::setContent(string content) {
    this->content = content;
}

string RC4::getKey() {
    return this->key;
}

void RC4::setKey(string key) {

}

void RC4::swap(unsigned int a, unsigned int b) {

    unsigned char tmp = this->S[a];
    this->S[a]  = this->S[b];
    this->S[b]  = tmp;
}

void RC4::ksa() {

    for(int i = 0; i < this->mod; i++){
        this->S[i] = i;
    }

    int j = 0;

    for(int i = 0; i < this->mod; i++){

        j = (j + this->S[i] + key[i % key.length()]) % this->mod;
        this->swap(this->S[i], this->S[j]);
    }

}

void RC4::compute(int min, int max, string result){

    int i = 0;
    int j = 0;

    this->lock.lock();

    for(int a = min; a < max; a++){

        i = ( i + 1) % this->mod;
        j = (j + this->S[i]) % this->mod;
        swap(i, j);

        unsigned char k = S[(S[i] + S[j]) % this->mod] ^ this->content[a];
        result += k;

    }
    this->lock.unlock();
}

string RC4::prga() {

    string result = "";
    int content_length = this->content.length();

    //THREAD 1
    int min1 = 0;
    int max1 = content_length/3;

    //THREAD 2
    int min2 = max1+1;
    int max2 = (content_length/3)*2;

    //THREAD 3
    int min3 = max2+1;
    int max3 = content_length;

    unsigned concurrentThreadsSupported = std::thread::hardware_concurrency(); // determine max threads number

    cout << "Number threads supported " << concurrentThreadsSupported << endl;

    /*
    std::thread t2([]() {
        for (int i = 0; i < 10; ++i)
        {
            std::cout << (i * 3) + 1 << " ";
        }
    });
    std::thread t3([]() {
        for (int i = 0; i < 10; ++i)
        {
            std::cout << (i * 3) + 2 << " ";
        }
    });
    */
    //t1.join();
    //t2.join();
    //t3.join();
/*
    std::thread t1( [&lock]() {
        int i = 0;
        int j = 0;

        lock.lock();

        for(int a = min1; a < max1; a++){

            i = ( i + 1) % this->mod;
            j = (j + this->S[i]) % this->mod;
            swap(i, j);

            unsigned char k = S[(S[i] + S[j]) % this->mod] ^ this->content[a];
            result += k;

        }
        lock.unlock();
    });
*/

/*
    std::thread t2([&lock]() {
        int i = 0;
        int j = 0;

        lock.lock();

        for(int a = min2; a < max2; a++){

            i = ( i + 1) % this->mod;
            j = (j + this->S[i]) % this->mod;
            swap(i, j);

            unsigned char k = S[(S[i] + S[j]) % this->mod] ^ this->content[a];
            result += k;

        }
        lock.unlock();
    });
*/

    /*
    std::thread t3([&lock]() {
        int i = 0;
        int j = 0;

        lock.lock();

        for(int a = min3; a < max3; a++){

            i = ( i + 1) % this->mod;
            j = (j + this->S[i]) % this->mod;
            swap(i, j);

            unsigned char k = S[(S[i] + S[j]) % this->mod] ^ this->content[a];
            result += k;

        }
        lock.unlock();
    });
     */


    std::thread t1(&RC4::compute, this, min1, max1, result);
    std::thread t2(&RC4::compute, this, min2, max2, result);
    std::thread t3(&RC4::compute, this, min2, max2, result);


    t1.join();
    t2.join();
    t3.join();


    /*int i = 0;
    int j = 0;

    for(int a = 0; a < this->content.length(); a++){

        i = ( i + 1) % this->mod;
        j = (j + this->S[i]) % this->mod;
        swap(i, j);

        unsigned char k = S[(S[i] + S[j]) % this->mod] ^ this->content[a];
        result += k;

    }*/


    return result;
}
/*
string RC4::compute(){
    return "aaa";
}
 */

