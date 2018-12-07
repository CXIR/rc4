#include <gtest/gtest.h>

#include "../src/FileIO.h"
#include "../src/RC4.h"

//using namespace my_namespace;

TEST(FileIOTest, Should_read_file) {
    FileIO fileIO;
    ASSERT_EQ("test", fileIO.read("test.txt"));
}

/*TEST(FileIO, Should_read_file) {
    FileIO fileIO;
    ASSERT_EQ("hello", fileIO.write());
}

TEST(RC4Test, Should_generate_key) {
    RC4 rc4("tes", "test");
    ASSERT_EQ("test", rc4.KSA());
}

TEST(RC4Test, Should_compute) {
    RC4 rc4("tes", "test");
    ASSERT_EQ("test", rc4.compute());
}

TEST(RC4Test, Should_crypt) {
    RC4 rc4("tes", "test");
    ASSERT_EQ("test", rc4.PRGA());
}*/