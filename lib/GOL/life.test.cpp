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
    Cell alive = SymbolLifeParser<unsigned char>('+', '-').symbol('+').parse();
    EXPECT_TRUE(alive.alive());
    EXPECT_FALSE(alive.dead());
    EXPECT_FALSE(alive.unknown());
}

TEST(Life, SymbolToDeadCell)
{
    Cell dead = SymbolLifeParser<unsigned char>('+', '-').symbol('-').parse();
    EXPECT_TRUE(dead.dead());
    EXPECT_FALSE(dead.alive());
    EXPECT_FALSE(dead.unknown());
}

TEST(Life, SymbolToUnknowCell)
{
    Cell unknown = SymbolLifeParser<unsigned char>('+', '-').symbol('?').parse();
    EXPECT_TRUE(unknown.unknown());
    EXPECT_FALSE(unknown.alive());
    EXPECT_FALSE(unknown.dead());
}

TEST(Life, CustomIntSymbols)
{
    SymbolLifeParser<int8_t> custom(1, 0);

    Cell unknown = custom.symbol(10).parse();
    EXPECT_TRUE(unknown.unknown());
    EXPECT_FALSE(unknown.alive());
    EXPECT_FALSE(unknown.dead());

    Cell alive_int = custom.symbol(1).parse();
    EXPECT_TRUE(alive_int.alive());
    EXPECT_FALSE(alive_int.dead());
    EXPECT_FALSE(alive_int.unknown());

    Cell alive_bool = custom.symbol(true).parse();
    EXPECT_TRUE(alive_bool.alive());
    EXPECT_FALSE(alive_bool.dead());
    EXPECT_FALSE(alive_bool.unknown());

    Cell dead_int = custom.symbol(0).parse();
    EXPECT_TRUE(dead_int.dead());
    EXPECT_FALSE(dead_int.alive());
    EXPECT_FALSE(dead_int.unknown());

    Cell dead_bool = custom.symbol(false).parse();
    EXPECT_TRUE(dead_bool.dead());
    EXPECT_FALSE(dead_bool.alive());
    EXPECT_FALSE(dead_bool.unknown());
}

TEST(Life, ParseLifeSymbol)
{
    ParseLifeSymbol<unsigned char> custom('+', '-', '?');
    Cell alive = Life::aliveCell();
    Cell dead = Life::deadCell();
    Cell unknown = Life::unknownCell();

    EXPECT_EQ(custom.parse(alive), '+');
    EXPECT_EQ(custom.parse(dead), '-');
    EXPECT_EQ(custom.parse(unknown), '?');
}