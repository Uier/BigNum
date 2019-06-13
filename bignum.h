#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define base 10000
#define max(x,y) (x >= y ? x : y)
#define min(x,y) (x <= y ? x : y)

typedef struct _BigNum_ {
	// bound: 32767, here we store 4 digits (max:9999) in an int32_t in order to handle decimal number.
    int32_t digits, *data;
    bool nega;
} BigNum;

// initial big number to n-bit integer, return -1 if fail to initialize
int32_t bigNumInit( BigNum *pNum, int32_t n );

// free a big number
void bigNumFree( BigNum *pObj );

// 0 equal, -1 (obj1 less than obj2), 1 (obj1 bigger than obj2)
int32_t bigNumCmp( const BigNum *pObj1, const BigNum *pObj2 );

// print big number decimal
void bigNumPrintDec( const BigNum *pObj );

// print big number binary
void bigNumPrintBin( const BigNum *pObj );

// print big number hex
void bigNumPrintHex( const BigNum *pObj );

// set big number by decimal string, return -1 if fail or invalid
int32_t bigNumSetDec( BigNum *pObj, const char *decimal );

// set big number by binary string, return -1 if fail or invalid
int32_t bigNumSetBin( BigNum *pObj, const char *binary );

// set big number by hex string, return -1 if fail or invalid
int32_t bigNumSetHex( BigNum *pObj, const char *hex );

// obj1 add obj2, return -1 if fail
int32_t bigNumAdd( BigNum *pAns, const BigNum *pObj1, const BigNum *pObj2 );

// obj1 substract obj2, return -1 if fail
int32_t bigNumSub( BigNum *pAns, const BigNum *pObj1, const BigNum *pObj2 );

// obj1 multiply obj2, return -1 if fail
int32_t bigNumMul( BigNum *pAns, const BigNum *pObj1, const BigNum *pObj2 );

// obj1 divide obj2, return -1 if fail
int32_t bigNumDiv( BigNum *pQuotient, BigNum *pRemainder, const BigNum *pObj1, const BigNum *pObj2 );

// obj1 to the power obj2, return -1 if fail
int32_t bigNumPow( BigNum *pAns, const BigNum *pObj1, const BigNum *pObj2 );

// factorial of obj1, return -1 if fail
int32_t bigNumFactorial( BigNum *pAns, const BigNum *pObj );

// k-permutations of n, return -1 if fail
int32_t bigNumPermutation( BigNum *pAns, const BigNum *pN, const BigNum *pK );

// k-combinations of n, return -1 if fail
int32_t bigNumCombination( BigNum *pAns, const BigNum *pN, const BigNum *pK );

// greatest common divisor of obj1 and obj2, return -1 if fail
int32_t bigNumGCD( BigNum *pAns, const BigNum *pObj1, const BigNum *pObj2 );

// least common multiple of obj1 and obj2, return -1 if fail
int32_t bigNumLCM( BigNum *pAns, const BigNum *pObj1, const BigNum *pObj2 );

// check obj is prime, 1 true, 0 false
int32_t isPrime( const BigNum *pObj );

int32_t __getIdx( const BigNum *pObj ) {
	int32_t pt = pObj->digits - 1;
	while ( pt >= 0 && pObj->data[pt] == 0 )	pt--;
	return pt == -1 ? 0 : pt;
}

void __carry( BigNum *pObj ) {
	for ( int32_t idx=0, carry=0; idx<pObj->digits; ++idx ) {
		pObj->data[idx] += carry;
		if ( pObj->data[idx] >= 0 ) {
			carry = pObj->data[idx] / base;
			pObj->data[idx] %= base;
		} else {
			carry = -1;
			pObj->data[idx] += base;
		}
	}
}

int32_t __bitNumInit( BigNum *pNum, int32_t n ) {
	pNum->digits = n;
	pNum->data = (int32_t*)calloc(pNum->digits, sizeof(int32_t));
	if ( pNum->data == NULL )	return -1;
	pNum->nega = false;
	return 0;
}

int32_t bigNumInit( BigNum *pNum, int32_t n ) {
	pNum->digits = max(n/32,1)*5;
	pNum->data = (int32_t*)calloc(pNum->digits, sizeof(int32_t));
	if ( pNum->data == NULL )	return -1;
	pNum->nega = false;
	return 0;
}

void bigNumFree( BigNum *pObj ) {
	free(pObj->data);
}

int32_t bigNumCmp( const BigNum *pObj1, const BigNum *pObj2 ) {
	int32_t idx1 = __getIdx( pObj1 ), idx2 = __getIdx( pObj2 );
	if ( idx1 < idx2 )	return -1;
	if ( idx1 > idx2 )	return 1;
	for ( ; idx1>=0; --idx1 ) {
		if ( pObj1->data[idx1] < pObj2->data[idx1] )	return -1;
		if ( pObj1->data[idx1] > pObj2->data[idx1] )	return 1;
	}
	return 0;
}

void bigNumPrintDec( const BigNum *pObj ) {
	int32_t idx = __getIdx(pObj);
	printf("%d", pObj->data[idx--]);
	for ( ; idx>=0; --idx )
		printf("%04d", pObj->data[idx]);
	puts("");
}

void bigNumPrintBin( const BigNum *pObj ) {

}

void bigNumPrintHex( const BigNum *pObj ) {

}

int32_t bigNumSetDec( BigNum *pObj, const char *decimal ) {
	int32_t len = strlen(decimal);
	for ( int32_t idx=0; idx<len; ++idx ) {
		if ( (len-1-idx)/4 > pObj->digits )	return puts("overflow! please initialize BigNum with a larger bit number."), -1;
		pObj->data[(len-1-idx)/4] = pObj->data[(len-1-idx)/4]*10 + (decimal[idx]-'0');
	}
	return 0;
}

int32_t bigNumSetBin( BigNum *pObj, const char *binary ) {
	int32_t len = strlen(binary);
	for ( int32_t idx=0; idx<len; ++idx ) {

	}
}

int32_t bigNumSetHex( BigNum *pObj, const char *hex ) {
	
}

int32_t bigNumAdd( BigNum *pAns, const BigNum *pObj1, const BigNum *pObj2 ) {
	int32_t len = max(__getIdx(pObj1),__getIdx(pObj2));
	if ( __bitNumInit(pAns, len+1) == -1 )	return -1;
	for ( int32_t idx=0; idx<=len; ++idx )
		pAns->data[idx] = pObj1->data[idx] + pObj2->data[idx];
	__carry(pAns);
	return 0;
}

int32_t bigNumSub( BigNum *pAns, const BigNum *pObj1, const BigNum *pObj2 ) {
	int32_t len = max(__getIdx(pObj1),__getIdx(pObj2));
	int32_t res = bigNumCmp(pObj1,pObj2);
}

int32_t bigNumMul( BigNum *pAns, const BigNum *pObj1, const BigNum *pObj2 ) {

}
