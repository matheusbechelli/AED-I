#include <stdio.h>
#include <stdlib.h>

int compare_pares(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int compare_impares(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int main()
{
    int N;
    scanf("%d", &N);

    if (N <= 0)
    {
        printf("Número inválido de elementos.\n");
        return 1;
    }

    int valores[N], pares[N], impares[N];
    int count_pares = 0, count_impares = 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &valores[i]);
        if (valores[i] % 2 == 0)
        {
            pares[count_pares++] = valores[i];
        }
        else
        {
            impares[count_impares++] = valores[i];
        }
    }

    qsort(pares, count_pares, sizeof(int), compare_pares);

    qsort(impares, count_impares, sizeof(int), compare_impares);

    for (int i = 0; i < count_pares; i++)
    {
        printf("%d\n", pares[i]);
    }
  
    for (int i = 0; i < count_impares; i++)
    {
        printf("%d\n", impares[i]);
    }

    return 0;
}
