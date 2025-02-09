#include <stdio.h>

int main()
{
    int teste;
    long long int vet[61];
    vet[0] = 0;
    vet[1] = 1;
    for (int i = 2; i <= 63; i++)
    {
        vet[i] = vet[i - 1] + vet[i - 2];
    }
    scanf("%d", &teste);
    for (int j = 0; j < teste; j++)
    {
        int num;
        scanf("%d", &num);
        printf("Fib(%d) = %lld\n", num, vet[num]);
    }
    return 0;
}
