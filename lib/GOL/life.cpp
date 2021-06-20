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

    Cell Life::toCell(unsigned char symbol)
    {
        switch (symbol)
        {
        case Alive:
            return aliveCell();
        case Dead:
            return deadCell();
        default:
            return unknownCell();
        }
    };
}