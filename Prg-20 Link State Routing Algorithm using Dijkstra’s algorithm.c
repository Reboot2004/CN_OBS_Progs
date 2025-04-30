#include <stdio.h>
#define INF 9999
int main() {
    int n, g[10][10], d[10], v[10] = {0}, src;
    printf("Enter the number of routers: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    printf("Enter the source router (0 to %d): ", n - 1);
    scanf("%d", &src);
    for (int i = 0; i < n; i++) d[i] = INF;
    d[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        int u = -1, min = INF;
        for (int j = 0; j < n; j++)
            if (!v[j] && d[j] < min) min = d[j], u = j;
        v[u] = 1;
        for (int j = 0; j < n; j++)
            if (g[u][j] && !v[j] && d[u] + g[u][j] < d[j])
                d[j] = d[u] + g[u][j];
    }
    printf("Router    Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d         %d\n", i, d[i]);
    return 0;
}
/*
Output:
Enter the number of routers: 3
Enter the cost matrix:
0 1 0
0 0 1
1 0 0
Enter the source router (0 to 2): 0
Router    Distance from Source
0         0
1         1
2         2
*/