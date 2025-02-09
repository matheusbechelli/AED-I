#include <stdio.h>
#include <stdlib.h>

struct cel {
    char caractere;
    struct cel *seg; 
};
typedef struct cel celula;

void Insere(char c, celula *lst) {
    celula *nova = malloc(sizeof(celula));
    nova->caractere = c;
    nova->seg = NULL;
    celula *p = lst;
    while (p->seg != NULL) {
        p = p->seg;
    }
    p->seg = nova;
}

void Remove(celula *lst) {
    celula *p = lst->seg;
    if (p != NULL) {
        lst->seg = p->seg;
        free(p);
    }
}

int Verifica(char *expressao) {
    celula *pilha = malloc(sizeof(celula));
    pilha->seg = NULL;

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            Insere('(', pilha);
        } else if (expressao[i] == ')') {
            if (pilha->seg != NULL) {
                Remove(pilha);
            } else {
                free(pilha);
                return 0;
            }
        }
    }
    
    int resultado = (pilha->seg == NULL);
    free(pilha);
    return resultado;
}

int main() {
    char expressao[1001];
    while (fgets(expressao, 1001, stdin) != NULL) {
        if (Verifica(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
