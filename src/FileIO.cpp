//
// Created by Ludwig Roger on 2018-12-06.
//

#include "FileIO.h"

FileIO::FileIO() {

    std::string file_path = __FILE__;
    this->base_path       = file_path.substr(0, file_path.rfind("/"));
}

std::string FileIO::read(std::string path) {

    std::string formatted_path = this->base_path + path;
    std::string content = "";
    std::string filecontent = "";
    std::ifstream inputFileStream;

    inputFileStream.open(formatted_path, std::ios::in|  std::ios::binary);

    if( inputFileStream.is_open() ) {

        /* std::string file_content( (std::istreambuf_iterator<char>(inputFileStream) ),
                                   (std::istreambuf_iterator<char>()    ) );
*/
        while(!inputFileStream.eof()) {
            getline(inputFileStream, filecontent);
            content += filecontent;

        }

         //content = file_content;
    }

    inputFileStream.close();
    return content;
}

int FileIO::write(std::string path, std::string text) {

    std::string formatted_path = this->base_path + path;
    int executed = -1;

    std::ofstream outputFileStream;
    outputFileStream.open(formatted_path, std::ios::out | std::ios::binary);

    if( outputFileStream.is_open() ) {

        outputFileStream << text << std::endl;
        executed  = 0;
    }

    outputFileStream.close();
    return executed;
}