/*
 Autor: Matheus Bechelli Duarte Migliaresi;
 RA: 180383;
 Exercício: 1008;
 Data: 22/11/2024;
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int numero, horas_trabalhadas;
    
    double valor_hora, salario;
    
    scanf("%d", &numero);
    scanf("%d", &horas_trabalhadas);
    scanf("%lf", &valor_hora);
    
    salario = valor_hora * horas_trabalhadas;
    
    printf("NUMBER = %d\n", numero);
    printf("SALARY = U$ %.2lf\n", salario);
    
}
