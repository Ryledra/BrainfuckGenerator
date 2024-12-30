#pragma once

typedef struct PrimeFactors {
    int  factors [2] {0, 0};
    int remainder {};
};

bool isPrime(int num);
PrimeFactors getPrimeFactors(int diff);