// 2018117610 문준용
// #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000000

int A[50001] = { 0, };
int i = 0;

int bin2(int n, int k) {
	A[0] = 1;
	for (; i < n; i++) {
		for (int j = n; j > 0; j--) {
			A[j] = (A[j] + A[j - 1]) % MAX;
		}
	}
	return A[k];
}

int main()
{
	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int n, k;
		n = 0, k = 0;
		scanf("%d %d", &n, &k);
		printf("%d\n", bin2(n, k));
	}
	return 0;
}
