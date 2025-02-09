/*
Nome: Matheus Bechelli Duarte Migliaresi;
RA: 180383;
Exercício: 1022;
*/

#include <stdio.h>

typedef struct {
    int numerador;
    int denominador;
} Racional;

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplificar(Racional *r) {
    int divisor = mdc(r->numerador, r->denominador);
    r->numerador /= divisor;
    r->denominador /= divisor;
    
    if (r->denominador < 0) {
        r->numerador = -r->numerador;
        r->denominador = -r->denominador;
    }
}

Racional soma(Racional r1, Racional r2) {
    Racional resultado;
    resultado.numerador = r1.numerador * r2.denominador + r2.numerador * r1.denominador;
    resultado.denominador = r1.denominador * r2.denominador;
    return resultado;
}

Racional subtrai(Racional r1, Racional r2) {
    Racional resultado;
    resultado.numerador = r1.numerador * r2.denominador - r2.numerador * r1.denominador;
    resultado.denominador = r1.denominador * r2.denominador;
    return resultado;
}

Racional multiplica(Racional r1, Racional r2) {
    Racional resultado;
    resultado.numerador = r1.numerador * r2.numerador;
    resultado.denominador = r1.denominador * r2.denominador;
    return resultado;
}

Racional divide(Racional r1, Racional r2) {
    Racional resultado;
    resultado.numerador = r1.numerador * r2.denominador;
    resultado.denominador = r2.numerador * r1.denominador;
    return resultado;
}

void imprimeResultado(Racional original, Racional simplificado) {
    printf("%d/%d = %d/%d\n", original.numerador, original.denominador, simplificado.numerador, simplificado.denominador);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Racional r1, r2, resultado;
        char operacao;
        scanf("%d / %d %c %d / %d", &r1.numerador, &r1.denominador, &operacao, &r2.numerador, &r2.denominador);

        switch (operacao) {
            case '+':
                resultado = soma(r1, r2);
                break;
            case '-':
                resultado = subtrai(r1, r2);
                break;
            case '*':
                resultado = multiplica(r1, r2);
                break;
            case '/':
                resultado = divide(r1, r2);
                break;
        }

        Racional simplificado = resultado;
        simplificar(&simplificado);
        imprimeResultado(resultado, simplificado);
    }

    return 0;
}
