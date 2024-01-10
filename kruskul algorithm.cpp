#include <stdio.h>
#include <stdlib.h>
struct Edge {
    int src, dest, weight;
};
struct Subset {
    int parent;
    int rank;
};
int compareEdges(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
void kruskalMST(struct Edge *edges, int V, int E) {
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    qsort(edges, E, sizeof(edges[0]), compareEdges);
    struct Edge *result = (struct Edge *)malloc((V - 1) * sizeof(struct Edge));

    int i = 0;
    while (i < V - 1 && edges[i].weight >= 0) {
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y) {
            result[i - 1] = next_edge;
            Union(subsets, x, y);
        }
    }
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int j = 0; j < V - 1; j++)
        printf("%d -- %d == %d\n", result[j].src, result[j].dest, result[j].weight);

    free(subsets);
    free(result);
}

int main() {
    int V = 4, E = 5;
    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(edges, V, E);

    return 0;
}

