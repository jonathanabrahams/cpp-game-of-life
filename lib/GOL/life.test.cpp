#include <gtest/gtest.h>
#include "cell.hpp"
#include "life.hpp"
#include <vector>

using namespace GOL;

TEST(Life, AliveCell)
{
    Cell alive = Life::aliveCell();
    EXPECT_TRUE(alive.alive());
}

TEST(Life, DeadCell)
{
    Cell dead = Life::deadCell();
    EXPECT_FALSE(dead.alive());
}

TEST(Life, AliveAndDeadCells)
{
    std::vector<Cell> collection = {
        Life::aliveCell(), Life::deadCell()};
    EXPECT_TRUE(collection.front().alive());
    EXPECT_FALSE(collection.back().alive());
}

TEST(Life, PushPopLife)
{
    std::vector<Cell> collection;

    collection.push_back(Life::aliveCell());
    collection.push_back(Life::deadCell());
    EXPECT_TRUE(collection.at(0).alive());
    EXPECT_FALSE(collection.at(1).alive());
    EXPECT_EQ(collection.size(), 2);

    collection.pop_back();

    EXPECT_EQ(collection.size(), 1);
    EXPECT_TRUE(collection.at(0).alive());
}

TEST(Life, SymbolToAliveCell)
{
    Cell alive = Life::toCell('+');
    EXPECT_TRUE(alive.alive());
}

TEST(Life, SymbolToDeadCell)
{
    Cell dead = Life::toCell('-');
    EXPECT_FALSE(dead.alive());
}

TEST(Life, SymbolToUnknowCell)
{
    Cell unknown = Life::toCell('?');
    EXPECT_TRUE(unknown.unknown());
}