
#include <iostream>
#include "src/RC4.h"
#include "src/FileIO.h"
#include "stdio.h"
#include <string>

int main() {

    std::string arg  = "";
    std::string key  = "";

    std::cout << "Paki Kryption" << std::endl;

    //std::cout << "Enter an argument -e (encrypt) or -d (decrypt) : " << std::endl;
    //std::cin >> arg;

    std::cout << "Enter the key, please :" << std::endl;
    std::cin >> key;

    std::cout << "Thanks !" << std::endl;

    FileIO fileIO;

    std::string fileContent = fileIO.read("/decrypt.txt");

    RC4 rc4(key, fileContent);
    rc4.KSA();
/*
    if( arg == "-e" ) {
        fileIO.write("/file.rc4", rc4.PRGA());
    }
    else if ( arg == "-d" ) {
        fileIO.write("/file.rc4.decrypt", rc4.PRGA());
    }
*/
    fileIO.write("/decrypt.txt", rc4.PRGA());
    return 0;
}