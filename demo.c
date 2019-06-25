#include <stdio.h>
#include <stdlib.h>

#include "bignum.h"
#include "mymacro.h"

int main() {
    BigNum num1, num2, num3, num4;

    bigNumInit( &num1, 256 );
    bigNumInit( &num2, 256 );
    
    
    printf("\n===========================\n");
    printf("display add, sub, mul, div:\n");
    bigNumSetDec( &num1, "1234523213123212" );
    bigNumSetHex( &num2, "4B6E8117ED5E51" );
    printf("num1: ");
    bigNumPrintDec( &num1 );
    printf("num2: ");
    bigNumPrintDec( &num2 );
    
    bigNumAdd( &num3, &num1, &num2 );
    printf("num1+num2: ");
    bigNumPrintDec( &num3 );
    
    bigNumSub( &num3, &num1, &num2 );
    printf("num1-num2: ");
    bigNumPrintDec( &num3 );
    
    bigNumMul( &num3, &num1, &num2 );
    printf("num1*num2: ");
    bigNumPrintDec( &num3 );

    bigNumDiv( &num3, &num4, &num1, &num2 );
    printf("num1/num2: ");
    bigNumPrintDec( &num3 );
    printf("num1%%num2: ");
    bigNumPrintDec( &num4 );
    printf("===========================\n");

    printf("\n===========================\n");
    printf("print 21232123984567889 in\n");
    printf("dec: ");
    bigNumPrintDec( &num2 );
    printf("bin: ");
    bigNumPrintBin( &num2 );
    printf("hex: ");
    bigNumPrintHex( &num2 );
    printf("base 8: ");
    bigNumPrint( &num2, 8 );
    printf("base 7: ");
    bigNumPrint( &num2, 7 );
    printf("base 3: ");
    bigNumPrint( &num2, 3 );
    printf("===========================\n");

    printf("\n===========================\n");
    printf("display power:\n");
    bigNumSetDec( &num1, "12345" );
    bigNumSetDec( &num2, "678" );
    printf("num1: ");
    bigNumPrintDec( &num1 );
    printf("num2: ");
    bigNumPrintDec( &num2 );
    
    bigNumPow( &num3, &num1, &num2 );
    printf("num1^num2: ");
    bigNumPrintDec( &num3 );
    printf("===========================\n");

    printf("\n===========================\n");
    printf("display factorial:\n");
    bigNumSetDec( &num1, "1000" );
    printf("num1: ");
    bigNumPrintDec( &num1 );
    
    bigNumFactorial( &num3, &num1 );
    printf("num1!: ");
    bigNumPrintDec( &num3 );
    printf("===========================\n");

    printf("\n===========================\n");
    printf("display permutation & combination:\n");
    bigNumSetDec( &num1, "87" );
    bigNumSetDec( &num2, "63" );
    printf("num1: ");
    bigNumPrintDec( &num1 );
    printf("num2: ");
    bigNumPrintDec( &num2 );

    bigNumPermutation( &num3, &num1, &num2 );
    printf("P(87,63): ");
    bigNumPrintDec( &num3 );
    bigNumCombination( &num3, &num1, &num2 );
    printf("C(87,63): ");
    bigNumPrintDec( &num3 );
    printf("===========================\n");

    printf("\n===========================\n");
    printf("Set Hex & display GCD & LCM:\n");
    bigNumSetHex( &num1, "8765432187654321");
    bigNumSetHex( &num2, "1234567812345678");
    printf("num1: ");
    bigNumPrintDec( &num1 );
    printf("num2: ");
    bigNumPrintDec( &num2 );

    bigNumGCD( &num3, &num1, &num2 );
    printf("GCD(num1,num2): ");
    bigNumPrintDec( &num3 );
    bigNumLCM( &num3, &num1, &num2 );
    printf("LCM(num1,num2): ");
    bigNumPrintDec( &num3 );
    printf("===========================\n");

    printf("\n===========================\n");
    printf("Set Bin & Fibonacci & isPrime:\n");
    bigNumSetBin( &num1, "10001001");
    printf("num1: ");
    bigNumPrintDec( &num1 );

    NthFibonacci( &num3, &num1 );
    printf("num1-th Fibonacci number: ");
    bigNumPrintDec( &num3 );
    
    printf("is it prime?\nans: ");
    if ( isPrime( &num1 ) )	printf("true\n");
    else	printf("false\n");
    printf("===========================\n");

    printf("\n===========================\n");
    printf("isPrime & isPalindrome:\n");
    bigNumSetDec( &num1, "123454321");
    printf("num1: ");
    bigNumPrintDec( &num1 );

    printf("\nis it prime?\nans: ");
    if ( isPrime( &num1 ) )	printf("true\n");
    else	printf("false\n");
    
	printf("\nis it palindrome?\nans: ");
    if ( isPalindrome( &num1 ) )	printf("true\n");
    else	printf("false\n");
    printf("===========================\n");

    printf("\n===========================\n");
    printf("SQRT & Log:\n");
    bigNumSetDec( &num1, "2");
    bigNumSetDec( &num2, "262144");
    printf("num1: ");
    bigNumPrintDec( &num1 );
    printf("num2: ");
    bigNumPrintDec( &num2 );

    bigNumSQRT( &num3, &num2 );
    printf("SQRT of num2: ");
    bigNumPrintDec( &num3 );

	bigNumLog( &num3, &num1, &num2 );
	printf("LOG(num1, num2): ");
    bigNumPrintDec( &num3 );
    printf("===========================\n");

    return 0;
}