// Program 2: bitwise operators
// Gary Tou
// 4/21/2021

#include <iostream>
using namespace std;

int p2()
{
    int TEST = 14;

    cout << (2 & 5) << endl;  // 0
    cout << (2 | 5) << endl;  // 7    
    cout << (256 & 128) << endl;  // 0
    cout << (256 | 128) << endl;  // 384
    cout << (TEST) << endl;  // 14        
    cout << (TEST << 2) << endl;  // 56
    cout << ('G' >> 2) << endl;  // 17
    cout << ('G' << 2) << endl;  // 284
    cout << ('G' & 'H') << endl;  // 64
    cout << ('G' | 'H') << endl;  // 79
    cout << ('G' << 222) << endl;  // ???
    cout << ('G' >> 222) << endl;  // 0
    cout << ('\n' << 2) << endl;  // 40
    cout << ('\n' >> 2) << endl;  // 2
    cout << (0x14) << endl;  // 20
    cout << (0x0000ff00) << endl;  // 65280
    cout << (0x12abcdef) << endl;  // 313249263



    /*
    1. 00000010 bitwise AND with 00000101 is 00000000 converts to decimal as 0
    2. 00000010 bitwise OR with 00000101 is 00000111 converts to decimal as 7
    3. 100000000 bitwise AND with 10000000 is 00000000 converts to decimal as 0
    4. 100000000 bitwise OR with 10000000 is 110000000 converts to decimal as 384
    5. TEST is an integer defined to 14 (00001110 in binary)
    6. 00001110 shift bits left two is 00111000 converts to decimal as 56
    7. 01000111 shift bits right two is 00010001 converts to decimal as 17
    8. 01000111 shift bits left two is 100011100 converts to decimal is 284
    9. 01000111 bitwise AND with 01001000 is 1000000 converts to decimal is 64
    10. 01000111 bitwise OR with 01001000 is 1001111 converts to decimal is 79
    11. 01000111 shift bits left 222 is "C26452: Arithmetic overflow: Left shift count is negative or greater than or equal to the operand size which is undefined behavior"
    12. 01000111 shift bits right 222 is 00000000 converts to decimal is 0
    13. 00001010 shift bits left 2 is 00101000 converts to decimal is 40
    14. 00001010 shift bits right 2 is 00000010 converts to decimal is 2
    15. hexadecimal 0x14 converts to decimal is 20 (converts to binary is 10100)
    16. hexadecimal 0x0000ff00 converts to decimal is 65280 (converts to binary is 1111111100000000)
    17. hexadecimal 0x12abcdef converts to decimal is 313249263 (converts to binary is 10010101010111100110111101111)
    */

    return 0;
}