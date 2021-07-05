#include "config.h"
#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>

#include "world.hpp"
#include "rules.hpp"

namespace GOL
{
    class WorldParser
    {
    public:
        WorldParser(WorldMap &worldmap, SymbolLifeParser<unsigned char> &parser)
        {
            _worldmap = &worldmap;
            _parser = &parser;
        };
        friend std::istream &operator>>(std::istream &is, GOL::WorldParser &wp)
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
                    if (cols != wp._cols)
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
                        wp._rows++;
                    }
                    // First row set world columns
                    if (wp._rows == 1)
                    {
                        wp._cols = cols;
                    }
                    wp._worldmap->push_back(wp._parser->symbol(c).parse());
                    // Unknown symbols should fail
                    if (wp._worldmap->back().unknown())
                    {
                        is.setstate(std::ios_base::failbit);
                    }
                }
            } while (!is.eof() && !is.fail());
            return is;
        };

        unsigned int _cols = 0;
        unsigned int _rows = 0;

    private:
        SymbolLifeParser<unsigned char> *_parser;
        WorldMap *_worldmap;
    };

}

int main(int argc, char const *argv[])
{
    std::clog << GameOfLife_DESCRIPTION << std::endl
              << "Homepage: " << GameOfLife_HOMEPAGE_URL << std::endl
              << "Version: " << GameOfLife_VERSION << std::endl;

    GOL::SymbolLifeParser<unsigned char> slp('+', '-');
    GOL::WorldMap wm;
    GOL::WorldParser wp(wm, slp);
    std::cin >> wp;
    GOL::World w(wm, wp._cols, wp._rows);

    GOL::WorldMap wm2;
    GOL::Rules<int> rules;
    GOL::WorldMap::iterator it = w.begin();
    GOL::WorldMap::iterator end = w.end();

    GOL::WorldMap neighbors;
    do
    {
        GOL::Cell cell = *it;
        w.neighbors(it, neighbors);
        if (rules.lives_reproduced(cell, neighbors) || rules.lives_next_generation(cell, neighbors))
        {
            wm2.push_back(GOL::Life::aliveCell());
        }
        else if (rules.dies_overpopulated(cell, neighbors) || rules.dies_underpopulation(cell, neighbors) || cell.dead())
        {
            wm2.push_back(GOL::Life::deadCell());
        }
        neighbors.clear();
    } while (++it != end);

    GOL::ParseLifeSymbol<unsigned char> custom('+', '-', '?');
    GOL::World w2(wm2, wp._cols, wp._rows);
    w2.parser(custom);
    std::cout << w2;

    return 0;
}
