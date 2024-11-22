/*
 Autor: Matheus Bechelli Duarte Migliaresi;
 RA: 180383;
 Exercício: 1002;
 Data: 22/11/2024;
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    double raio, area, pi = 3.14159;
    
    scanf("%lf", &raio);

    area = pi * (raio * raio);
    
    printf("A=%.4lf\n", area);
}

