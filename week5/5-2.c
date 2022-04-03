#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 128
#define INF 999

// 조언
// 1. m이랑 t를 분리를 해서 일단 수정을 하시고
// 2. 입력 다 받고 출력이 될 수 있도록 하고
// 3. 행렬도 1부터 루프 돌아가게 수정을 하시는게 가독성이 더 좋을 것 같아요
void floyd(int n, const int W[][MAX], int D[][MAX], int P[][MAX]);
void arrayCopy(int n, const int W[][MAX], int D[][MAX]);
void path(int q, int r, int P[][MAX]);

int main(void) {
    int n, m, u, v, w, x, y, z;
    scanf("%d %d", &n, &m);

    int arr1[MAX][MAX];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            arr1[i][j] = INF;
        }
    }

    for (int i = 0; i < n; i++) {
        arr1[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        arr1[u - 1][v - 1] = w;
    }

    int arr2[MAX][MAX] = { 0, };
    int arr3[MAX][MAX] = { 0, };

    floyd(n, arr1, arr2, arr3);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr2[i][j] == INF) {
                printf("NONE ");
            }
            else {
                printf("%d ", arr2[i][j]);
            }
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr3[i][j]);
        }
        printf("\n");
    }

    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        scanf("%d %d", &y, &z);
        printf("%d ", y);
        path(y, z, arr3);
        printf("%d ", z);
        if (arr2[y - 1][z - 1] == INF)
            printf("NONE \n");
        else {
            printf("%d \n", arr2[y - 1][z - 1]);
        }
    }
}

void arrayCopy(int n, const int W[][MAX], int D[][MAX]) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            D[i][j] = W[i][j];
    }
}

void floyd(int n, const int W[][MAX], int D[][MAX], int P[][MAX]) {
    arrayCopy(n, W, D);
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if ((D[i][k] + D[k][j]) < D[i][j]) {
                    P[i][j] = k + 1;
                    D[i][j] = (D[i][k] + D[k][j]);
                }
}

void path(int q, int r, int P[][MAX]) {
    if (P[q - 1][r - 1] != 0) {
        path(q, P[q - 1][r - 1], P);
        printf("%d ", P[q - 1][r - 1]);
        path(P[q - 1][r - 1], r, P);
    }
}