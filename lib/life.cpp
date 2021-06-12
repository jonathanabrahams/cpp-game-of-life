#include <iostream>
#include "life.hpp"

std::string Life::to_string() const
{
    return "Life!";
}

std::ostream& operator<<(std::ostream& os, Life const& l)
{
    os << l.to_string();
    return os;
}