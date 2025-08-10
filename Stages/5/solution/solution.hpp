#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <type_traits>
#include <utility>
#include "aliens.hpp"

// Primary Template
template<typename, typename = void>
struct is_human_like : public std::false_type
{};

// Secondary Template
template<typename Human>
struct is_human_like<
    Human, 
    typename std::enable_if<
        std::is_same<decltype(std::declval<Human>().age), int>::value
    >::type
> : public std::true_type
{};


// Extending the `is_human_like` to types which have a public method `int age`
template<typename Human>
struct is_human_like<
    Human, 
    typename std::enable_if<
                                 // Notice the () Here vvv !
        std::is_same<decltype(std::declval<Human>().age()), int>::value
    >::type
> : public std::true_type
{};


// Syntax Sugar
// Notice that in order to delegate the default `void` type we have to give it a name.
template<typename Human, typename Void = void>
constexpr bool is_human_like_v = is_human_like<Human, Void>::value;

#endif