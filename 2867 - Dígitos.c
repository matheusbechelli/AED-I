#include <stdio.h>
#include <math.h>

int main() {
    int C, N, M;
    scanf("%d", &C);

    for (int i = 0; i < C; i++) {
        scanf("%d %d", &N, &M);
        int digitos = (int)(M * log10(N)) + 1;
        printf("%d\n", digitos);
    }

    return 0;
}
