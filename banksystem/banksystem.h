#ifndef BANKSYSTEM_H_INCLUDED
#define BANKSYSTEM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
struct date
{
    int month,day,year;

};
struct transuction
{
    char *operation;
    struct tm tm;
    float amount;
};
struct accountdata
{

    char name[20];
   unsigned short acc_no,age;
    char address[20];
    unsigned short phone;
    struct date dob;
    unsigned short national_id;
    unsigned short id;
    float money;
    struct transuction *transuctions;
    int numOftransuctions;
};
struct Node
{
    struct accountdata info;
    struct Node *next;
};
typedef struct Node node;
typedef struct transuction transuct;


#endif // BANKSYSTEM_H_INCLUDED
