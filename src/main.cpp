#include <iostream>

class X {
    private:
        unsigned char value = {};
        X * next;

    public:
        X(char* input);
        void printValue();
        void bfValue(unsigned char mem);
};

typedef struct PrimeFactors {
    int  factors [2] {0, 0};
    int remainder {};
};

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

/*
    6: >++[-<+++>]<.
    7: >++[-<+++>]<+.
    ...
    12 >+++[-<++++>]<.
    13 >+++[-<++++>]<+.
*/
void makeLoop(unsigned char *mem, unsigned char value)   {
    PrimeFactors primes = getPrimeFactors(abs((*mem) - value));
    // std::cout << primes.factors[0] << '\t' << primes.factors[1] << '\n';
    if(!primes.factors[0] && !primes.factors[1]) {
        int itt = { (*mem < value) ? 1 : -1 };
        for(int i = 0; i < primes.remainder; i++) {
            *mem += itt;
            std::cout << ((itt == 1) ? '+' : '-');
        }
        // std::cout << *mem << '\n';
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
    // std::cout << *mem << '\n';
}

void getToValue(unsigned char * mem, unsigned char value) {
    if (!value) return;
    makeLoop(mem, value);
    std::cout << '.';
}

void X::bfValue(unsigned char mem)  {
    getToValue(&mem, value);
    if (!next->value) return;
    (*next).bfValue(mem);
};

int main(int argc, char *argv[])  {
    if (argc != 2) return -1;
    X str = { X( argv[1] ) };
    // str.printValue();
    str.bfValue((unsigned char)0);
    std::cout << "\n";
    return 0;
}