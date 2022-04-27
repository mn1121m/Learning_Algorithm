#include<stdio.h>
#include<stdlib.h>

#define INF 1024
#define MAX 128


// Global variable
int G[MAX][MAX], n, F[MAX][MAX];


// Function
void prims();


// Main
int main(){
    int i, j, total_cost, m;
    // input: 정점의 개수 n, 간선의 개수 m
    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            G[i][j] = 0;
        }
    }
    // input: u v w
    int num1, num2, num3;
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &num1, &num2, &num3);
        G[num1 - 1][num2 - 1] = num3;
        G[num2 - 1][num1 - 1] = num3;
    }
    // prim()
    prims();
    // 이후로, 프림 알고리즘 F 집합에 포함되는 간선을 순서대로 출력
    for (i = 0; i < n - 1; i++) {
        printf("%d %d %d\n", F[i][0], F[i][1], F[i][2]);
    }
    return 0;
}


// Function
void prims()
{
    int arr[MAX][MAX];
    int u, v, min, distance[MAX], nearest[MAX];
    int temp[MAX], i, j;

    for(i = 0; i < 4; i++) {
        nearest[i] = 1;
        printf("%d", nearest[i]);
        if( i == 4) 
            break;
        else 
            printf(" ");
    }
    printf("\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
                arr[i][j] = INF;
            else
                arr[i][j] = G[i][j];
        }
    distance[0] = 0;
    temp[0] = 1;

    for (i = 1; i < n; i++)
    {
        distance[i] = arr[0][i];
        nearest[i] = 1;
        temp[i] = 0;
    }

    
    for (int z = 0; z < n-1; z++)
    {
        min = INF;
        for (i = 1; i < n; i++)
            if (temp[i] == 0 && distance[i] < min)
            {
                v = i;
                min = distance[i];
            }

        u = nearest[v];
        
        F[z][0] = v+1;
        F[z][1] = u;
        F[z][2] = G[v][u-1];

        temp[v] = 1;

        for (i = 1; i < n; i++)
            if (temp[i] == 0 && arr[i][v] < distance[i])
            {
                distance[i] = arr[i][v];
                nearest[i] = v + 1;
            }
        distance[v] = -1;

        for (i = 1; i < n-1; i++) {
            printf("%d ", nearest[i]);
        }
        printf("%d\n", nearest[n - 1]);
    }
}
