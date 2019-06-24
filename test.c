#include <stdio.h>
#include <stdlib.h>

#include "bignum.h"
#include "mymacro.h"

int main() {
    BigNum num1;
    BigNum num2, num3, num4;

    __bigNumInitSize( &num1, 1000 );
    __bigNumInitSize( &num2, 1000 );
    // __bigNumInitSize( &num3, 700 );
    // __bigNumInitSize( &num4, 700 );
    // bigNumInit( &num1, 4096 );
    // bigNumInit( &num3, 4096 );
    bigNumSetDec( &num2, "10000" );
    NthFibonacci( &num1, &num2 );
    bigNumPrintDec( &num1 );
    bigNumFree( &num1 );
    bigNumFree( &num2 );
    // bigNumFree( &num3 );
    // bigNumFree( &num4 );
    
    return 0;
    // 9756277979052589857
    bigNumInit( &num1, 128 );
    bigNumSetHex( &num1, "8765432187654321");
    bigNumPrintDec( &num1 );
    bigNumPrintBin( &num1 );
    bigNumPrintHex( &num1 );

    // 1311768465173141112
    bigNumInit( &num2, 128 );
    bigNumSetHex( &num2, "1234567812345678");
    bigNumPrintHex( &num2 );
    // bigNumFree( &num1 );
    // bigNumFree( &num2 );
    // return 0;

    // 11068046444225730969
    bigNumAdd( &num3, &num1, &num2 );
    bigNumPrintDec( &num3 );

    // 8444509513879448745
    bigNumSub( &num3, &num1, &num2 );
    bigNumPrintDec( &num3 );

    // 12797977790384330769265737619320900984
    bigNumMul( &num3, &num1, &num2 );
    bigNumPrintDec( &num3 );

    bigNumDiv( &num3, &num4, &num1, &num2 );
    // 7
    bigNumPrintDec( &num3 );
    // 573898722840602073
    bigNumPrintDec( &num4 );

    // 38654705673
    bigNumGCD( &num3, &num1, &num2 );
    bigNumPrintDec( &num3 );

    // 331084600634370241406177208
    bigNumLCM( &num3, &num1, &num2 );
    bigNumPrintDec( &num3 );

    // 88393601556881408918814842533141000142486815892907919024928757521165040585171318827661185841057
    bigNumSetDec( &num2, "5" );
    bigNumPow( &num3, &num1, &num2);
    bigNumPrintDec( &num3 );

    // 815915283247897734345611269596115894272000000000
    bigNumSetDec( &num1, "40" );
    bigNumFactorial( &num3, &num1);
    bigNumPrintDec( &num3 );

    bigNumSetDec( &num2, "20" );
    // 137846528820
    bigNumCombination( &num3, &num1, &num2 );
    bigNumPrintDec( &num3 );

    // 335367096786357081410764800000
    bigNumPermutation( &num3, &num1, &num2 );
    bigNumPrintDec( &num3 );

    return 0;
}