#include <stdio.h>
#define MAX 10
#define INF 9999
int main() {
    int n, cost[MAX][MAX], dist[MAX][MAX], next[MAX][MAX];
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = cost[i][j];
            next[i][j] = j;
        }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
    for (int i = 0; i < n; i++) {
        printf("Routing table for router %d:\n", i);
        for (int j = 0; j < n; j++)
            printf("To %d via %d cost %d\n", j, next[i][j], dist[i][j]);
        printf("\n");
    }
    return 0;
}
/*
output:
Enter number of nodes: 2
Enter cost matrix:
1 2
3 4
Routing table for router 0:
To 0 via 0 cost 0
To 1 via 1 cost 2
Routing table for router 1:
To 0 via 0 cost 3
To 1 via 1 cost 0
*/