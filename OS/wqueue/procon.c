#include "wqueue.h"
#include "consumer.h"
#include "producer.h"

#define QUEUESIZE 7
#define PRODUCERS 3
#define CONSUMERS 4
#define MESSAGES 5

int main()
{
	wqueue* pcQueue=createWqueue(QUEUESIZE);
	wqueue* cpQueue=createWqueue(QUEUESIZE);
	createProducers(pcQueue);
	createConsumers(cpQueue);/*
	joinProducers();
	killConsumers();
	joinConsumers(consumers);*/
	destroyWqueue(pcQueue);
	destroyWqueue(cpQueue);

	return 0;
}