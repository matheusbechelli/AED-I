#include <stdio.h>
#include <stdlib.h>

typedef struct NoFila {
    int valor;
    int operacoes;
    struct NoFila* proximo;
} NoFila;

typedef struct Fila {
    NoFila* inicio;
    NoFila* fim;
} Fila;

#define TAMANHO_HASH 10007

typedef struct NoHash {
    int valor;
    struct NoHash* proximo;
} NoHash;

NoHash* tabelaHash[TAMANHO_HASH];

void inicializaTabelaHash() {
    for (int i = 0; i < TAMANHO_HASH; i++) {
        tabelaHash[i] = NULL;
    }
}

void insereHash(int valor) {
    int indice = (valor % TAMANHO_HASH + TAMANHO_HASH) % TAMANHO_HASH; 
    
    NoHash* atual = tabelaHash[indice];
    while (atual != NULL) {
        if (atual->valor == valor) return; 
        atual = atual->proximo;
    }
    
    NoHash* novoNo = (NoHash*)malloc(sizeof(NoHash));
    novoNo->valor = valor;
    novoNo->proximo = tabelaHash[indice];
    tabelaHash[indice] = novoNo;
}

int contemHash(int valor) {
    int indice = (valor % TAMANHO_HASH + TAMANHO_HASH) % TAMANHO_HASH;
    
    NoHash* atual = tabelaHash[indice];
    while (atual != NULL) {
        if (atual->valor == valor) return 1;
        atual = atual->proximo;
    }
    return 0;
}

void liberaTabelaHash() {
    for (int i = 0; i < TAMANHO_HASH; i++) {
        NoHash* atual = tabelaHash[i];
        while (atual != NULL) {
            NoHash* temp = atual;
            atual = atual->proximo;
            free(temp);
        }
        tabelaHash[i] = NULL;
    }
}

void enfileira(Fila* f, int valor, int operacoes) {
    NoFila* novoNo = (NoFila*)malloc(sizeof(NoFila));
    novoNo->valor = valor;
    novoNo->operacoes = operacoes;
    novoNo->proximo = NULL;
    
    if (f->fim == NULL) {
        f->inicio = f->fim = novoNo;
    } else {
        f->fim->proximo = novoNo;
        f->fim = novoNo;
    }
}

NoFila* desenfileira(Fila* f) {
    if (f->inicio == NULL) return NULL;
    
    NoFila* temp = f->inicio;
    f->inicio = f->inicio->proximo;
    
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    
    return temp;
}

int filaVazia(Fila* f) {
    return f->inicio == NULL;
}

int resolve(int inicio, int objetivo) {
    Fila f = {NULL, NULL};
    inicializaTabelaHash();
    
    enfileira(&f, inicio, 0);
    insereHash(inicio);
    
    while (!filaVazia(&f)) {
        NoFila* atual = desenfileira(&f);
        int valorAtual = atual->valor;
        int operacoesAtuais = atual->operacoes;
        
        if (valorAtual == objetivo) {
            free(atual);
            while (!filaVazia(&f)) {
                NoFila* temp = desenfileira(&f);
                free(temp);
            }
            liberaTabelaHash();
            return operacoesAtuais;
        }
        
        int proximosValores[] = {
            valorAtual * 2,
            valorAtual * 3,
            valorAtual / 2,
            valorAtual / 3,
            valorAtual + 7,
            valorAtual - 7
        };
        
        for (int i = 0; i < 6; i++) {
            int proximoValor = proximosValores[i];
            if (!contemHash(proximoValor)) {
                enfileira(&f, proximoValor, operacoesAtuais + 1);
                insereHash(proximoValor);
            }
        }
        
        free(atual);
    }
    
    liberaTabelaHash();
    return -1;
}

int main() {
    int inicio, objetivo;
    scanf("%d %d", &inicio, &objetivo);
    printf("%d\n", resolve(inicio, objetivo));
    return 0;
}
