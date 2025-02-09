#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenarSelecao(int array[], int tamanho);
void lerArray(int array[], int tamanho);
int contarOcorrencias(int array[], int tamanho, int numero);
void copiarArray(int origem[], int destino[], int tamanhoDestino, int indiceInicial);

int main() {
    int tamanhoArray, quantidadeRodadas;
    int indiceInicial, indiceFinal, posicaoMenor, pontuacaoGuga, pontuacaoDabriel;
    int *arrayPrincipal, *arrayIntervalo;
    int rodada;

    scanf("%d %d", &tamanhoArray, &quantidadeRodadas);
    arrayPrincipal = (int*) malloc(tamanhoArray * sizeof(int));
    lerArray(arrayPrincipal, tamanhoArray);
    
    for(rodada = 0; rodada < quantidadeRodadas; rodada++) {
        scanf("%d %d %d %d %d", &indiceInicial, &indiceFinal, &posicaoMenor, &pontuacaoGuga, &pontuacaoDabriel);

        int tamanhoIntervalo = indiceFinal - indiceInicial + 1;
        arrayIntervalo = (int*) malloc(tamanhoIntervalo * sizeof(int));
        copiarArray(arrayPrincipal, arrayIntervalo, tamanhoIntervalo, indiceInicial - 1);

        ordenarSelecao(arrayIntervalo, tamanhoIntervalo);
        int menorValor = arrayIntervalo[posicaoMenor - 1];
        int ocorrenciasMenor = contarOcorrencias(arrayIntervalo, tamanhoIntervalo, menorValor);

        int diferencaGuga = abs(ocorrenciasMenor - pontuacaoGuga);
        int diferencaDabriel = abs(ocorrenciasMenor - pontuacaoDabriel);

        char resultado = 'E';
        if(diferencaGuga < diferencaDabriel) { resultado = 'G'; }
        else if(diferencaDabriel < diferencaGuga) { resultado = 'D'; }

        printf("%d %d %c\n", menorValor, ocorrenciasMenor, resultado);
        free(arrayIntervalo);
    }

    free(arrayPrincipal);
    return 0;
}

int contarOcorrencias(int array[], int tamanho, int numero) {
    int i, contador = 0;
    for(i = 0; i < tamanho; i++) {
        if(array[i] == numero) {
            contador++;
        }
    }
    return contador;
}

void ordenarSelecao(int array[], int tamanho) {
    int i, j;
    for (i = 0; i < tamanho - 1; i++) {
        int indiceMinimo = i;
        for (j = i + 1; j < tamanho; j++) {
            if (array[j] < array[indiceMinimo]) {
                indiceMinimo = j;
            }
        }
        int temp = array[i];
        array[i] = array[indiceMinimo];
        array[indiceMinimo] = temp;
    }
}

void copiarArray(int origem[], int destino[], int tamanhoDestino, int indiceInicial) {
    int i, j;
    for(i = 0, j = indiceInicial; i < tamanhoDestino; i++, j++) {
        destino[i] = origem[j];
    }
}

void lerArray(int array[], int tamanho) {
    int i;
    for(i = 0; i < tamanho; i++) {
        scanf("%d", &array[i]);
    }
}
