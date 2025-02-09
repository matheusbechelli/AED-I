#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char* TipoElemento;

struct EstruturaFila {
    TipoElemento* elementos;
    int capacidade;
    int fim;
};

typedef struct EstruturaFila* TipoFila;

TipoFila criarFila(int capacidadeMax);
void destruirFila(TipoFila fila);
bool filaCheia(TipoFila fila);
bool filaVazia(TipoFila fila);
bool inserirNaFila(TipoFila fila, TipoElemento elemento);
bool removerDaFila(TipoFila fila, TipoElemento* elemento);

int main() {
    TipoFila filaLeste, filaOeste, filaSul, filaNorte, filaPrincipal;
    TipoElemento aviao;
    
    filaLeste = criarFila(1000);
    filaOeste = criarFila(1000);
    filaSul = criarFila(1000);
    filaNorte = criarFila(1000);
    filaPrincipal = criarFila(4000);
    
    int direcao;
    char idAviao[100];
    
    while (scanf("%d", &direcao) != EOF) {
        if (direcao == 0) {
            break;
        }
        
        scanf("%s", idAviao);
        aviao = idAviao;
        
        switch (direcao) {
            case -4:
                inserirNaFila(filaLeste, aviao);
                break;
            case -3:
                inserirNaFila(filaNorte, aviao);
                break;
            case -2:
                inserirNaFila(filaSul, aviao);
                break;
            case -1:
                inserirNaFila(filaOeste, aviao);
                break;
            default:
                break;
        }
    }
    
    while (!filaVazia(filaLeste) || !filaVazia(filaNorte) || !filaVazia(filaSul) || !filaVazia(filaOeste)) {
        if (!filaVazia(filaOeste)) {
            removerDaFila(filaOeste, &aviao);
            inserirNaFila(filaPrincipal, aviao);
        }
        if (!filaVazia(filaNorte)) {
            removerDaFila(filaNorte, &aviao);
            inserirNaFila(filaPrincipal, aviao);
        }
        if (!filaVazia(filaSul)) {
            removerDaFila(filaSul, &aviao);
            inserirNaFila(filaPrincipal, aviao);
        }
        if (!filaVazia(filaLeste)) {
            removerDaFila(filaLeste, &aviao);
            inserirNaFila(filaPrincipal, aviao);
        }
    }

    while (!filaVazia(filaPrincipal)) {
        removerDaFila(filaPrincipal, &aviao);
        printf("%s", aviao);
        if (!filaVazia(filaPrincipal)) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    destruirFila(filaLeste);
    destruirFila(filaOeste);
    destruirFila(filaSul);
    destruirFila(filaNorte);
    destruirFila(filaPrincipal);
    
    return 0;
}

TipoFila criarFila(int capacidadeMax) {
    if (capacidadeMax < 1) {
        return NULL;
    }

    TipoFila fila = malloc(sizeof(struct EstruturaFila));
    if (fila != NULL) {
        fila->fim = -1;
        fila->capacidade = capacidadeMax;
        fila->elementos = malloc(sizeof(TipoElemento) * fila->capacidade);
        if (fila->elementos == NULL) {
            free(fila);
            fila = NULL;
        }
    }

    return fila;
}

void destruirFila(TipoFila fila) {
    for (int i = 0; i <= fila->fim; i++) {
        free(fila->elementos[i]);
    }
    free(fila->elementos);
    free(fila);
}

bool filaCheia(TipoFila fila) {
    return fila != NULL && fila->fim == fila->capacidade - 1;
}

bool filaVazia(TipoFila fila) {
    return fila != NULL && fila->fim == -1;
}

bool inserirNaFila(TipoFila fila, TipoElemento elemento) {
    if (fila == NULL || filaCheia(fila)) {
        return false;
    }

    fila->fim += 1;
    fila->elementos[fila->fim] = malloc(strlen(elemento) + 1);
    if (fila->elementos[fila->fim] == NULL) {
        return false;
    }
    strcpy(fila->elementos[fila->fim], elemento);
    return true;
}

bool removerDaFila(TipoFila fila, TipoElemento* elemento) {
    if (fila == NULL || filaVazia(fila)) {
        return false;
    }

    *elemento = fila->elementos[0];

    for (int i = 0; i < fila->fim; i++) {
        fila->elementos[i] = fila->elementos[i + 1];
    }
    fila->fim -= 1;

    return true;
}
