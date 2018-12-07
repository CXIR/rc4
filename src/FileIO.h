//
// Created by Ludwig Roger on 2018-12-06.
//

#ifndef RC4_FILEIO_H
#define RC4_FILEIO_H

#include <iostream>
#include <string>
#include <fstream>

#include "stdio.h"
#include "stdlib.h"


class FileIO {

private:
    std::string base_path;

public:
    FileIO();

    std::string read(  std::string path );
    int         write( std::string path, std::string text);
};

#endif //RC4_FILEIO_H
