#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int src, dest, weight;
};

struct Edge edges[MAX];
int parent[MAX], n, e;

int find(int v) {
    if (parent[v] == v)
        return v;
    return find(parent[v]);
}

void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    parent[rootU] = rootV;
}

void kruskal() {
    struct Edge mst[MAX];
    int i, mstCount = 0, mstWeight = 0;

    for (i = 0; i < n; i++)
        parent[i] = i;

    for (i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < e; i++) {
        if (find(edges[i].src) != find(edges[i].dest)) {
            mst[mstCount++] = edges[i];
            mstWeight += edges[i].weight;
            unionSets(edges[i].src, edges[i].dest);
        }
    }

    printf("Edges in the MST:\n");
    for (i = 0; i < mstCount; i++)
        printf("%d -- %d == %d\n", mst[i].src, mst[i].dest, mst[i].weight);
    printf("Total weight: %d\n", mstWeight);
}

int main() {
    int i;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (source, destination, weight):\n");
    for (i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);

    kruskal();
    return 0;
}

#Enter the number of vertices: 4
#Enter the number of edges: 5
#Enter edges (source, destination, weight):
#0 1 10
#0 2 6
#0 3 5
#1 3 15
#2 3 4

