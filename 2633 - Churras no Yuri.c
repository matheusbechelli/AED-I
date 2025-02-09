#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[21];
    int validade;
} Carne;

int comparar(const void *a, const void *b) {
    return ((Carne *)a)->validade - ((Carne *)b)->validade;
}

int main() {
    int N;
    Carne carnes[10];

    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) {
            scanf("%s %d", carnes[i].nome, &carnes[i].validade);
        }

        qsort(carnes, N, sizeof(Carne), comparar);

        for (int i = 0; i < N; i++) {
            printf("%s", carnes[i].nome);
            if (i < N - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
