#ifndef PRODUCER_H
#define PRODUCER_H

#include "wqueue.h"

typedef struct producers producers_t;

producers_t* createProducers();
void joinProducers(producers_t* prod);
void* producerFunc(void* arg);

#endif