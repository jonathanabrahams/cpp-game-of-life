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
        int rows();

    private:
        std::vector<Cell> _world;
        int _rows = 0;
    };

}
#endif