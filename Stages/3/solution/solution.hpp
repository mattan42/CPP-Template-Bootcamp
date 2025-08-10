#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <type_traits>
#include "humans.hpp"

// Primary Template
template<typename>
struct is_human : public std::false_type
{
};

// Specialization for `Adult`
template<>
struct is_human<Adult> : public std::true_type
{
};

// Specialization for `Child`
template<>
struct is_human<Child> : public std::true_type
{
};

// Specialization for `Baby`
template<>
struct is_human<Baby> : public std::true_type
{
};

template<typename Human>
constexpr bool is_human_v = is_human<Human>::value;

#endif