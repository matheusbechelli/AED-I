#include <stdio.h>
#define TAM 9

void zerar(int *dg) {
  int i;
  for (i = 0; i < TAM; i++) 
    dg[i] = 0;
  }


int valida(int v[TAM][TAM], int flag, int *dg) {
  int i, j;
  for (i = 0; i < TAM; i++) {
    for (j = 0; j < TAM; j++) {
      if (flag) {
dg[v[i][j]]++;
        if (dg[v[i][j]] > 1) 
          return 1;
      }
        else {
          dg[v[j][i]]++;
          if (dg[v[j][i]] > 1)
            return 1;
        }
      }
      zerar(dg);
    
  }
  return 0;
}

int validaSubMatriz(int v[TAM][TAM], int lInicio, int lfim, int cInicio,int cFim, int *dg) {
  int i, j;
  for (i = lInicio; i < lfim; i++) {
    for (j = cInicio; j < cFim; j++) {
      dg[v[j][i]]++;
      if (dg[v[j][i]] > 1) 
        return 1;
      
    }
  }
  zerar(dg);
  return 0;
}

int main(void) {
int n, mat[TAM][TAM], invalid, digits[TAM], cases, i, j;
  scanf("%i", &n);
for (cases = 1; cases <= n; cases++) {
  for (i = 0; i < TAM; i++) {
zerar(digits);
    for (j = 0; j < TAM; j++) {
      scanf("%i", &mat[i][j]);
    mat[i][j]--;
    }
  }
  invalid = valida(mat, 1, digits) + valida(mat, 0, digits);
         for (i = 0; i < TAM; i+=3)
            for (j = 0; j < TAM; j+=3)
        invalid += validaSubMatriz(mat, i, i + 3, j, j + 3, digits);

  printf("Instancia %i\n", cases);

  if (invalid)
      printf("NAO\n\n");
  else
      printf("SIM\n\n");
  
  
}  
  return 0;
}
