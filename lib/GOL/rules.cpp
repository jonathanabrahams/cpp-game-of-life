#include "rules.hpp"
#include <vector>

namespace GOL
{
    /** Dies due to underpopulation
     * 1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
     */
    template <class T>
    bool Rules<T>::dies_underpopulation(WorldMap::iterator it, WorldMap n)
    {
        return it->alive() && live_neighbours(n, Specification<T>::fewer_than_two);
    };

    /** Lives due to next generation
     * 2. Any live cell with two or three live neighbours lives on to the next generation.
     */
    template <class T>
    bool Rules<T>::lives_next_generation(WorldMap::iterator it, WorldMap n)
    {
        return it->alive() && live_neighbours(n, Specification<T>::two_or_three);
    };

    /** Dies due to overpopulation
     * 3. Any live cell with more than three live neighbours dies, as if by overpopulation.
     */
    template <class T>
    bool Rules<T>::dies_overpopulated(WorldMap::iterator it, WorldMap n)
    {
        return it->alive() && live_neighbours(n, Specification<T>::more_than_three);
    };

    /** Lives due to reproduction
     * 4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
     */
    template <class T>
    bool Rules<T>::lives_reproduced(WorldMap::iterator it, WorldMap n)
    {
        return it->dead() && live_neighbours(n, Specification<T>::exactly_three);
    };

    /** Live neighbours
     * Count live neighbours
     */
    template <class T>
    bool Rules<T>::live_neighbours(WorldMap n, SpecificationCallback<T> specification)
    {
        T alive = 0;
        WorldMap::iterator ptr = n.begin();

        while (ptr != n.end())
            if (ptr++->alive())
                alive++;

        return specification(alive);
    };

    template class Rules<int>;
    template class Rules<unsigned int>;
    template class Specification<int>;
    template class Specification<unsigned int>;
}