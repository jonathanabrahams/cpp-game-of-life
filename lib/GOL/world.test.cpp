#include <gtest/gtest.h>
#include "life.hpp"
#include "world.hpp"
#include <sstream>

using namespace GOL;

TEST(World, EmptyWorldBuilder)
{
    std::istringstream i("");
    SymbolLifeParser<unsigned char> parser;
    parser.alive('+').dead('-');
    World w(i, parser);

    EXPECT_EQ(w.rows(), 0);
    EXPECT_EQ(w.cols(), 0);
}

TEST(World, WorldBuilder)
{
    std::istringstream i("+--+\n++--");
    SymbolLifeParser<unsigned char> parser;
    parser.alive('+').dead('-');
    World w(i, parser);

    EXPECT_TRUE(i.eof());
    EXPECT_FALSE(i.bad());
    EXPECT_FALSE(i.fail());
    EXPECT_FALSE(i.good());

    EXPECT_EQ(w.rows(), 2);
    EXPECT_EQ(w.cols(), 4);

    auto it = w.begin();

    EXPECT_TRUE(it++->alive());
    EXPECT_TRUE(it++->dead());
    EXPECT_TRUE(it++->dead());
    EXPECT_TRUE(it++->alive());

    EXPECT_TRUE(it++->alive());
    EXPECT_TRUE(it++->alive());
    EXPECT_TRUE(it++->dead());
    EXPECT_TRUE(it++->dead());
}

TEST(World, WorldSeed)
{
    WorldMap wm = {
        Life::aliveCell(),
        Life::aliveCell(),
        Life::aliveCell(),

        Life::deadCell(),
        Life::deadCell(),
        Life::deadCell(),
    };
    World w(wm, 3, 2);

    EXPECT_EQ(w.cols(), 3);
    EXPECT_EQ(w.rows(), 2);

    auto it = w.begin();

    EXPECT_TRUE(it++->alive());
    EXPECT_TRUE(it++->alive());
    EXPECT_TRUE(it++->alive());

    EXPECT_TRUE(it++->dead());
    EXPECT_TRUE(it++->dead());
    EXPECT_TRUE(it++->dead());
}

TEST(World, WorldOutputStream)
{
    std::ostringstream o;
    World w({
                Life::aliveCell(),
                Life::aliveCell(),

                Life::deadCell(),
                Life::deadCell(),
            },
            2, 2);
    ParseLifeSymbol<unsigned char> custom('+', '-', '?');
    w.parser(custom);
    o << w;

    EXPECT_EQ("++\n--", o.str());
}