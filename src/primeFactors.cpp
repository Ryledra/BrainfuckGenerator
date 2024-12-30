#include "primeFactors.hpp"

bool isPrime(int num)   {
    if(num < 2) return false;
    if(num == 2) return true;
    if(num % 2 == 0) return false;
    
    for(int i = 3; i < num; i+=2)
        if(num % i == 0) return false;
    
    return true;
}

PrimeFactors getPrimeFactors(int diff)   {
    // if difference is prime, recurse with diff-1
    if(isPrime(diff)) {
        PrimeFactors primes = getPrimeFactors(diff - 1);
        primes.remainder++;
        return primes;
    }
    PrimeFactors primes {};
    // if difference < 6, return rem(6), with x&y=0
    if(diff < 6) {
        primes.remainder = diff;
        return primes;
    }
    primes.factors[0] = 1;
    primes.factors[1] = 1;
    bool itter {0};
    int divisor {2};
    // get prime factors
    while(diff != 1)    {
        // std::cout << diff << '\t' << divisor << '\n';
        while (diff % divisor == 0) {
            primes.factors[itter] *= divisor;
            diff /= divisor;
            itter = !itter;
        }
        divisor++;
    }
    // std::cout << primes.factors[0] << ' ' << primes.factors[1] << ' '
    // << primes.remainder << '\n';
    return primes;
}