#ifndef WORKING_H
#define WORKING_H
#include <stdio.h>

typedef struct{
	int numberOfFeatures_m;
	int* array_m;
} bitmap_t;


bitmap_t* createBitmap(int nf);
void destroyBitmap(bitmap_t* bitmap);
void intToBinary(int n);
void printAllFeatures(bitmap_t* bitmap);
int bitOn(bitmap_t* bitmap, int feature);
int bitOff(bitmap_t* bitmap, int feature);
int bitStatus(bitmap_t* bitmap, int feature);

#endif