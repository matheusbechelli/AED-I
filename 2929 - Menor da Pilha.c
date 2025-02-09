#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha {
  int *dados;
  int *minimos;
  int topo;
  int capacidade;
} Pilha;

void Inicializar(Pilha *pilha, int capacidade) {
  pilha->dados = (int *)malloc(capacidade * sizeof(int));
  pilha->minimos = (int *)malloc(capacidade * sizeof(int));
  pilha->topo = -1;
  pilha->capacidade = capacidade;
}

int EstaVazia(Pilha *pilha) { return pilha->topo == -1; }

int ObterMinimo(Pilha *pilha) {
  if (pilha->topo == -1) {
    return -1;
  }
  return pilha->minimos[pilha->topo];
}

int Desempilhar(Pilha *pilha) {
  if (pilha->topo == -1) {
    return -1;
  }
  return pilha->dados[pilha->topo--];
}

void Empilhar(Pilha *pilha, int valor) {
  if (pilha->topo == pilha->capacidade - 1) {
    pilha->capacidade *= 2;
    pilha->dados = (int *)realloc(pilha->dados, pilha->capacidade * sizeof(int));
    pilha->minimos = (int *)realloc(pilha->minimos, pilha->capacidade * sizeof(int));
  }
  pilha->dados[++pilha->topo] = valor;
  if (pilha->topo == 0) {
    pilha->minimos[pilha->topo] = valor;
  } else {
    if (valor < pilha->minimos[pilha->topo - 1]) {
      pilha->minimos[pilha->topo] = valor;
    } else {
      pilha->minimos[pilha->topo] = pilha->minimos[pilha->topo - 1];
    }
  }
}

void LiberarPilha(Pilha *pilha) {
  free(pilha->dados);
  free(pilha->minimos);
}

int main() {
  Pilha pilha;
  int numOperacoes, valor;
  char comando[10];

  scanf("%d", &numOperacoes);
  Inicializar(&pilha, numOperacoes);

  for (int i = 0; i < numOperacoes; i++) {
    scanf("%s", comando);
    if (comando[1] == 'U') {
      scanf("%d", &valor);
      Empilhar(&pilha, valor);
    } else if (comando[1] == 'O') {
      if (EstaVazia(&pilha)) {
        printf("EMPTY\n");
      } else {
        Desempilhar(&pilha);
      }
    } else if (comando[1] == 'I') {
      int minimo = ObterMinimo(&pilha);
      if (minimo == -1) {
        printf("EMPTY\n");
      } else {
        printf("%d\n", minimo);
      }
    }
  }
  LiberarPilha(&pilha);
  return 0;
}
