#include <gtest/gtest.h>

#include "humans.hpp"
#include "buffer.hpp"

#include "solution.hpp"

struct Alien {};

TEST(is_human, humans)
{
    EXPECT_TRUE(is_human<Child>::value);
    static_assert(is_human<Child>::value, "A Child should be a human");
    
    EXPECT_TRUE(is_human<Adult>::value);
    static_assert(is_human<Adult>::value, "A Adult should be a human");
    
    EXPECT_TRUE(is_human<Baby>::value);
    static_assert(is_human<Baby>::value, "A Baby should be a human");    
}

TEST(is_human, aliens)
{
    EXPECT_FALSE(is_human<Alien>::value);
    static_assert(!is_human<Alien>::value, "An Alien should not be a human");
}

TEST(is_human_v, humans)
{
    EXPECT_TRUE(is_human_v<Child>);
    static_assert(is_human_v<Child>, "A Child should be a human");
    
    EXPECT_TRUE(is_human_v<Adult>);
    static_assert(is_human_v<Adult>, "A Adult should be a human");
    
    EXPECT_TRUE(is_human_v<Baby>);
    static_assert(is_human_v<Baby>, "A Baby should be a human");    
}

TEST(is_human_v, aliens)
{
    EXPECT_FALSE(is_human_v<Alien>);
    static_assert(!is_human_v<Alien>, "An Alien should not be a human");
}

TEST(is_buffer, buffers)
{
    EXPECT_TRUE(is_buffer<Buffer<int, 1>>::value);
    static_assert(is_buffer<Buffer<int, 1>>::value, "A type Buffer<int, 1> should be considered a buffer");
}

TEST(is_buffer, not_buffers)
{
    EXPECT_TRUE(is_buffer<Alient>::value);
    static_assert(is_buffer<Alien>::value, "A type Alient should not be considered a buffer");
}
