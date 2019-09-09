#ifndef WQUEUE_H
#define WQUEUE_H

typedef struct wqueue wqueue;


wqueue* createWqueue(unsigned int sizeOfQueue);

int destroyWqueue(wqueue* newWqueue);
/*
readFromQueue();*/
int writeToQueue(wqueue* newWqueue, char* message);


#endif