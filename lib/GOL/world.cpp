#include "life.hpp"
#include "world.hpp"
#include <cstdlib>
namespace GOL
{
    World::World(std::istream &is, SymbolLifeParser<unsigned char> &parser)
    {
        char c;
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
    };

    unsigned int World::rows()
    {
        return _rows;
    };

    unsigned int World::cols()
    {
        return _cols;
    };

    void World::neighbors(WorldMap::iterator it, WorldMap &_result)
    {
        Coordinate max(_cols, _rows);
        Coordinate current(std::distance(begin(), it), max);
        Coordinate n[8] = {
            current.n_w(), // 0: Top-Left
            current.n(),   // 1: Top
            current.n_e(), // 2: Top-Right
            current.w(),   // 3: Left
            current.e(),   // 4: Right
            current.s_w(), // 5: Bottom-Left
            current.s(),   // 6: Bottom
            current.s_e()  // 7: Bottom-Right
        };
        for (int i = 0; i < 8; i++)
        {
            if (n[i].xy_in_range(max))
            {
                _result.push_back(_world.at(n[i].index(max)));
            }
        }
    };

    std::ostream &operator<<(std::ostream &os, World const &w)
    {
        auto current = w._world.begin();
        auto end = w._world.end();
        auto row = 0;
        auto col = 0;
        auto cols = w._cols;
        auto rows = w._rows;
        while (current != end)
        {
            if (cols == col)
            {
                col = 0;
                row++;
                os << std::endl;
            };
            os << w._parser->parse(*current);
            col++;
            current++;
        }
        return os;
    };

    ParseLifeSymbol<unsigned char> *World::parser()
    {
        return _parser;
    };

    void World::parser(ParseLifeSymbol<unsigned char> &p)
    {
        _parser = &p;
    }
}