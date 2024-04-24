#include <stdio.h>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int c[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    int k;
    scanf("%d", &k);
    char t;
    int a, b;
    for (int i = 0; i < k; i++) {
        scanf("%c", &t);
        scanf("%d%d", &a, &b);
        if (t == 'c') {
            for (int j = 0; j < m; j++) {
                int p;
                p = c[j][a];
                c[j][a] = c[j][b];
                c[j][b] = p;
            }
        }
        if (t == 'r') {
            for (int j = 0; j < n; j++) {
                int p;
                p = c[a][j];
                c[a][j] = c[b][j];
                c[b][j] = p;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }

}