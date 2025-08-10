#include <gtest/gtest.h>
#include <utility>

#include "aliens.hpp"

#include "solution.hpp"


TEST(is_human_like, int_age_member)
{
    static_assert(!is_human_like<VampireAlien>::value, "VampireAlien is not human like, it doesn't have an age");
    static_assert(is_human_like<Alien>::value, "Alien should be human like, it has an age");
}

TEST(is_human_like, int_age_member_or_method)
{
    static_assert(!is_human_like<ShapeShiftingAlien>::value, "ShapeShiftingAlien is definitly not human like!");
    static_assert(is_human_like<AnotherAlien>::value, "AnotherAlien should be human like, it has a `public int age` method");
}
