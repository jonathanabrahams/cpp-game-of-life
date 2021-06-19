#ifndef __CELL_HPP__
#define __CELL_HPP__

namespace GOL
{

    enum CellState
    {
        Alive,
        Dead,
        Unknown
    };

    class Cell
    {
        CellState state;

    public:
        Cell(CellState);
    };

};
#endif