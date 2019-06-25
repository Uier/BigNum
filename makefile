all:
	gcc -static -std=c11 -O2 -lm test.c -o test
	gcc -static -std=c11 -O2 -lm demo.c -o demo
