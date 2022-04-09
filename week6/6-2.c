#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20
#define INF 9999999


// Data structure
typedef struct node* node_pointer;
typedef struct node {
	int key;
	node_pointer left;
	node_pointer right;
} nodetype;


// Global variable
int A[MAX][MAX] = { 0, };
int R[MAX][MAX] = { 0, };
int p[MAX];

int optsearchtreeV = 0;
int minV = 0;
int optimum = 0; // optsearchtreeV + minV


// Functions
void optsearchtree(int n, int arrp[], int R[][MAX]);
int minimum(int i, int j, int* minK, int A[][MAX]);
node_pointer tree(int i, int j, int R[][MAX], int keys[MAX]);
void inorder(node_pointer p);
void preorder(node_pointer p);


// Main
int main()
{
	node_pointer ptk;
	int num;
	scanf("%d", &num);
	int arrK[MAX] = { 0, };
	for (int i = 1; i <= num; i++) {
		scanf("%d", &arrK[i]);
	}
	for (int i = 1; i <= num; i++) {
		scanf("%d", &p[i]);
	}

	optsearchtree(num, p, R);

    // First print the upper triangle of matrix A
	for (int i = 1; i <= num; i++) {
        printf("0 ");
		for (int j = i; j <= num; j++) {
			printf("%d", A[i][j]);
			if (j < num) {
				printf(" ");
			}
		}
		printf("\n");
	}
    printf("0\n");

    // Next, print the upper triangle of the matrix R. (including 0)
	for (int i = 1; i <= num; i++) {
        printf("0 ");
		for (int j = i; j <= num; j++) {
			printf("%d", R[i][j]);
			if (j < num) {
				printf(" ");
			}
		}
		printf("\n");
	}
    printf("0\n");

    // After outputting A and R, output the optimal value of the average search time in the optimal binary search tree.
    // printf("optsearchtreeV : %d\t minv: %d\n", optsearchtreeV, minV);
    optimum = optsearchtreeV + minV;
    printf("%d\n", optimum);

	ptk = tree(1, num, R, arrK);
	preorder(ptk);      // print preorder
	printf("\n");
	inorder(ptk);       // print inorder
}

void optsearchtree(int n, int arrp[], int R[][MAX]) 
{
	int i, j, k, diagonal;
	int sum = 0;
	for (i = 1; i <= n; i++) {
		A[i][i] = arrp[i]; A[i][i - 1] = 0;
		R[i][i] = i; R[i][i - 1] = 0;
	}
	A[n + 1][n] = 0;
	R[n + 1][n] = 0;
	for (diagonal = 1; diagonal <= n - 1; diagonal++) {
		for (i = 1; i <= n - diagonal; i++) {
			sum = 0;
			j = i + diagonal;
				for (int m = i; m <= j; m++) {
					sum += arrp[m];
				}

			A[i][j] = minimum(i, j, &k, A) + sum;
			R[i][j] = k;
		}
    optsearchtreeV = sum;
    }
}

int minimum(int i, int j, int* minK, int A[][MAX]) 
{
    minV = INF;
	for (int k = i; k <= j; k++) {
		int value = A[i][k-1] + A[k + 1][j];
		if (minV > value) {
			minV = value;
			*minK = k;
		}
	}
	return minV;
}

node_pointer tree(int i, int j, int R[][MAX], int keys[MAX]) 
{
	int k;
	node_pointer p;
	k = R[i][j];
	if (k == 0)
		return NULL;
	else {
		p = (node_pointer)malloc(sizeof(nodetype));
		p->key = keys[k];
		p->left = tree(i, k - 1, R, keys);
		p->right = tree(k + 1, j, R, keys);
		return p;
	}
}

void inorder(node_pointer p) 
{
	if (p) {
		if (p->left) {
			inorder(p->left);
			printf(" ");
		}
		printf("%d", p->key);
		if (p->right) {
			printf(" ");
			inorder(p->right);
		}
	}
}

void preorder(node_pointer p) 
{
	if (p) {
		printf("%d", p->key);
		if (p->left) {
			printf(" ");
			preorder(p->left);
		}
		if (p->right) {
			printf(" ");
			preorder(p->right);
		}
	}
}