/*
배열에서 가장 큰 수와 가장 작은 수 찾기

Description

주어진 배열에서 가장 큰 수와 가장 작은 수를 출력하라.


Input
입력의 첫 줄에는 배열의 원소 개수 n이 주어진다. (1 <= n <= 1000)

입력의 둘째 줄에는 n개의 배열 원소 m[i]가 주어진다.

배열 원소는 모두 양의 정수라고 가정해도 된다. (1 <= m[i] <= 10000)


Output
출력의 첫 줄에는 배열에서 가장 작은 원소 smallest를 출력한다.

출력의 두번째 줄에는 배열에서 가장 큰 원소 largest를 출력한다.
*/

#include <stdio.h>

int main()
{
    int n; // n: 배열의 원소 개수, m: 배열의 원소
    int m[10000];

    int min, max;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m[i]);
    }

    min = m[0];
    max = m[0];

    for(int i = 0; i < n; i++) {
        if(m[i] > max) {
            max = m[i];
        }
        if(m[i] < min) {
            min = m[i];
        }
    }
    printf("%d\n", min);
    printf("%d\n", max);

    return 0;
}