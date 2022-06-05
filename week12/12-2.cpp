#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define MAX 100
#define INF 999

int u[MAX], v[MAX], w[MAX];
int W[MAX][MAX], P[MAX][MAX], D[MAX][MAX];
int n,m,minlength,minj=0;

void travel();
int minimum(int i, int A);
int isIn(int i, int A);
int diff(int A, int j);
int count(int A);
void tour(int v, int A);


int main()
{
    int cnt = 0;
    cin >> n >> m;
   
    int subset_size =1;
    subset_size = pow(2,n-1);
    //초기화
    for (int i = 0; i <= MAX; i++) 
        for (int j = 0; j <= MAX; j++) 
        {
            if (i == j) 
                W[i][j] = 0;
            else 
                W[i][j] = INF;
        }

    for (int i = 0; i < m; i++) 
    {
        cin>>u[i]>>v[i]>>w[i];
        W[u[i]][v[i]] = w[i];
    }
    
    travel();
    cout << minlength <<"\n";
    printf("1 ");
    tour(1, subset_size - 1);
    printf("1\n");
    
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
            if(D[i][j] != 0 && D[i][j] != INF )
                printf("%d %d %d\n",i,j,D[i][j]);
        
    
}

void travel()
{
    int i,j,k,A;
    int subset_size =1;
    subset_size = pow(2,n-1);
    for (i = 2; i <= n; i++) 
        D[i][0] = W[i][1];
    
    for (k = 1; k <= n - 2; k++) 
        for (A = 0; A < subset_size; A++) 
        {
            if (count(A) != k) continue;
            for (int i = 2; i <= n; i++) 
            {
                if (isIn(i, A)) continue;
                D[i][A] = minimum(i, A);
                P[i][A] = minj;
            }
        }
    
    A = subset_size - 1;
    D[1][A] = minimum(1, A);
    P[1][A] = minj;
    
    minlength = D[1][A];
}

int minimum(int i, int A)
{
    int value,minV = INF;
    for (int j = 2; j <= n; j++) 
    {
        if (!isIn(j, A)) 
            continue;
        value = W[i][j] + D[j][diff(A, j)];
        if (minV > value) 
        {
            minV = value;
            minj = j;
        }
    }
    return minV;
}

//A에 i가 포함되어 있는지 판별
int isIn(int i, int A)
{ 
    return (A & (1 << (i - 2))) != 0;
}

int diff(int A, int j)
{
    return (A & ~(1 << (j - 2)));
}

//A안의 1의 개수 리턴
int count(int A)
{   
    int cnt = 0;
    for (; A != 0; A >>= 1) 
        if (A & 1) 
            cnt++;
    return cnt;
}

//경로
void tour(int v, int A)
{
    
    int k = P[v][A];
    if ( k == 0) 
        return;
    if (A == 1)
        cout << k <<" ";
    else 
    {
        cout << k << " ";
        tour(k, diff(A, k));
    }
    

}

