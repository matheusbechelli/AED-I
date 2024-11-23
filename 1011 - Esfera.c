/*
 Autor: Matheus Bechelli Duarte Migliaresi;
 RA: 180383;
 Exercício: 1011;
 Data: 22/11/2024;
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    double raio, pi = 3.14159, volume;
    
    scanf("%lf", &raio);

    volume = (4/3.0) * pi * (raio * raio * raio);
    
    printf("VOLUME = %.3lf\n", volume);
    
}
