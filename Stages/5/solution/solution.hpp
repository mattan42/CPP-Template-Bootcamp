#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <type_traits>
#include <utility>
#include "aliens.hpp"

template<typename, typename = void>
struct is_human_like : public std::false_type
{};

template<typename Human>
struct is_human_like<
    Human, 
    typename std::enable_if<
        std::is_same<decltype(std::declval<Human>().age), int>::value
    >::type
> : public std::true_type
{};


// Extending  the `is_human_like` to types which have a public method `int age`
template<typename Human>
struct is_human_like<
    Human, 
    typename std::enable_if<
                                 // Notice the () Here vvv !
        std::is_same<decltype(std::declval<Human>().age()), int>::value
    >::type
> : public std::true_type
{};

#endif