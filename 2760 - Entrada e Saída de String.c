#include <stdio.h>
#include <string.h>

int main() {
    char A[101], B[101], C[101];
  
    fgets(A, 101, stdin);
    fgets(B, 101, stdin);
    fgets(C, 101, stdin);

    A[strcspn(A, "\n")] = '\0';
    B[strcspn(B, "\n")] = '\0';
    C[strcspn(C, "\n")] = '\0';

    printf("%s%s%s\n", A, B, C);

    printf("%s%s%s\n", B, C, A);

    printf("%s%s%s\n", C, A, B);

    printf("%.10s%.10s%.10s\n", A, B, C);

    return 0;
}
