/*
NIM : 13322033
Nama : Rivaldo Y.G Butarbutar
Nama Program : Driver dari header dan Implementasi QUEUE Sirkular
*/

#include "queue_sirkular.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, del, i, j;
    int pilihan, jumlah;
    QUEUE Q;

    printf("Masukkan Size Queue : ");
    scanf("%d", &n);
    CreateEmpty(&Q, n);

    int *T;
    T = (int *)malloc(n * sizeof(int));

    do
    {
        printf("silahkan Masukkan Nilai Queue dengan Maksimum %d elemen dan tidak boleh angka -99\n", n);
        printf("Jika nilai -99 atau sudah melebihi batas maksimum elemen, maka nilai tidak dimasukkan ke dalam Queue\n");
        printf("Add nilai ke dalam Queue :\n");
        i = 0;
        do
        {
            scanf("%d", &T[i]);
            if (T[i] == -99)
            {
                system("exit");
            }
            else
            {
                Add(&Q, T[i]);
                i++;
            }
        } while (i < n && T[i] != -99);

        printf("\nIsi Queue : ");
        jumlah = 1;
        if (!IsEmpty(Q))
        {
            j = Q.Head;
            while (j != Q.Tail)
            {
                printf("%ld ", Q.T[j]);
                jumlah++;
                j++;
            }
            printf("%ld\n", Q.T[j]);
        }
        printf("Nilai Header = %d\n", Q.T[Q.Head]);
        printf("Index Header = %d\n", Q.Head);
        printf("Nilai Tail = %d\n", Q.T[Q.Tail]);
        printf("Index Tail = %d\n", Q.Tail);
        printf("Banyak ELemen = %d\n", jumlah);

        if (IsFull(Q) == 1)
        {
            printf("Status Queue: Full");
        }
        else if (IsEmpty(Q) == 1)
        {
            printf("Status Queue: Empety");
        }
        else
        {
            printf("Status Queue: Not Full & Not Empety");
        }

        printf("\n\nMasukkan jumlah elemen yang akan di hapus (Delete Queue): ");
        scanf("%d", &del);

        for (i = 0; i < del; i++)
        {
            long x = Q.T[Q.Head];
            Del(&Q, &x);
        }

        printf("Isi Queue : ");
        jumlah = 1;
        if (!IsEmpty(Q))
        {
            j = Q.Head;
            while (j != Q.Tail)
            {
                printf("%ld ", Q.T[j]);
                jumlah++;
                j++;
            }
            printf("%ld\n", Q.T[j]);
        }

        printf("Nilai Header = %d\n", Q.T[Q.Head]);
        printf("Index Header = %d\n", Q.Head);
        printf("Nilai Tail = %d\n", Q.T[Q.Tail]);
        printf("Index Tail = %d\n", Q.Tail);
        printf("Banyak ELemen = %d\n", jumlah);

        if (IsFull(Q) == 1)
        {
            printf("Status Queue: Full\n");
        }
        else if (IsEmpty(Q) == 1)
        {
            printf("Status Queue: Empety\n");
        }
        else
        {
            printf("Status Queue : Not Full & Not Empty\n");
        }

        printf("Apakah Anda Ingin Melakukan Proses Add Queue (YES = 1 , NO = 0) : ");
        scanf("%d", &pilihan);

    } while (pilihan == 1);
    printf("Terimakasih ... \n");
}
