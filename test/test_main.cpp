#include <gtest/gtest.h>

#include "../src/my_code.h"

using namespace my_namespace;

TEST(my_code, string) {
    Hello hello;
    ASSERT_EQ("hello", hello.hello());
}

TEST(my_code, stringFromFile) {
    Hello hello;
    ASSERT_EQ("hello", hello.helloFile());
}
