// 2018117610 moonjunyong

/*
이후에 정점의 개수 T가 주어진다.

이후에 T개의 정점 번호가 주어진다.

(1번 정점이 주어지는 경우는 없다고 가정해도 된다)
*/

/*
이후로, 다익스트라 알고리즘의 F 집합에 포함되는 간선을 순서대로 출력한다.

이후로, T개의 정점 v에 대해서

1번 정점으로부터 정점 v로 가는 최단 경로를 출력한다.
*/
#include<stdio.h>
#include<stdlib.h>

#define INF 1024
#define MAX 128


// Global varible
int G[MAX][MAX], n, F[MAX][MAX];

// Function
void dijkstra();

// Main
int main() {
    int i, j, total_cost, m;
    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            G[i][j] = 0;
        }
    }
    
    int num1, num2, num3;
    for (i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &num1, &num2, &num3);
        G[num1 - 1][num2 - 1] = num3;
    }

    dijkstra();

    for (i = 0; i < n - 1; i++) {
        printf("%d %d %d\n", F[i][0], F[i][1], F[i][2]);
    }
    return 0;
}


// Function
void dijkstra()
{
    int arr[MAX][MAX];
    int u, v = 0, min, length[MAX], touch[MAX];
    int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
                arr[i][j] = INF;
            else
                arr[i][j] = G[i][j];
        }
    length[0] = -1;

    for (i = 1; i < n; i++)
    {
        length[i] = arr[0][i];
        touch[i] = 1;
    }

    for (int z = 0; z < n - 1; z++)
    {
        min = INF;
        for (i = 1; i < n; i++)
            if (0 <= length[i] && length[i] < min)
            {
                v = i;
                min = length[i];
            }

        u = touch[v];

        F[z][0] = u;
        F[z][1] = v + 1;
        F[z][2] = G[u-1][v];

        for (i = 1; i < n; i++)
            if (arr[v][i]+length[v] < length[i])
            {
                length[i] = length[v]+arr[v][i];
                touch[i] = v + 1;
            }
        length[v] = -1;

        for (i = 1; i < n - 1; i++) {
            printf("%d ", touch[i]);
        }
        printf("%d", touch[n - 1]);
        printf("\n");
    }
}
