//
// Created by Micka on 21/11/2018.
//

#ifndef RC4_FILEMANAGER_H
#define RC4_FILEMANAGER_H

#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include <string>

using namespace std;

class FileManager {
private:
    string path;
public:
    FileManager(string path);
    string read();
    void write(string text);
};

#endif //RC4_FILEMANAGER_H
