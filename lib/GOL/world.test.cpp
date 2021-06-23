#include <gtest/gtest.h>
#include "life.hpp"
#include "world.hpp"
#include <sstream>

using namespace GOL;

TEST(World, EmptyWorldBuilder)
{
    std::istringstream i("");
    World w(i);

    EXPECT_EQ(w.rows(), 0);
}

TEST(World, WorldBuilder)
{
    std::istringstream i("+-?-+\n++--");
    World w(i);

    std::vector<Cell>::iterator it = w.world().begin();
    EXPECT_TRUE(it++->alive());
    EXPECT_TRUE(it++->dead());
    EXPECT_TRUE(it++->unknown());
    EXPECT_TRUE(it++->dead());
    EXPECT_TRUE(it++->alive());

    EXPECT_TRUE(it++->alive());
    EXPECT_TRUE(it++->alive());
    EXPECT_TRUE(it++->dead());
    EXPECT_TRUE(it++->dead());

    EXPECT_TRUE(it == w.world().end());
    EXPECT_EQ(w.rows(), 2);
}