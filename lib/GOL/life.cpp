#include "cell.hpp"
#include "life.hpp"
#include <cstdint>
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

    template <class T>
    bool SymbolLifeParser<T>::alive() const
    {
        return _symbol == _alive;
    }

    template <class T>
    bool SymbolLifeParser<T>::dead() const
    {
        return _symbol == _dead;
    }

    template <class T>
    Cell SymbolLifeParser<T>::parse() const
    {
        if (alive())
        {
            return Life::aliveCell();
        }
        else if (dead())
        {
            return Life::deadCell();
        }

        return Life::unknownCell();
    };

    template <class T>
    SymbolLifeParser<T> &SymbolLifeParser<T>::alive(T a)
    {
        _alive = a;
        return *this;
    }

    template <class T>
    SymbolLifeParser<T> &SymbolLifeParser<T>::dead(T d)
    {
        _dead = d;
        return *this;
    }

    template <class T>
    SymbolLifeParser<T> &SymbolLifeParser<T>::symbol(T s)
    {
        _symbol = s;
        return *this;
    }
    template class SymbolLifeParser<unsigned char>;
    template class SymbolLifeParser<char>;
    template class SymbolLifeParser<int8_t>;
}