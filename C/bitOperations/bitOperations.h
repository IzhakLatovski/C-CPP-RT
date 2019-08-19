#ifndef BITOP_H
#define BITOP_H

int invert(unsigned char x);
int rotate(unsigned char x, unsigned int n);
unsigned int setbits(unsigned char x, unsigned int p, unsigned int n, unsigned char y);
int setbitsTwo(unsigned int w, unsigned int i, unsigned int j, unsigned int value);


#endif
