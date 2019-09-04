#ifndef MEMORY_H
#define MEMORY_H

void* memInit(unsigned int* buffer, unsigned int* sizeBuffer);
void* memAlloc(unsigned int* buffer,  unsigned int sizeBuffer, unsigned int sizeAlloc);
void memFree(unsigned int* buffer, unsigned int* pointer, unsigned int sizeBuffer);

unsigned int getSize(unsigned int* header);
int isOccupied(unsigned int* header);

#endif