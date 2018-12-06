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
    mutex lock;

    void compute(int min, int max, string result);
    void test(int a);

public:
    string getKey();
    void setKey(string key);
    void ksa();
    string prga();
    void swap(unsigned int a, unsigned int b);
    //string compute();


    RC4(string key);
    void setContent(string content);
};

#endif //RC4_RC4_H
