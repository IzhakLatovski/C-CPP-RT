#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <openssl/md5.h>
#include"hash.h"
#include"init.h"

extern size_t hashFunction(void* str)
{
    size_t h=5381;
    int c;
    unsigned char s[200];
    strcpy((char*)s,(char*)str);
    c=(*s)++;
    while(c)
    {
        h=((h<<5)+h)+c;/*hash*33+c*/
        c=(*s)++;
    }
    return h;
}

extern void printFunction(void* key,void* value)
{
    int i;
    printf("Key=");
    for(i = 0; i < MD5_DIGEST_LENGTH; i++) 
        printf("%02x", ((unsigned char*)key)[i]);
    printf("\tValue=%s\n",(unsigned char*)value);
}

extern int cmpFunction(void* a,void* b)
{
    return strcmp((char*)a,(char*)b);
}

int initFunc(hashArr** h,char* filename)
{
    size_t size=200;
    hashFunc hf=hashFunction;
    printFunc pf=printFunction;
    cmpFunc cmpf=cmpFunction;
    *h=NULL;
    (*h)=createHash(size,hf,cmpf,pf);
    if(!(*h))
        return 0;
    printf("Enter File Name or Directory:\n");
    scanf("%s",filename);
    return 1;
}