/*
 Autor: Matheus Bechelli Duarte Migliaresi;
 RA: 180383;
 Exercício: 1011;
 Data: 22/11/2024;
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    double a, b, c, area_triangulo_retangulo, area_circulo, area_trapezio, area_quadrado, area_retangulo, pi = 3.14159;
    
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    
    area_triangulo_retangulo = (a * c) / 2;
    area_circulo = (c * c) * pi;
    area_trapezio = ((a + b) * c) / 2;
    area_quadrado = (b * b);
    area_retangulo = (a *b);
    
    printf("TRIANGULO: %.3lf\n", area_triangulo_retangulo);
    printf("CIRCULO: %.3lf\n", area_circulo);
    printf("TRAPEZIO: %.3lf\n", area_trapezio);
    printf("QUADRADO: %.3lf\n", area_quadrado);
    printf("RETANGULO: %.3lf\n", area_retangulo);
    
}
