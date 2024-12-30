#include <iostream>
#include "x.hpp"

int main(int argc, char *argv[])  {
    if (argc != 2) return -1;
    X str = { X( argv[1] ) };
    str.bfValue((unsigned char)0);
    std::cout << "\n";
    return 0;
}