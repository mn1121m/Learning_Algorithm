//2018117610 moonjunyong

#include <stdio.h>
#include <stdlib.h>
#define MAX 128


// Data structure
typedef struct edge {
    int u, v, w;
} edge;

typedef struct edge_list {
    edge data[MAX];
    int n;
} edge_list;

edge_list E;


// Global variable
int Graph[MAX][MAX], n;
edge_list F;


// Functions
void kruskal();
int find(int U[], int num);
void initial(int U[], int c1, int c2);
void sort();


// Main
int main(){
    int i, j;

    int m;
    scanf("%d %d", &n, &m);
    int num1, num2, num3;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            Graph[i][j] = 0;
        }
    }
    for (int k = 0; k < m; k++) {
        scanf("%d %d %d", &num1, &num2, &num3);
        Graph[num1 - 1][num2 - 1] = num3;
        Graph[num2 - 1][num1 - 1] = num3;
    }
    
    kruskal();

    for (i = 0; i < F.n; i++) {
        printf("%d %d %d\n", F.data[i].v + 1, F.data[i].u + 1, F.data[i].w);
    }
}

// Functions
void kruskal(){
    int U[MAX], i, j, cno1, cno2;
    E.n = 0;

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++) {
            if (Graph[i][j] != 0) {
                E.data[E.n].u = i;
                E.data[E.n].v = j;
                E.data[E.n].w = Graph[i][j];
                E.n++;
            }
        }

    sort();

    for (i = 0; i < n; i++)
        U[i] = i;

    F.n = 0;

    for (i = 0; i < E.n; i++) {
        cno1 = find(U, E.data[i].u);
        cno2 = find(U, E.data[i].v);

        if (cno1 != cno2) {
            F.data[F.n] = E.data[i];
            F.n = F.n + 1;
            initial(U, cno1, cno2);
        }
    }
}

int find(int U[], int num){
    return (U[num]);
}

void initial(int U[], int c1, int c2){
    int i;

    for (i = 0; i < n; i++)
        if (U[i] == c2)
            U[i] = c1;
}


void sort(){
    int i, j;
    edge temp;

    for (i = 1; i < E.n; i++)
        for (j = 0; j < E.n - 1; j++)
            if (E.data[j].w > E.data[j + 1].w) {
                temp = E.data[j];
                E.data[j] = E.data[j + 1];
                E.data[j + 1] = temp;
            }
}