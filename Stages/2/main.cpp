#include <gtest/gtest.h>
#include <type_traits>
#include <functional>

#include "solution.hpp"

TEST(max, accept_integral_types)
{
    EXPECT_EQ(max<int>(1, 2), 2);
    EXPECT_EQ(max<char>('a', 'b'), 'b');
    EXPECT_EQ(max<const int>(1, 2), 2);
    EXPECT_EQ(max<long>(1, 2), 2);
    EXPECT_EQ(max<long long>(1, 2), 2);

    static_assert(!std::is_invocable_v<decltype(max<bool>)>, "Can't instantiate max with T=bool.");
    EXPECT_FALSE(std::is_invocable_v<decltype(max<bool>)>);

    static_assert(!std::is_invocable_v<decltype(max<float>)>, "Can't instantiate max with T=float.");
    EXPECT_FALSE(std::is_invocable_v<decltype(max<float>)>);
}

TEST(max, doesnt_accept_bool_type)
{
    static_assert(!std::is_invocable_v<decltype(max<bool>)>, "Can't instantiate max with T=bool.");
    EXPECT_FALSE(std::is_invocable_v<decltype(max<bool>)>);
}

TEST(max, doesnt_accept_non_integral_types)
{
    static_assert(!std::is_invocable_v<decltype(max<float>)>, "Can't instantiate max with T=float.");
    EXPECT_FALSE(std::is_invocable_v<decltype(max<float>)>);

    struct Person {};
    
    static_assert(!std::is_invocable_v<decltype(max<Person>)>, "Can't instantiate max with T=Person.");
    EXPECT_FALSE(std::is_invocable_v<decltype(max<Person>)>);
}
