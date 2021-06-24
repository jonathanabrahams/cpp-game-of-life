#include "life.hpp"
#include "world.hpp"
namespace GOL
{
    World::World(std::istream &is)
    {
        char c;
        SymbolLifeParser<char> parser;
        parser.alive('+').dead('-');

        unsigned int cols = 0;
        while (is.get(c))
        {
            // End-Of-Row and Reset Column
            if (c == '\n')
            {
                cols = 0;
            }
            // Insert Cell
            else
            {
                // First column is new row
                if (cols++ == 0)
                {
                    _rows++;
                }
                // First row set world columns
                if (_rows == 1)
                {
                    _cols = cols;
                }
                _world.push_back(parser.symbol(c).parse());
            }
        }

        if (is.eof())
        {
            // reset failbit as side-effect of get()
            is.clear(std::ios_base::eofbit);
            _begin = _world.begin();
            _end = _world.end();
        }
    };

    std::vector<Cell> &World::world()
    {
        return _world;
    }

    unsigned int World::rows()
    {
        return _rows;
    }
    unsigned int World::cols()
    {
        return _cols;
    }

    std::vector<Cell> World::neighbors(std::vector<Cell>::iterator &it)
    {
        std::cout << "B:" << std::distance(_begin, it) << " E:" << std::distance(it, _end) << std::endl;
        std::cout << "R:" << _rows << " C:" << _cols << std::endl;
        return std::vector<Cell>{};
    }
}