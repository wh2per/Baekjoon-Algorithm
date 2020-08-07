#include <cstdio>

using namespace std;

int main() {
    int a[1000001];
    int b[1000001];

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    int v = 0;
    int u = 0;
    while (v < n && u < m) {
        if (a[v] <= b[u]) {
            printf("%d ", a[v]);
            v += 1;
        }
        else {
            printf("%d ", b[u]);
            u += 1;
        }
    }
    while (v < n) {
        printf("%d ", a[v]);
        v += 1;
    }
    while (u < m) {
        printf("%d ", b[u]);
        u += 1;
    }
    printf("\n");
}

