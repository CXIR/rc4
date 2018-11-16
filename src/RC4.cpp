//
// Created by Ludwig Roger on 15/11/2018.
//

#include "RC4.h"

using namespace std;

RC4::RC4(string content, string key){
    this->content = content;
    this->key = key;
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

string RC4::prga() {

    string result = "";
    int i = 0;
    int j = 0;

    for(int a = 0; a < this->content.length(); a++){

        i = ( i + 1) % this->mod;
        j = (j + this->S[i]) % this->mod;
        swap(i, j);

        unsigned char k = S[(S[i] + S[j]) % this->mod] ^ this->content[a];
        result += k;

    }
    return result;
}

string RC4::compute(){
    return "aaa";
}

