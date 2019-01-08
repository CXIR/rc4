
#include <iostream>
#include "src/RC4.h"
#include "src/FileIO.h"
#include "stdio.h"
#include <string>
#include <cctype>

int helper(){

    std::cout << "RC4 I/O Helper"                                              << std::endl;
    std::cout << "Please consider the following instructions to make it work!" << std::endl;
    std::cout << "\nThis program expect for 4 parameters :"                    << std::endl;

    std::cout << "> -e (encrypt) or -d (decrypt)"                     << std::endl;
    std::cout << "> number of threads treatment"                      << std::endl;
    std::cout << "> the key (max 255), quote if your key is a phrase" << std::endl;
    std::cout << "> your source file path"                            << std::endl;

    return -1;
}

int main (int argc, char** argv) {

    if (argc < 5) { //we expect four arguments, makes a total of 5 at execution because the first one is the program name and path

        return helper();
    }
    else {

        std::string command    = argv[1];
        std::string threads    = argv[2];
        std::string key        = argv[3];
        std::string fileSource = argv[4];

        char* pEnd;

        if (command != "-d" && command != "-e") {

            std::cout << "We don't recognize you command parameter :/ \n" << std::endl;
            return helper();
        }
        else if (strtol(argv[2], &pEnd, 10) == 0L) {

            std::cout << "Your threads parameter seems not to be an integer ! \n" << std::endl;
            return helper();
        }
        else {

            FileIO fileIO;
            int numberOfThreadsSelected = (int) strtol(argv[2], &pEnd, 10);

            std::cout << "threads" << numberOfThreadsSelected << std::endl;

            if(fileIO.test(fileSource) == -1){

                std::cout << "We failed in opening your file :/ \n" << std::endl;
                return helper();
            }

            std::string fileContent = fileIO.read(fileSource);
            RC4         rc4(key, fileContent, numberOfThreadsSelected);
            rc4.KSA();

            if (command == "-d") {

                std::string fileDestination = fileSource + ".decrypt";
                fileIO.write(fileDestination, rc4.PRGA());
            }
            else if (command == "-e") {

                std::string fileDestination = fileSource + ".rc4";
                fileIO.write(fileDestination, rc4.PRGA());
            }
            else{
                return helper();
            }
        }
    }

    return 0;
}
