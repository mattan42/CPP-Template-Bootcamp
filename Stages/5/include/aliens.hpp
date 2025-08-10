#ifndef ALIENS_HPP
#define ALIENS_HPP

#include <type_traits>
#include <utility>

struct SimpleAlien
{
    int age;
};

class Alien
{
public:
    // We don't want to have an alient without an initial age.
    Alien() = delete;

    Alien(int age) : age(age) {};

    int age;
};

struct VampireAlien
{};

struct WeirdAlien
{
    // Age in `char`?!?! That's weird.
    char age;
};

class AnotherAlien
{
public:
    // We don't want to have an alient without an initial age.
    AnotherAlien() = delete;

    AnotherAlien(int age) : inner_age(age)
    {}

    int age()
    {
        return this->inner_age;
    }

private:
    int inner_age;
};

class ShapeShiftingAlien
{
private:
    /**
     * Since it's shape shifting it gets the age of what it
     * shape-shifted... And also it's evil so it keeps that
     * information private. Definitly not human like!!!
     */
    int age()
    {
        return this->inner_age;
    }

    int inner_age;
};

#endif