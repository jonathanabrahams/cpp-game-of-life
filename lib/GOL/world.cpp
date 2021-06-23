#include "life.hpp"
#include "world.hpp"
namespace GOL
{
    World::World(std::istream &is)
    {
        char c;
        SymbolLifeParser<char> parser;
        parser.alive('+').dead('-');

        while (is.get(c))
        {
            if (c == '\n')
            {
                _rows++;
            }
            else
            {
                _world.push_back(parser.symbol(c).parse());
            }
        }

        if (is.eof())
        {
            if (_world.size() > 0)
            {
                _rows++;
            }
        }
    };

    std::vector<Cell> &World::world()
    {
        return _world;
    }

    int World::rows()
    {
        return _rows;
    }
}