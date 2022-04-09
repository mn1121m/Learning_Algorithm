/*
두 행렬의 곱셈

Description

주어진 두 개의 행렬을 곱하시오.

*** 주의 ***

답안 출력시에 공백 문자가 마지막에 추가되지 않도록 주의하시오. (OutputDescription참고)


Input
입력의 첫 줄에는 두 행렬 A, B의 차원 n, k, m이 주어진다.

이후에는 (n * k) 행렬 A의 원소와 (k * m) 행렬 B의 원소가 주어진다.


Output
두 행렬을 곱한 n * m 행렬 C를 출력한다.

행렬을 출력할 때 각 행의 마지막에는 개행 문자를 출력한다.

*/

#include <stdio.h>

int main(void)
{
    // A(n, k) B(k, m) => C(n, m)
    int A[100][100], B[100][100], C[100][100];
    int n, k, m;
    // input n, m, k
    scanf("%d %d %d", &n, &k, &m);

    // get array A
   for(int i = 0; i < n; i++) {
       for(int j = 0; j < k; j++) {
            scanf("%d", &A[i][j]);
       }
   }

    // get array B
   for(int i = 0; i < k; i++) {
       for(int j = 0; j < m; j++) {
            scanf("%d", &B[i][j]);
       }
   }
    // get array C
    for(int i = 0; i < n; i++) {
       for(int j = 0; j < k; j++) {
            for(int k = 0; k < m; k++) {
                C[i][k] += A[i][j] * B[j][k];
            }
       }
   }
   // print array C
   for(int i = 0; i < n; i++) {
       for(int j = 0; j < m; j++) {
            printf("%d", C[i][j]);
            if(j == m-1) break; //개행문자 앞에 공백이 없기 위한 조건
            printf(" ");
       }
        printf("\n"); 
   }

    return 0;
}
