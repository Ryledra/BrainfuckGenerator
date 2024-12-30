#include <iostream>
#include "x.hpp"
#include "primeFactors.hpp"

X::X(char* input)   {
    if (!*input) return;
    value = (unsigned char)(* input);
    next = new X(++input);
};

void X::printValue()    {
    if (!value) return;
    std::cout << value;
    (*next).printValue();
};

void X::bfValue(unsigned char mem)  {
    getToValue(&mem, value);
    if (!next->value) return;
    (*next).bfValue(mem);
};

/*
    6: >++[-<+++>]<.
    7: >++[-<+++>]<+.
    ...
    12 >+++[-<++++>]<.
    13 >+++[-<++++>]<+.
*/
void makeLoop(unsigned char *mem, unsigned char value)   {
    PrimeFactors primes = getPrimeFactors(abs((*mem) - value));
    if(!primes.factors[0] && !primes.factors[1]) {
        int itt = { (*mem < value) ? 1 : -1 };
        for(int i = 0; i < primes.remainder; i++) {
            *mem += itt;
            std::cout << ((itt == 1) ? '+' : '-');
        }
        return;
    }
    int itt = { (*mem < value) ? 1 : -1 };
    std::cout << ">";
    for(int i = 0; i < primes.factors[0]; i++)  {
        std::cout << '+';
    } std::cout << "[-<";
    for(int i = 0; i < primes.factors[1]; i++)  {
        std::cout << ((itt == 1) ? '+' : '-');
    } std::cout << ">]<";
    for(int i = 0; i < primes.remainder; i++)  {
        std::cout << ((itt == 1) ? '+' : '-');
    }
    *mem = value;
}

void getToValue(unsigned char * mem, unsigned char value) {
    if (!value) return;
    makeLoop(mem, value);
    std::cout << '.';
}