#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int> > matrix_t;
void matrixmult(int n, int m, int k, matrix_t A, matrix_t B, matrix_t& C)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            C[i][j]=0;
            for(int l = 1; l <= k; l++)
                C[i][j] += A[i][l] * B[l][j];
        }
}
int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    matrix_t A(n+1, vector<int>(k+1));
    matrix_t B(k+1, vector<int>(m+1));
    matrix_t C(n+1, vector<int>(m+1));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=k; j++)
            cin>>A[i][j];
    for(int i=1; i<=k; i++)
        for(int j=1; j<=m; j++)
            cin>>B[i][j];
    matrixmult(n, m, k, A, B, C);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(j==m)
                cout<<C[i][j];
            else
                cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
