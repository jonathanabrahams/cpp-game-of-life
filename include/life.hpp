#ifndef __LIFE_HPP__
#define __LIFE_HPP__

class Life
{
public:
    std::string to_string() const;
    friend std::ostream& operator<<(std::ostream&, Life const&);
};


#endif