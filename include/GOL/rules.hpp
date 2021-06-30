#ifndef __GOL_RULES_HPP__
#define __GOL_RULES_HPP__
#include "world.hpp"
namespace GOL
{
    template<class T>
    using SpecificationCallback = bool (&)(T);
    template <class T>
    class Rules
    {
    public:
        static bool dies_underpopulation(WorldMap::iterator, WorldMap);
        static bool lives_next_generation(WorldMap::iterator, WorldMap);
        static bool dies_overpopulated(WorldMap::iterator, WorldMap);
        static bool lives_reproduced(WorldMap::iterator, WorldMap);
        static bool live_neighbours(WorldMap, SpecificationCallback<T>);
    };

    template <class T>
    class Specification
    {
    public:
        static bool fewer_than_two(T tst) { return tst < 2; };
        static bool exactly_three(T tst) { return tst == 3; };
        static bool more_than_three(T tst) { return tst > 3; };
        static bool two_or_three(T tst) { return tst == 2 || tst == 3; };
    };
}

#endif