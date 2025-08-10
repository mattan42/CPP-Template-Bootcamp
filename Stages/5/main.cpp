#include <gtest/gtest.h>
#include <utility>

#include "aliens.hpp"

#include "solution.hpp"

TEST(is_human_like, simple_alien)
{
    static_assert(is_human_like_v<SimpleAlien>, "SimpleAlien has an age, it's human like");
    ASSERT_TRUE(is_human_like_v<SimpleAlien>);
}

TEST(is_human_like, alien)
{
    static_assert(is_human_like_v<Alien>, "Alien should be human like, it has an age");
    ASSERT_TRUE(is_human_like_v<Alien>);
}

TEST(is_human_like, vampire_alien)
{
    static_assert(!is_human_like_v<VampireAlien>, "VampireAlien is not human like, it doesn't have an age");
    ASSERT_FALSE(is_human_like_v<VampireAlien>);
}

TEST(is_human_like, weird_alien)
{
    static_assert(!is_human_like_v<WeirdAlien>, "WeirdAlien has a char age, which is not human like");
    ASSERT_FALSE(is_human_like_v<WeirdAlien>);
}

TEST(is_human_like, immortal_alien)
{
    static_assert(is_human_like_v<ImmortalAlien>, "AnotherAlien should be human like, it has a `public int age` method");
    ASSERT_TRUE(is_human_like_v<ImmortalAlien>);
}    

TEST(is_human_like, shape_shifting_alien)
{
    static_assert(!is_human_like_v<ShapeShiftingAlien>, "ShapeShiftingAlien is definitly not human like!");
    ASSERT_FALSE(is_human_like_v<ShapeShiftingAlien>);
}
