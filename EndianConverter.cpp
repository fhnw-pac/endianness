// EndianConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

union byteAccessor
{
    uint8_t arr[4];
    uint32_t ui;
};

void printBytesInMemoryOrder(uint32_t i) {

    byteAccessor ba;
    ba.ui = i;

    std::cout << "input in hex: " << std::hex << std::uppercase << (int)i << std::dec << std::endl;

    for (int i = 0; i < sizeof(ba); ++i) {
        std::cout << "byte " << i << ": " << std::hex << std::uppercase << (int)ba.arr[i] << std::endl;
    }
}

/*
    input is little endian (DCBA), convert to little endian (ABCD)
*/
int toBig(uint32_t i)
{
    return 0;
}

int main()
{
    uint32_t test = 0x0A0B0C0D;
    std::cout << "little endian" << std::endl;
    printBytesInMemoryOrder(test);
    std::cout << std::endl << "big endian (will be interpreted wrong - because x86 is a little endian machine)" << std::endl;
    printBytesInMemoryOrder(test = toBig(test));
}
