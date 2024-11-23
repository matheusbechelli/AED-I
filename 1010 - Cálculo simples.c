/*
 Autor: Matheus Bechelli Duarte Migliaresi;
 RA: 180383;
 Exercício: 1010;
 Data: 22/11/2024;
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int codigo1, n_pecas1, codigo2, n_pecas2;
    double valor_pecas1, valor_pecas2, soma1;
    
    scanf("%d %d %lf", &codigo1, &n_pecas1, &valor_pecas1);
    scanf("%d %d %lf", &codigo2, &n_pecas2, &valor_pecas2);
    
    soma1 = n_pecas1 * valor_pecas1 + n_pecas2 * valor_pecas2;
    
    printf("VALOR A PAGAR: R$ %.2lf\n", soma1);
    
    
}
