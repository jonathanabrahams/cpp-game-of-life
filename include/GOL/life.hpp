#ifndef __LIFE_HPP__
#define __LIFE_HPP__
namespace GOL
{

    enum LifeSymbol : unsigned char
    {
        Alive = '1',
        Dead = '0'
    };
    class Life
    {
    private:
        LifeSymbol symbol;

    public:
        Life(LifeSymbol);
    };
}
#endif