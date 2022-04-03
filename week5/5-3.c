//ok
// #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 128


void Big(int N, int arr1[][MAX], int arr2[][MAX]);
void path(int N, int x, int y, int arr1[][MAX], int arr2[][MAX]);

int main(void) {
	int N, num;
	scanf("%d", &N);
	int arr1[MAX][MAX] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < i + 1; k++) {
			scanf("%d", &num);
			arr1[i][k] = num;
		}
	}
	int arr2[MAX][MAX] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			arr2[i][k] = 0;
		}
	}

	Big(N, arr1, arr2);
	printf("%d\n", arr2[0][0]);
	printf("%d ", arr1[0][0]);
	path(N, 0, 0, arr1, arr2);
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

void Big(int N, int arr1[][MAX], int arr2[][MAX]) {
	for (int i = N; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			arr2[i - 1][j] = arr1[i - 1][j] + max(arr2[i][j], arr2[i][j + 1]);
		}
	}
}

void path(int N, int x, int y, int arr1[][MAX], int arr2[][MAX]) {
	if (x <= N - 2)
	{
		if (arr2[x + 1][y] > arr2[x + 1][y + 1]) {
			printf("%d ", arr1[x + 1][y]);
			path(N, x + 1, y, arr1, arr2);
		}
		else {
			printf("%d ", arr1[x + 1][y + 1]);
			path(N, x + 1, y + 1, arr1, arr2);
		}
	}
}