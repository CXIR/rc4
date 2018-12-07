#ifndef MY_CODE_H
#define MY_CODE_H

#include <string>
#include <sstream>
#include <fstream>

namespace my_namespace {

class Hello {
public:
    Hello() = default;

    std::string hello() {
        return "hello";
    }

    std::string helloFile() {
        std::string line;
        std::stringstream ss;

        std::ifstream myfile ("../data/hello.txt");
        if(myfile.is_open()) {
            while (getline (myfile, line)) {
                ss << line;
            }
            myfile.close();
        } else {
            throw std::runtime_error("Could not open file");
        }

        return ss.str();
    }
};

}   // namespace my_namespace

#endif //MY_CODE_H
