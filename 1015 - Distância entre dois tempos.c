/*
 Autor: Matheus Bechelli Duarte Migliaresi;
 RA: 180383;
 Exercício: 1015;
 Data: 22/11/2024;
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    
    double x1, x2, y1, y2, distancia;
    
    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);
    
    distancia = sqrt(((x2 -x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
    
    printf("%.4lf\n", distancia);
    
}
