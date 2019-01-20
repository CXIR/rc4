//
// Created by Ludwig Roger on 15/11/2018.
//

#include <thread>
#include <vector>
#include <algorithm>
#include "RC4.h"

RC4::RC4 (std::string key, std::string content, int threads) {

    this->key     = key;
    this->result  = "";
    this->content = content;

    if (threads < 1) {
        this->concurrentThreadsSupported = std::thread::hardware_concurrency(); // determine max supported threads number
    }
    else {
        this->concurrentThreadsSupported = threads;
    }
}

void RC4::swap (unsigned int a, unsigned int b) {

    unsigned char tmp = this->S[a];
    this->S[a]        = this->S[b];
    this->S[b]        = tmp;
}

void RC4::KSA () {

    for (int i = 0; i < this->mod; i++) {

        this->S[i] = i;
    }

    int j = 0;

    for (int i = 0; i < this->mod; i++) {

        j = (j + this->S[i] + key[i % key.length()]) % this->mod;
        this->swap(this->S[i], this->S[j]);
    }

}

void RC4::compute (int min, int max) {

    std::string treatment = this->content.substr(min, max);

    int i = 0;
    int j = 0;

    std::lock_guard<std::mutex> guard(this->lock);

    for(int a = min; a < max; a++){

        i = ( i + 1) % this->mod;
        j = (j + this->S[i]) % this->mod;
        swap(i, j);

        unsigned char k = S[(S[i] + S[j]) % this->mod] ^ this->content[a];

        //this->test[a] = k;
        this->result += k;
    }
}

std::string RC4::PRGA () {

    int content_length = (int) this->content.length();

    if (content_length < 255) {

        compute(0, content_length);
    }
    else {

        std::vector<std::thread> threads;
        int                      sub_content_length = content_length / this->concurrentThreadsSupported;
        int                      start_cursor       = 0;
        int                      end_cursor         = sub_content_length;

        for (int i = 0; i < this->concurrentThreadsSupported; ++i) {

            threads.emplace_back( std::thread( &RC4::compute, this, start_cursor, end_cursor ));

            start_cursor += sub_content_length;
            end_cursor   += sub_content_length;
        }

        std::for_each(threads.begin(), threads.end(), [](std::thread &t) {
            t.join();
        });
    }
    return result;
}

RC4::~RC4() {

}
