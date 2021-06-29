#include <gtest/gtest.h>
#include "rules.hpp"
#include "life.hpp"
#include "world.hpp"
using namespace GOL;

TEST(Rules, SpecificationFewerThanTwo)
{
    EXPECT_TRUE(Specification<int>::fewer_than_two(-1));
    EXPECT_TRUE(Specification<int>::fewer_than_two(0));
    EXPECT_TRUE(Specification<int>::fewer_than_two(1));
    EXPECT_FALSE(Specification<int>::fewer_than_two(2));
}

TEST(Rules, SpecificationExactlyThree)
{
    EXPECT_FALSE(Specification<int>::exactly_three(-3));
    EXPECT_FALSE(Specification<int>::exactly_three(0));
    EXPECT_TRUE(Specification<int>::exactly_three(3));
}

TEST(Rules, SpecificationMoreThanThree)
{
    EXPECT_FALSE(Specification<int>::more_than_three(2));
    EXPECT_FALSE(Specification<int>::more_than_three(3));
    EXPECT_TRUE(Specification<int>::more_than_three(4));
    EXPECT_TRUE(Specification<int>::more_than_three(5));
}

TEST(Rules, SpecificationTwoOrThree)
{
    EXPECT_FALSE(Specification<int>::two_or_three(1));
    EXPECT_TRUE(Specification<int>::two_or_three(2));
    EXPECT_TRUE(Specification<int>::two_or_three(3));
    EXPECT_FALSE(Specification<int>::two_or_three(4));
}

TEST(Rules, NoLiveNeighbours)
{
    WorldMap n = {};
    EXPECT_TRUE(Rules<int>::live_neighbours(n, Specification<int>::fewer_than_two));
    EXPECT_FALSE(Rules<int>::live_neighbours(n, Specification<int>::exactly_three));
}

TEST(Rules, ALiveNeighbour)
{
    WorldMap n = {Life::aliveCell()};
    EXPECT_TRUE(Rules<int>::live_neighbours(n, Specification<int>::fewer_than_two));
    EXPECT_FALSE(Rules<int>::live_neighbours(n, Specification<int>::exactly_three));
}

TEST(Rules, ALiveAndDeadNeighbours)
{
    WorldMap n = {Life::deadCell(), Life::aliveCell(), Life::deadCell(), Life::deadCell(), Life::deadCell(), Life::deadCell()};
    EXPECT_TRUE(Rules<int>::live_neighbours(n, Specification<int>::fewer_than_two));
    EXPECT_FALSE(Rules<int>::live_neighbours(n, Specification<int>::exactly_three));
}

TEST(Rules, TwoLiveAndDeadNeighbours)
{
    WorldMap n = {Life::aliveCell(), Life::deadCell(), Life::aliveCell(), Life::deadCell()};
    EXPECT_TRUE(Rules<int>::live_neighbours(n, Specification<int>::two_or_three));
    EXPECT_FALSE(Rules<int>::live_neighbours(n, Specification<int>::fewer_than_two));
    EXPECT_FALSE(Rules<int>::live_neighbours(n, Specification<int>::exactly_three));
    EXPECT_FALSE(Rules<int>::live_neighbours(n, Specification<int>::more_than_three));
}

TEST(Rules, ThreeLiveAndDeadNeighbours)
{
    WorldMap n = {Life::aliveCell(), Life::deadCell(), Life::aliveCell(), Life::aliveCell(), Life::deadCell()};
    EXPECT_TRUE(Rules<int>::live_neighbours(n, Specification<int>::two_or_three));
    EXPECT_TRUE(Rules<int>::live_neighbours(n, Specification<int>::exactly_three));
    EXPECT_FALSE(Rules<int>::live_neighbours(n, Specification<int>::fewer_than_two));
    EXPECT_FALSE(Rules<int>::live_neighbours(n, Specification<int>::more_than_three));
}

TEST(Rules, FourLiveAndDeadNeighbours)
{
    WorldMap n = {Life::aliveCell(), Life::aliveCell(), Life::deadCell(), Life::aliveCell(), Life::aliveCell(), Life::deadCell()};
    EXPECT_FALSE(Rules<int>::live_neighbours(n, Specification<int>::two_or_three));
    EXPECT_FALSE(Rules<int>::live_neighbours(n, Specification<int>::exactly_three));
    EXPECT_FALSE(Rules<int>::live_neighbours(n, Specification<int>::fewer_than_two));
    EXPECT_TRUE(Rules<int>::live_neighbours(n, Specification<int>::more_than_three));
}