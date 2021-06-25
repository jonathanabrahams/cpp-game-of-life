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
        do
        {
            is.get(c);
            // End-Of-Stream
            if (is.eof())
            {
                //Set eof and Rest failbit
                is.clear(std::ios_base::eofbit);
                // Set failbit
                if (cols != _cols)
                {
                    is.setstate(std::ios_base::failbit);
                }
            }
            // End-Of-Row and Reset Column
            else if (c == '\n')
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
                // Unknown symbols should fail
                if (_world.back().unknown())
                {
                    is.setstate(std::ios_base::failbit);
                }
            }
        } while (!is.eof() && !is.fail());

        if (is.eof())
        {
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