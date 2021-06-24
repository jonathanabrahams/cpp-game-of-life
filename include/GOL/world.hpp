#ifndef __GOL_WORLD_HPP__
#define __GOL_WORLD_HPP__
#include "cell.hpp"
#include <vector>
#include <iostream>
namespace GOL
{
    class World
    {
    public:
        World(std::istream &);
        std::vector<Cell> &world();
        std::vector<Cell> neighbors(std::vector<Cell>::iterator &);
        unsigned int rows();
        unsigned int cols();

    private:
        std::vector<Cell> _world;
        std::vector<Cell>::iterator _begin;
        std::vector<Cell>::iterator _end;
        unsigned int _rows = 0;
        unsigned int _cols = 0;
    };

}
#endif