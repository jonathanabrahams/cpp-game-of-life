#ifndef __GOL_WORLD_HPP__
#define __GOL_WORLD_HPP__
#include "cell.hpp"
#include "life.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
namespace GOL
{
    typedef std::vector<Cell> WorldMap;
    struct Coordinate
    {
        Coordinate(int _x, int _y) : x(_x), y(_y){};
        Coordinate(int _p, Coordinate const &max)
        {
            std::div_t pos = std::div(_p, max.x);
            x = pos.rem;
            y = pos.quot;
        };
        int x;
        int y;
        bool x_in_range(Coordinate const &max) { return (x >= 0 && x < max.x); };
        bool y_in_range(Coordinate const &max) { return (y >= 0 && y < max.y); };
        bool xy_in_range(Coordinate const &max) { return x_in_range(max) && y_in_range(max); };
        Coordinate n_w() { return Coordinate{x - 1, y - 1}; };
        Coordinate n() { return Coordinate{x, y - 1}; };
        Coordinate n_e() { return Coordinate{x + 1, y - 1}; };
        Coordinate w() { return Coordinate{x - 1, y}; };
        Coordinate e() { return Coordinate{x + 1, y}; };
        Coordinate s_w() { return Coordinate{x - 1, y + 1}; };
        Coordinate s() { return Coordinate{x, y + 1}; };
        Coordinate s_e() { return Coordinate{x + 1, y + 1}; };

        unsigned int index(Coordinate const &max) { return x + y * max.x; };
    };
    class World
    {
    public:
        World(WorldMap w, unsigned int c, unsigned int r) : _world(w), _rows(r), _cols(c){};
        World(std::istream &, SymbolLifeParser<unsigned char>&);
        WorldMap::iterator begin() { return _world.begin(); };
        WorldMap::iterator end() { return _world.end(); };
        WorldMap neighbors(WorldMap::iterator);
        unsigned int rows();
        unsigned int cols();
        friend std::ostream &operator<<(std::ostream &, World const &);
        ParseLifeSymbol<unsigned char> *parser();
        void parser(ParseLifeSymbol<unsigned char> &);

    private:
        WorldMap _world;
        ParseLifeSymbol<unsigned char> *_parser;
        unsigned int _rows = 0;
        unsigned int _cols = 0;
    };

}
#endif