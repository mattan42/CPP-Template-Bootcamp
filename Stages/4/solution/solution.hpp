#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <type_traits>
#include "buffer.hpp"

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