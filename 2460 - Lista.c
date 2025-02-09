#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
	int identificador;
	struct cel *seg;
} celula;

void insere(int y, celula *p, celula **ultimo){
	celula *nova;
	nova = malloc(sizeof(celula));
	nova->identificador = y;
	nova->seg = NULL;
	(*ultimo)->seg = nova;
	*ultimo = nova;
}

void busca_remove(int x, celula *lst){
	celula *p, *q;
	p = lst;
	q = lst->seg;
	while(q != NULL && q->identificador != x){
		p = q;
		q = q->seg;
	}
	if(q != NULL){
		p->seg = q->seg;
		free(q);
	}
}

void imprima(celula *lst){
	celula *p;
	for(p = lst->seg; p != NULL; p = p->seg){
		if(p->seg == NULL){
			printf("%d\n", p->identificador);
		}
		else{
			printf("%d ", p->identificador);
		}
	}
}

int main(){
	celula *cabeca = malloc(sizeof(celula));
	cabeca->seg = NULL;
	celula *ultimo = cabeca;
	
	int N, M, ident, i;
	
	scanf("%d", &N);
	
	for(i=0; i<N; i++){
		scanf("%d", &ident);
		insere(ident, cabeca, &ultimo);
	}
	
	scanf("%d", &M);
	
	for(i=0; i<M; i++){
		scanf("%d", &ident);
		busca_remove(ident, cabeca);
	}
	
	imprima(cabeca);
}
