#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include "humans.hpp"
#include "buffer.hpp"

#include <type_traits>

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

// Primary Template
// The deafult "false" case
template<typename>
struct is_buffer : public std::false_type
{
};

// Partial Specialization
// The "true" case in which a type is an instantiation of Buffer.
template<typename T, int MemberCount>
struct is_buffer<Buffer<T, MemberCount>> : public std::true_type
{
};

#endif