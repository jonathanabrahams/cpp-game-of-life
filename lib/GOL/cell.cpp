#include "cell.hpp"
namespace GOL
{
    Cell::Cell(CellState cs) : _state(cs){};
    bool Cell::alive() const { return _state == Alive; };
    bool Cell::dead() const { return _state == Dead; };
    bool Cell::unknown() const { return _state == Unknown; };
};