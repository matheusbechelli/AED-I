#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

int compare(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->weight - edgeB->weight;
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);

    if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    } else if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
    } else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

int main() {
    int m, n;

    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) {
            break;
        }

        Edge edges[n];
        int totalCost = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
            totalCost += edges[i].weight;
        }

        qsort(edges, n, sizeof(Edge), compare);

        int parent[m], rank[m];
        for (int i = 0; i < m; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        int mstCost = 0;
        int edgeCount = 0;

        for (int i = 0; i < n && edgeCount < m - 1; i++) {
            int u = edges[i].u;
            int v = edges[i].v;
            int weight = edges[i].weight;

            int setU = find(parent, u);
            int setV = find(parent, v);

            if (setU != setV) {
                mstCost += weight;
                unionSets(parent, rank, setU, setV);
                edgeCount++;
            }
        }

        int maxSavings = totalCost - mstCost;
        printf("%d\n", maxSavings);
    }

    return 0;
}
