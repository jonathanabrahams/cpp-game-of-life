#ifndef __GOL_LIFE_HPP__
#define __GOL_LIFE_HPP__
#include <map>

namespace GOL
{
    class Cell;
    class SymbolLifeParser;
    class Life
    {
    public:
        static Cell aliveCell();
        static Cell deadCell();
        static Cell unknownCell();
        static Cell toCell(SymbolLifeParser const &);
    };

    class SymbolLifeParser
    {
    public:
        SymbolLifeParser(unsigned char s, unsigned char a = '+', unsigned char d = '-')
        {
            _symbol = s;
            _mapper[a] = Alive;
            _mapper[d] = Dead;
        };

        Cell parse() const;

    private:
        unsigned char _symbol;
        enum _state
        {
            Alive,
            Dead,
            Unknown
        };
        std::map<unsigned char, _state> _mapper;
    };

}
#endif