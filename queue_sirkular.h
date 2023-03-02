/*
NIM : 13322033
Nama : Rivaldo Y.G Butarbutar
Nama Program : Header Queue Sirkular
*/

#ifndef _QUEUE_H
#define _QUEUE_H

#define boolean unsigned char
#define true 1
#define false 0

#define Nil -99

typedef struct queue
{
    long *T;
    int Head;
    int Tail;
    int MaxEl;
} QUEUE;

void CreateEmpty(QUEUE *Q, int Max);

void DeAlokai(QUEUE *Q);

int IsEmpty(QUEUE Q);

int IsFull(QUEUE Q);

void Add(QUEUE *Q, long X);

void Del(QUEUE *Q, long *X);

#endif