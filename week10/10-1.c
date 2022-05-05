
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 128
#define MAX1 1028

// Global variable
int n;
int col[MAX] = { 0, };
int arr[MAX1] = {0, };
int count = 0;


// Functions
void queens(int i, int n);
void printResult();
int abs(int n);
bool promising(int i);


// Main
int main(void) {

	int max = 0;

	scanf("%d", &n);

	//queens
	queens(0, n);
	
	//print count, max
	printf("%d\n", count);	// possible number of board 
	
	return 0;
}

// Functions
void queens(int i, int n) {
	int j;

	if (promising(i)) {
		if (i == n) {
			printResult();
			count++;
		}
		else
			for (j = 1; j <= n; j++) {
				col[i + 1] = j;
				queens(i + 1, n);
			}
	}
}

// review ()
void printResult() {
	int i;
	
	printf("result : ");
	for(i = 1; i <= n; i++) {
		printf("%d", col[i]);
	}
	printf("\n");
}

bool promising(int i) {
	int k = 1;
	bool flag = true;
	while (k < i && flag) {
		if ((col[i] == col[k]) || (abs(col[i] - col[k]) == i - k))
			flag = false;
		k++;
	}
	return flag;
}

int abs(int n) {
	if (n > 0) {
		return n;
	}
	else
		return -n;
}


