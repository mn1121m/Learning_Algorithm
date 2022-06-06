#include <iostream>
#include <vector>
#include <math.h>

const int INF = 999;
using namespace std;

typedef vector<vector<int>> matrix_t;
vector<int> visit;

int count(int A)
{
    int cnt = 0;
    for(; A != 0; A >>= 1)
        if(A & 1)
            cnt++;
    return cnt;
}

bool isIn(int i, int A)
{
    return (A & (1 << (i - 2))) != 0;
}

int diff(int A, int j)
{
    return (A & ~(1 << (j - 2)));
}

void tour(int v, int A, matrix_t& P)
{
    int k = P[v][A];
    if (A == 0)
        cout << "1";
    else{
        cout << k << " ";
        tour(k, diff(A, k), P);
    }
}

int minimum(int n, int i, int &minJ, int A, matrix_t& W, matrix_t& D)
{
    int minV = INF;

    for(int j = 2; j <= n; j++)
    {
        if(!isIn(j, A))
            continue;
        int value = W[i][j] + D[j][diff(A, j)];
        if(minV > value)
        {
            minV = value;
            minJ = j;
        }
    }
    return minV;
}

void travel(int n, matrix_t& W, matrix_t& D, matrix_t& P, int& minlength)
{
    int i, j, k, A;
    
    int subset_size = pow(2, n - 1);
    for (i = 2; i <= n; i++)
        D[i][0] = W[i][1];
    for (k = 1; k <= n - 2; k++)
        for (A = 0; A < subset_size; A++){
            if(count(A) != k)
                continue;
            for (i = 2; i <= n; i++) {
                if (isIn(i, A))
                    continue;
                D[i][A] = minimum(n, i, j, A, W, D);
                P[i][A] = j;
            }
        }
    A = subset_size - 1;
    D[1][A] = minimum(n, 1, j, A, W, D);
    P[1][A] = j;
    minlength = D[1][A];
}

int main() {
    int n;   // 정점 개수
    int m;   // 간선 개수
    int u, v, w;
    int minlength;
    matrix_t W, D, P;
    
    cin >> n >> m;
    W.assign(n+1, vector<int>(n+1, INF));
    D.assign(n+1, vector<int>(pow(2, n - 1), INF));
    P.assign(n+1, vector<int>(pow(2, n - 1), INF));
    
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        W[u][v] = w;
    }
    
    for (int i = 1; i <= n; i++) {
        W[i][i] = 0;
    }
    
    travel(n, W, D, P, minlength);
    
    cout << minlength << endl;
    cout << "1 ";
    tour(1, pow(2, n-1) - 1, P);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < D[i].size(); j++)
        {
            if(D[i][j] < INF)
                cout << endl << i << " " << j << " " << D[i][j];
        }
    }
    return 0;
}
