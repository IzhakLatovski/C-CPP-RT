#ifndef WQUEUE_H
#define WQUEUE_H

typedef struct wqueue wqueue;

wqueue* createWqueue(unsigned int sizeOfQueue);
int destroyWqueue(wqueue* newWqueue);
int readFromQueue(wqueue* newWqueue, void** message);
int writeToQueue(wqueue* newWqueue, void* message);
void printWqueue(wqueue* newWqueue);

#endif