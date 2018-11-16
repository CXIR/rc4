//
// Created by Ludwig Roger on 15/11/2018.
//

#ifndef RC4_RC4_H
#define RC4_RC4_H

#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include <string>

using namespace std;

class RC4 {

private:
    int mod = 256;
    string key;
    string content;
    unsigned char S[256];

public:
    string getKey();
    void setKey(string key);
    void ksa();
    string prga();
    void swap(unsigned int a, unsigned int b);
    string compute();

    RC4(string content, string key);
};

#endif //RC4_RC4_H
