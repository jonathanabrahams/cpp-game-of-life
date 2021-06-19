#ifndef __WORLD_HPP__
#define __WORLD_HPP__
#include <vector>
#include "cell.hpp"

namespace GOL
{
    class World
    {
    private:
        std::vector<Cell> world_map = {};

    public:
        World();
    };

}
#endif