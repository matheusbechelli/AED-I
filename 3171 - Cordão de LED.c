#include <stdio.h>

void dfs(int v, int adj[][100], int visited[], int N) {
    visited[v] = 1;
    for (int i = 1; i <= N; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i, adj, visited, N);
        }
    }
}

int main() {
    int N, L;
    scanf("%d %d", &N, &L);

    int adj[100][100] = {0};
    int visited[100] = {0};
  
    for (int i = 0; i < L; i++) {
        int X, Y;
        scanf("%d %d", &X, &Y);
        adj[X][Y] = 1;
        adj[Y][X] = 1;
    }

    dfs(1, adj, visited, N);

    int completo = 1;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            completo = 0;
            break;
        }
    }

    if (completo) {
        printf("COMPLETO\n");
    } else {
        printf("INCOMPLETO\n");
    }

    return 0;
}
