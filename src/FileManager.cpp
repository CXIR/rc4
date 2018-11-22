//
// Created by Micka on 21/11/2018.
//
#include <fstream>
#include <codecvt>
#include "FileManager.h"

FileManager::FileManager(string path) {
    this->path = path;
}

string FileManager::read() {
    ifstream readFile;
    string text;
    string line;
    readFile.open(path, ios::binary);
    if(readFile.is_open()) {
        while(!readFile.eof()) {
            getline(readFile, line);
            text.append(line);
        }
    }
    else {
        cout << "File not open" << endl;
    }

    if(readFile.fail()) {
        cout << "File open error" << endl;
    }
    readFile.close();
    return text;
}

void FileManager::write(string text) {
    ofstream writeFile;
    writeFile.open(path, ios::binary);
    if(writeFile.is_open()) {
        writeFile << text;
    }
    else {
        cout << "File not open" << endl;
    }

    if(writeFile.fail()) {
        cout << "File open error" << endl;
    }
    writeFile.close();
}