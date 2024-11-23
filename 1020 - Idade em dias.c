/*
 Autor: Matheus Bechelli Duarte Migliaresi;
 RA: 180383;
 Exercício: 1020;
 Data: 23/11/2024;
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int idade,ano , mes, dia;
    
    scanf("%d", &idade);
    
    ano = idade / 365;
    mes = (idade % 365) / 30;
    dia = (idade % 365) % 30;
        
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", ano, mes, dia);
    
}
