#ifndef MEMORY_H
#define MEMORY_H

void* memInit(char* buffer, int* size);
void* memAlloc(char* buffer,  int sizeBuffer, int sizeAlloc);
void memFree(char* pointer,int sizeBuffer);

#endif