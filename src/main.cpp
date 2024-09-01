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

X::X(char* input)   {
    // std::cout << *input;
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
    if (!value) return;
    int itt = { (mem < value) ? 1 : -1 };

    while (mem != value) {
        mem += itt;
        std::cout << ((itt == 1) ? '+' : '-');
    }

    std::cout << '.';
    (*next).bfValue(mem);
};

int main(int argc, char *argv[])  {
    if (argc != 2) return -1;
    std::cout << argv[1] << "\n";
    X str = { X( argv[1] ) };
    str.printValue();
    std::cout << "\n";
    str.bfValue((unsigned char)0);
    return 0;
}