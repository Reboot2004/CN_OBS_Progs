#include <stdio.h>
#define INF 9999
int main() {
    int n, g[10][10], d[10], v[10] = {0}, src;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &g[i][j]);
        }
    }
    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);
    for (int i = 0; i < n; i++) {
        d[i] = INF;
    }
    d[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        int u = -1, min = INF;
        for (int j = 0; j < n; j++){
            if (!v[j] && d[j] < min){
                min = d[j], u = j;
            }
        }
        v[u] = 1;
        for (int j = 0; j < n; j++){
            if (g[u][j] && d[u] + g[u][j] < d[j]){
                d[j] = d[u] + g[u][j];
            }
        }
    }
    printf("Vertex    Distance from Source\n");
    for (int i = 0; i < n; i++){
        printf("%d         %d\n", i, d[i]);
    }
    return 0;
}
/*
output
Enter the number of vertices: 3
Enter the adjacency matrix:
1 2 3
0 1 0
0 0 1
Enter the source vertex (0 to 2): 0
Vertex    Distance from Source
0         0
1         2
2         3
*/