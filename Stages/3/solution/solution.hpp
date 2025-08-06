#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include "humans.hpp"

#include <type_traits>

// Primary Template
template<typename Human>
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