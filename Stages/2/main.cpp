#include <gtest/gtest.h>
#include <type_traits>

#include "solution.hpp"

template<typename T>
struct can_compile_max
{
    static constexpr bool value = true;
};


template<>
struct can_compile_max<bool>
{
    static constexpr bool value = false;
};

TEST(max, doesnt_accept_bool)
{
    EXPECT_FALSE(can_compile_max<decltype(max<bool>)>::value);
}