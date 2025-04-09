#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int parent[MAX_N + 1];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void union_sets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY)
        parent[rootX] = rootY;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        union_sets(a, b);
    }

    int X;
    scanf("%d", &X);

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (find(i) == find(X)) {
            count++;
        }
    }

    printf("%d\n", count - 1);

    return 0;
}
