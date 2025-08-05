#ifndef HUMANS_HPP
#define HUMANS_HPP

#include <iostream>
#include <string>

struct Adult
{
    int age;
    void think()
    {
        std::cout << "Adult is thinking..." << std::endl;
    }
};

struct Child
{
    int age;
    void think()
    {
        std::cout << "Child is thinking..." << std::endl;
    }
};

struct Baby
{
    int age;
    void think()
    {
        std::cout << "Baby is thinking..." << std::endl;
    }
};

#endif
