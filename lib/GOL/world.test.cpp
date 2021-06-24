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
    EXPECT_EQ(w.cols(), 0);
}

TEST(World, WorldBuilder)
{
    std::istringstream i("+--+\n++--");
    World w(i);

    EXPECT_TRUE(i.eof());
    EXPECT_FALSE(i.bad());
    EXPECT_FALSE(i.fail());
    EXPECT_FALSE(i.good());

    EXPECT_EQ(w.rows(), 2);
    EXPECT_EQ(w.cols(), 4);

    std::vector<Cell>::iterator it = w.world().begin();

    EXPECT_TRUE(it++->alive());
    EXPECT_TRUE(it++->dead());
    EXPECT_TRUE(it++->dead());
    EXPECT_TRUE(it++->alive());

    EXPECT_TRUE(it++->alive());
    EXPECT_TRUE(it++->alive());
    EXPECT_TRUE(it++->dead());
    EXPECT_TRUE(it++->dead());

    EXPECT_TRUE(it == w.world().end());
}