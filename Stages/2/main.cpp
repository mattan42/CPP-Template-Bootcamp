#include <gtest/gtest.h>
#include <type_traits>

#include "solution.hpp"

TEST(max, accept_integral_types)
{
    EXPECT_EQ(max<int>(1, 2), 2);
    EXPECT_EQ(max<char>('a', 'b'), 'b');
    EXPECT_EQ(max<const int>(1, 2), 2);
    EXPECT_EQ(max<long>(1, 2), 2);
    EXPECT_EQ(max<long long>(1, 2), 2);
}

// TODO: Add a helper template to check that the max function tempalte doesn't compile on certain scenarios.
