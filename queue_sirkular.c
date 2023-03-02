/*
NIM : 13322033
Nama : Rivaldo Y.G Butarbutar
Nama Program : Implementasi dari header Queue Sirkular
*/

#include "queue_sirkular.h"
#include <stdio.h>
#include <stdlib.h>

void CreateEmpty(QUEUE *Q, int Max)
{
    Q->T = (long *)malloc(Max * sizeof(long));
    if (Q->T != NULL)
    {
        Q->Head = Nil;
        Q->Tail = Nil;
        Q->MaxEl = Max;
    }
    else
    {
        Q->MaxEl = 0;
    }
}

void DeAlokai(QUEUE *Q)
{
    Q->Head = Nil;
    Q->Tail = Nil;
    Q->MaxEl = 0;
    free(Q->T);
}

int IsEmpty(QUEUE Q)
{
    if (Q.Head == Nil && Q.Tail == Nil)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsFull(QUEUE Q)
{
    if ((Q.Head == 1 && Q.Tail == Q.MaxEl) || (Q.Head == Q.Tail + 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Add(QUEUE *Q, long X)
{
    if (!IsFull(*Q))
    {
        if (IsEmpty(*Q))
        {
            Q->Head = 0;
            Q->Tail = 0;
            Q->T[Q->Head] = X;
            Q->T[Q->Tail] = X;
        }
        else
        {
            Q->Tail = Q->Tail + 1;
            Q->T[Q->Tail] = X;
        }
    }
    else
    {
        printf("Queue Full, Tidak Bisa Melakukan Proses Penambahan Elemen");
    }
}

void Del(QUEUE *Q, long *X)
{
    if (!IsEmpty(*Q))
    {
        if (Q->Head < Q->Tail)
        {
            *X = Q->T[Q->Head];
            Q->Head = Q->Head + 1;
        }
        else
        {
            *X = Q->T[Q->Head];
            Q->Head = Nil;
            Q->Tail = Nil;
        }
    }
}
