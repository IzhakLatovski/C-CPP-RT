#ifndef BITS_H
#define BITS_H

typedef struct
{
	int numberOfFeatures_m;
	int* array_m;
} bitmap_t;


typedef int (*BitFunction)(bitmap_t* bitmap,int feature);


bitmap_t* createBitmap(int numberOfFeatures);
void destroyBitmap(bitmap_t* bitmap);
void intToBinary(int n);
void printAllFeatures(bitmap_t* bitmap);
int bitOn(bitmap_t* bitmap, int feature);
int bitOff(bitmap_t* bitmap, int feature);
int bitStatus(bitmap_t* bitmap, int feature);
int runFunction(BitFunction function,bitmap_t* bitmap,int feture);





#endif