/*
 Nome: Matheus Bechelli Duarte Migliaresi;
 RA: 180383;
 Exercício: InsertionSort;
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const TAM = 20000; // constante para tamanho do vetor

void InsertionSort(int v[TAM])
{
    int i, j, x;
    for (j = 0; j < TAM; j++)
    {
        x = v[j];
        for (i = j - 1; i >= 0 && v[i] > x; i--)
        {
            v[i + 1] = v[i];
        }
        v[i + 1] = x;
    }
}

int main(void)
{
    clock_t t;
    int vetor[TAM];

    srand((unsigned)time(NULL));

    for (int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    t = clock();
    InsertionSort(vetor);
    t = clock() - t;

    printf("Tempo de execucao: %lf ms\n", ((double)t) / ((CLOCKS_PER_SEC / 1000)));
    return 0;
}
