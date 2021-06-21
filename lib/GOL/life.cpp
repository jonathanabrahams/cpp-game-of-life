#include "cell.hpp"
#include "life.hpp"
namespace GOL
{
    Cell Life::aliveCell()
    {
        return Cell(CellState::Alive);
    };

    Cell Life::deadCell()
    {
        return Cell(CellState::Dead);
    };

    Cell Life::unknownCell()
    {
        return Cell(CellState::Unknown);
    };

    Cell Life::toCell(SymbolLifeParser const &life)
    {
        return life.parse();
    };

    Cell SymbolLifeParser::parse() const
    {
        _state sym = _mapper.find(_symbol) == _mapper.end() ? Unknown : _mapper.at(_symbol);
        switch (sym)
        {
        case Alive:
            return Life::aliveCell();
        case Dead:
            return Life::deadCell();
        default:
            return Life::unknownCell();
        }
    };
}