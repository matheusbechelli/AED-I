/*
 Autor: Matheus Bechelli Duarte Migliaresi;
 RA: 180383;
 Exercício: 1019;
 Data: 23/11/2024;
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int horas, minutos, segundos;
    
    scanf("%d", &segundos);
    
    horas = segundos / 3600;
    minutos = (segundos % 3600) / 60;
    segundos = (segundos % 60);
    
    printf("%d:%d:%d\n",horas, minutos, segundos);
    
}
