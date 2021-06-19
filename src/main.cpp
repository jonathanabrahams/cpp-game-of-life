#include "config.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << GameOfLife_DESCRIPTION << std::endl
              << "Homepage: " << GameOfLife_HOMEPAGE_URL << std::endl
              << "Version: " << GameOfLife_VERSION << std::endl;

    return 0;
}
