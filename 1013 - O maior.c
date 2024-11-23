/*
 Autor: Matheus Bechelli Duarte Migliaresi;
 RA: 180383;
 Exercício: 1013;
 Data: 22/11/2024;
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int a, b, c, teste, teste2;
    
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    
    teste = (a + b + abs(a - b)) / 2;
    
    teste2 = (teste + c + abs(teste - c)) / 2;
    
    printf("%d eh o maior\n", teste2);
}
