#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selecao(int n, char v[][21]){
	int i, j, min, r;
	char x[21];
	for(i=0; i<n-1; i++){
		min = i;
		for(j=i+1; j<n; j++){
			r = strcmp(v[j], v[min]);
			if(r < 0){
				min = j;
			}
		}
		strcpy(x, v[i]);
		strcpy(v[i], v[min]);
		strcpy(v[min], x);
	}
}

int main(){
	int N, K, posicao;
	
	scanf("%d %d", &N, &K);
	
	char alunos[N][21];
	
	for(posicao=0; posicao<N; posicao++){
		scanf("%s", alunos[posicao]);
	}
	
	selecao(N, alunos);
	
	printf("%s\n", alunos[K-1]);
}
