/*
 Autor: Matheus bechelli Duarte Migliaresi;
 RA: 180383;
 Exercício: 1009;
 Data: 22/11/2024
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    char nome[10];
    double salario_fixo, total_vendas, salario_final;
    
    scanf("%s", &nome);
    scanf("%lf", &salario_fixo);
    scanf("%lf", &total_vendas);

    salario_final = salario_fixo + (total_vendas * 0.15);
    
    printf("TOTAL = R$ %.2lf\n", salario_final);
    
}
