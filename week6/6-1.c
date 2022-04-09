#include <stdio.h>
#define MAX 17
#define INF 100000

// Functions
int minmult(int n, int d[], int P[][MAX], int M[][MAX]);
int minimum(int i, int j, int *minK, int M[][MAX], int d[MAX]);
void order(int i, int j, int P[][MAX]);



// Global variable
int P[MAX][MAX] = { 0, };
int M[MAX][MAX] = { 0, };
int arrD[MAX] = { 0, };

int optimum;


// Main
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num + 1; i++) {
		scanf("%d", &arrD[i]);
	}
	minmult(num, arrD, P, M);
	
	// M
	for (int i = 1; i < num; i++) {
		printf("0 ");
		for (int j = i+1; j <= num; j++) {
			printf("%d", M[i][j]);
			if (j < num) {
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("0\n");

	// P
	for (int i = 1; i < num; i++) {
		printf("0 ");
		for (int j = i+1; j <= num; j++) {
			printf("%d", P[i][j]);
			if (j < num) {
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("0\n");

	printf("%d\n", optimum);
	order(1, num, P);
}

int minmult(int n, int d[], int P[][MAX], int M[][MAX]) 
{
	int i, j, K, diagonal;
	for (i = 0; i <= n; i++)
		M[i][i] = 0;
	for (diagonal = 1; diagonal <= n - 1; diagonal++)
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;
			M[i][j] = minimum(i, j, &K, M, d);
			P[i][j] = K;
		}
	return M[1][n];
}


int minimum(int i, int j, int *minK, int M[][MAX], int d[MAX]) 
{
	int minV = INF;
	for (int k = i; k <= j - 1; k++) {
		int value = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
		if (minV > value) {
			minV = value;
			*minK = k;
		}
	}
	optimum = minV;
	return minV;
}

void order(int i, int j, int P[][MAX]) 
{
	if (i == j)
		printf("(A%d)", i);
	else {
		int k = P[i][j];
		printf("(");
		order(i, k, P);
		order(k + 1, j, P);
		printf(")");
	}
}