#include "cell.hpp"
#include <gtest/gtest.h>

using namespace GOL;

TEST(Cell, IsAlive)
{
    Cell alive(CellState::Alive);
    EXPECT_TRUE(alive.alive());
}

TEST(Cell, IsNotAlive)
{
    Cell dead(CellState::Dead);
    EXPECT_FALSE(dead.alive());
}

TEST(Cell, IsDead)
{
    Cell dead(CellState::Dead);
    EXPECT_TRUE(dead.dead());
}

TEST(Cell, IsUnknown)
{
    Cell unknown(CellState::Unknown);
    EXPECT_TRUE(unknown.unknown());
}