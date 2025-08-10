#ifndef ALIENS_HPP
#define ALIENS_HPP

#include <type_traits>
#include <utility>

/**
 * This is a very simple alien, just a struct with an int member.
 */
struct SimpleAlien
{
    int age;
};

/**
 * This is a normal alien.
 */
class Alien
{
public:
    // We don't want to have an alient without an initial age.
    Alien() = delete;

    Alien(int age) : age(age) {};

    int age;
};

/**
 * This is a vampire alien! It doesn't have an age at all!
 */
struct VampireAlien
{};

/**
 * This alien has an age in `char`.
 * This is weird, so he is WeirdAlien.
 */
struct WeirdAlien
{
    char age;
};

/**
 * This alien is immortal, so we'd rather the user
 * not being able to change it's age.
 */
class ImmortalAlien
{
public:
    // We don't want to have an alient without an initial age.
    ImmortalAlien() = delete;

    ImmortalAlien(int age) : inner_age(age)
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