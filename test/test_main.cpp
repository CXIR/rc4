#include <gtest/gtest.h>

#include "../src/RC4.h"
#include "../src/RC4.cpp"
#include "../src/FileIO.h"
#include "../src/FileIO.cpp"

std::string content = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse orci magna, eleifend eu porta vel, rhoncus sit amet arcu.";
int threads         = 4;
std::string key     = "banana";

FileIO fileIO;


TEST(fileIO, fileExists) {

    ASSERT_EQ(1, fileIO.test("../test/file_test.txt"));
}

TEST(fileIO, read) {

    std::string fileContent = fileIO.read("../test/file_test.txt");

    ASSERT_EQ(content, fileContent);
}

TEST(fileIO, write) {

    std::string path = "../test/file_test_written.txt";

    fileIO.write(path, content);

    ASSERT_EQ(1, fileIO.test(path));
    ASSERT_EQ(content + "\n", fileIO.read(path));
}

TEST(rc4, cypher) {

    RC4 encypher(key, content, threads);
    encypher.KSA();

    RC4 decypher(key, encypher.PRGA(), threads);
    decypher.KSA();

    ASSERT_EQ(content, decypher.PRGA());
}

TEST(rc4, cypherFromFile) {

    std::string fileContent = fileIO.read("../test/file_test.txt");

    RC4 encypher(key, fileContent, threads);
    encypher.KSA();

    RC4 decypher(key, encypher.PRGA(), threads);
    decypher.KSA();

    ASSERT_EQ(fileContent, decypher.PRGA());
}