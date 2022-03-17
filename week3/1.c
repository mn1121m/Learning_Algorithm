#include <stdio.h>

int main(void)
{
    int n, t1, t2, nextTerm;
    int max;

    t1 = 0, t2 = 1;
    //input n, max
    scanf("%d", &n);
    scanf("%d", &max);

    //print
    for(int i = 0; i <= n; i++) {
        if(i == 0) {
            // printf("%d", t1);
            // if(i != n) printf(" ");
        }
        else if(i == 1) {
            //printf("%d", t2);
            //if(i != n) printf(" ");
        }
        else {
            nextTerm = (t1 + t2) % max;
            //printf("%d", nextTerm);
            t1 = t2;
            t2 = nextTerm;
            //if(i != n) printf(" ");
        }
    }
    if(n == 0)  {
        printf("%d", t1);   //n == 0인 경우
    }else {
        printf("%d", t2);   //n번째 항
    }
    return 0;
}