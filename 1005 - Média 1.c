/*
 Autor: Matheus Bechelli Duarte Migliaresi;
 RA: 180383;
 Exercício: 1005;
 Data: 22/11/2024;
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    double a, b, media;
    
    scanf("%lf", &a);
    scanf("%lf", &b);
    
    a = a * 3.5;
    b = b * 7.5;
    
    media = (a + b) / 11;
    
    printf("MEDIA = %.5lf\n", media);
    
}
