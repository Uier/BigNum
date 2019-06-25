# BigNum
computer programming course final project
implement Big Number library in c

# Usage
1. write your code in `test.c`
2. Note that you should include two header
	```c
	#include "bignum.h"
	#include "mymacro.h"
	```
3. compile with
	```
	make
	```
4. run with
	```
    ./test
    ```

# Caution
when using following functions:
```
bigNumSetDec( BigNum *pObj, const char *decimal )
bigNumSetBin( BigNum *pObj, const char *binary )
bigNumSetHex( BigNum *pObj, const char *hex )
```
**the `pObj` should be initialized.**

# Demo Presentation
http://gg.gg/bignumdemo

# Example
example code is in `demo.c`, and executive file `demo`.

# Required Function
- [x] Initialization
- [x] Free
- [x] Comparison
- [x] Addition
- [x] Subtraction
- [x] Multiplication
- [x] Division
- [x] Power
- [x] Factorial
- [x] Permutation
- [x] Combination
- [x] Print
- [x] Set
- [x] GCD
- [x] LCM

# Feature
- [x] isPrime
- [x] SQRT
- [x] Nth Fibonacci Number
- [x] Log
- [x] isPalindrome
- [x] BigNumPrint based on N(2~16)
- can handle negative number operation except exponent part of Pow
- debugger with macro