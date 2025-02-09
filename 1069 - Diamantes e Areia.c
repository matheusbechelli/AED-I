#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int n;
    scanf("%d", &n);
    getchar();

    for (int i =0; i<n; i++){
        int diamantes = 0;
        int aberto = 0;
        char vetor[1001];  
        fgets(vetor, 1001, stdin);  

        for (int k = 0; vetor[k] != '\n'; k++) {
            if (vetor[k] == '<') {
                aberto++;
            } else if (vetor[k] == '>') {
                if (aberto > 0) {
                    diamantes++;
                    aberto--;
                }
            }
        }
        printf("%d\n", diamantes);
    }
}
