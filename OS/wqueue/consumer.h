#ifndef CONSUMER_H
#define CONSUMER_H

#include "wqueue.h"

typedef struct consumers consumers_t;

consumers_t* createConsumers();
void joinConsumers(consumers_t* prod);
void* consumerFunc(void* arg);

#endif
