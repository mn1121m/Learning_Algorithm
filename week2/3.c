/*
인덱스와 값이 같은 배열 원소 찾기

*/
#include <stdio.h>
#define MAX_ARY_SIZE 100

int binSearch(int *ary, int size, int  value);

int main()
{
    int n, ary[MAX_ARY_SIZE], cnt = 0;
    int key = 0;

    // input n개 , ary원소
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &ary[i]);
    }

    // 인덱스와 값이 같은 배열의 원소 찾기
    for(int i = 0; i < n; i ++) {
        if(ary[i] == i) {
            break;
        }
        else {
            key++;
        }
    }
    
    // 만약 인덱스와 값이 같지 않은 경우
    if(key == n) key = -1;
    printf("%d\n", key);

    // binSearch
    printf("%d\n", binSearch(ary, n, key));

    return 0;
}

int binSearch(int *ary, int size, int  value)
{
    int middle, left = 0, right = size - 1;
    int cnt = 0;
    while(left <= right) {
        cnt++;
        middle = (left + right) / 2;
        if(ary[middle] > value) right = middle -1;
        else if(ary[middle] == value) return cnt;
        else left = middle +1;
    }
    return cnt;
}