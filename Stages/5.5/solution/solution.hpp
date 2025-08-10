#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <type_traits>
#include <utility>
#include "aliens.hpp"

template<typename, typename Void = void>
struct is_human_like : public std::false_type
{
    /**
     * +-------------------------------+
     * |Notice the static assert here! |
     * +---vv--------------------------+
     */
    static_assert(std::is_same_v<Void, void>, "'Void' template parameter (the seoncd template parameter) has to be of void type. Alternatively, the user can not provide it and the default argument `void` will be used.");
};

template<typename Human>
struct is_human_like<
    Human, 
    typename std::enable_if<
        std::is_same<decltype(std::declval<Human>().age), int>::value
    >::type
> : public std::true_type
{};


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