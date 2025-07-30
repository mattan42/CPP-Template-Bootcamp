#include <gtest/gtest.h>

#include <iostream>
#include "solution.hpp"

struct Dog
{
    int age;
    void think()
    {
        std::cout << "Dog is thinking..." << std::endl;
    };
}