#include <iostream>

class X {
    private:
        unsigned char value = {};
        X * next;

    public:
        X(char* input);
        void print();
};

X::X(char* input)   {
    // std::cout << *input;
    if (!*input) { return; }
    value = (unsigned char)(* input);
    next = new X(++input);
};

void X::print()    {
    if (!value) { return; }
    std::cout << value;
    (*next).print();
};

int main(int argc, char *argv[])  {
    if (argc != 2) return -1;
    std::cout << argv[1] << "\n";
    X str = { X( argv[1] ) };
    str.print();
    return 0;
}