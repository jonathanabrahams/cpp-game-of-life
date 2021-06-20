#ifndef __GOL_CELL_HPP__
#define __GOL_CELL_HPP__
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
    public:
        explicit Cell(CellState);
        bool alive() const;
        bool dead() const;
        bool unknown() const;

    private:
        CellState _state;
    };

};
#endif