//
// Created by Ludwig Roger on 15/11/2018.
//

#ifndef RC4_RC4_H
#define RC4_RC4_H

#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <mutex>



class RC4 {

private:
    int           mod = 256;
    std::string   key;
    std::string   content;
    unsigned char S[256];
    std::mutex    lock;
    std::string   result;
    unsigned      concurrentThreadsSupported;

    void compute(int min, int max);

public:
    void        KSA();
    std::string PRGA();
    void        swap( unsigned int a, unsigned int b );


    RC4( std::string key, std::string content );
};

#endif //RC4_RC4_H
