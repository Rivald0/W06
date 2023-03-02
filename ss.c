#include <stdio.h>
#include <stdlib.h>
#include "queue_sirkular.h"

void CreateEmpty(QUEUE *Q, int Max)
{
    Q->T = (long *)malloc((Max + 1) * sizeof(long));
    Q->MaxEl = Max;
    Q->Head = Nil;
    Q->Tail = Nil;
}

void DeAlokasi(QUEUE *Q)
{
    free(Q->T);
    Q->MaxEl = Nil;
    Q->Head = Nil;
    Q->Tail = Nil;
}

int IsEmpty(QUEUE Q)
{
    return ((Q.Head == Nil) && (Q.Tail == Nil));
}

int IsFull(QUEUE Q)
{
    return ((Q.Head == 1 && Q.Tail == Q.MaxEl) || (Q.Head == Q.Tail + 1));
}

void Add(QUEUE *Q, long X)
{
    if (IsEmpty(*Q))
    {
        Q->Head = 1;
        Q->Tail = 1;
        Q->T[Q->Tail] = X;
    }
    else
    {
        if (IsFull(*Q))
        {
            printf("Queue penuh!\n");
        }
        else
        {
            if (Q->Tail == Q->MaxEl)
            {
                Q->Tail = 1;
            }
            else
            {
                Q->Tail++;
            }
            Q->T[Q->Tail] = X;
        }
    }
}

void Del(QUEUE *Q, long *X)
{
    if (IsEmpty(*Q))
    {
        printf("Queue kosong!\n");
    }
    else
    {
        *X = Q->T[Q->Head];
        if (Q->Head == Q->Tail)
        {
            Q->Head = Nil;
            Q->Tail = Nil;
        }
        else
        {
            if (Q->Head == Q->MaxEl)
            {
                Q->Head = 1;
            }
            else
            {
                Q->Head++;
            }
        }
    }
}

int main()
{
    QUEUE Q;
    long X;
    int Max, pilih;

    printf("Masukkan jumlah maksimum elemen dalam queue: ");
    scanf("%d", &Max);
    CreateEmpty(&Q, Max);

    do
    {
        printf("Menu:\n");
        printf("1. Add\n");
        printf("2. Del\n");
        printf("3. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilih);

        switch (pilih)
        {
        case 1:
            printf("Masukkan angka: ");
            scanf("%ld", &X);
            Add(&Q, X);
            break;
        case 2:
            Del(&Q, &X);
            printf("Elemen yang dihapus: %ld\n", X);
            break;
        case 3:
            printf("Keluar dari program.\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }
    } while (pilih != 3);

    DeAlokasi(&Q);

    return 0;
}
