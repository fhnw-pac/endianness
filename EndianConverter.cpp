// EndianConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

union byteAccessor
{
    uint8_t arr[4];
    uint32_t ui;
};

void printBytesInMemoryOrder(uint32_t i) {

    byteAccessor ba;
    ba.ui = i;

    cout << "input in hex: " << hex << uppercase << (int)i << dec << endl;

    for (int i = 0; i < sizeof(ba); ++i) {
        cout << "byte " << i << ": " << std::hex << uppercase << (int)ba.arr[i] << endl;
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
    cout << "little endian" << endl;
    printBytesInMemoryOrder(test);
    cout << endl << "big endian (will be interpreted wrong - because x86 is a little endian machine)" << endl;
    printBytesInMemoryOrder(test = toBig(test));
}
