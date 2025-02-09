#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cel{
	char nome[21];
	struct cel *seg;
};

typedef struct cel celula;

int repetido(char palavra[], celula *cabeca){
	celula *p;
	for(p = cabeca->seg; p != NULL; p = p->seg){
		if(strcmp(palavra, p->nome)==0)
			return 1;
	}
	return 0;
}

void insere(char y[], celula *p){
	celula *nova;
	nova = malloc(sizeof(celula));
	strcpy(nova->nome, y);
	nova->seg = NULL;
	while(p->seg != NULL){
		p = p->seg;
	}
	p->seg = nova;
}

void ordena(celula *cabeca){
	celula *atual, *prox;
	for(atual = cabeca->seg; atual != NULL; atual = atual->seg){
		for(prox = atual->seg; prox != NULL; prox = prox->seg){
			if(strcmp(atual->nome, prox->nome) > 0){
				char temp[21];
				strcpy(temp, atual->nome);
				strcpy(atual->nome, prox->nome);
				strcpy(prox->nome, temp);
			}
		}
	}
}

void imprima(celula *cabeca){
	celula *p;
	for(p = cabeca->seg; p != NULL; p = p->seg){
		if(p->seg == NULL)
			printf("%s\n", p->nome);
		else
			printf("%s ", p->nome);
	}
}

int main(){
	celula *cabeca = malloc(sizeof(celula));
	strcpy(cabeca->nome,"cabeca");
	cabeca->seg = NULL;
	
	int N, i;
	char lista[21000];
	char *item;
	
	scanf("%d", &N);
	
	for(i=0; i<=N; i++){
		gets(lista);
		
		item = strtok(lista, " ");
		while(item != NULL){
			if(repetido(item, cabeca) == 0){
				insere(item, cabeca);
			}
			item = strtok(NULL, " ");
		}
		
		ordena(cabeca);
		imprima(cabeca);
		
		celula *lixo;
		while(cabeca->seg != NULL){
			lixo = cabeca->seg;
			cabeca->seg = lixo->seg;
			free(lixo);
		}
	}
	
	free(cabeca);
}
