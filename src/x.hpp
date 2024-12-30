#pragma once

class X {
    private:
        unsigned char value = {};
        X * next;

    public:
        X(char* input);
        void printValue();
        void bfValue(unsigned char mem);
};

void makeLoop(unsigned char *mem, unsigned char value);
void getToValue(unsigned char * mem, unsigned char value);