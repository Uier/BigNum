#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Get the beginning index of BigNum's data
int32_t __getIdx( const BigNum *pObj );

// Carrying a BigNum
int32_t __carry( BigNum *pObj );

// Initialize with certain data size
int32_t __bitNumInit( BigNum *pNum, int32_t size );

// Print overflow warning and return -1
int32_t __overflow();

// Assign a BigNum as zero
void __returnZero( BigNum *pNum );

