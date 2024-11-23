/*
 Autor: Matheus Bechelli Duarte Migliaresi;
 RA: 180383;
 Exercício: 1014;
 Data: 22/11/2024;
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int x;
    double y, consumo;
    
    scanf("%d", &x);
    scanf("%lf", &y);
    
    consumo = x / y;
    
    printf("%.3lf km/l\n", consumo);
    
}


