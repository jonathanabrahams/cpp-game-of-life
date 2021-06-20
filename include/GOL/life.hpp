#ifndef __GOL_LIFE_HPP__
#define __GOL_LIFE_HPP__
namespace GOL
{
    class Cell;
    class Life
    {
    public:
        static Cell aliveCell();
        static Cell deadCell();
        static Cell unknownCell();
        static Cell toCell(unsigned char);

    private:
        enum _mapper
        {
            Alive = '+',
            Dead = '-'
        };
    };
}
#endif