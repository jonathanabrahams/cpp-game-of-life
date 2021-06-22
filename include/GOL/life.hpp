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
    };

    template <class T>
    class SymbolLifeParser
    {
    public:
        bool alive() const;
        bool dead() const;
        Cell parse() const;
        SymbolLifeParser<T> &alive(T);
        SymbolLifeParser<T> &dead(T);
        SymbolLifeParser<T> &symbol(T);

    private:
        T _symbol;
        T _alive;
        T _dead;
    };
}
#endif