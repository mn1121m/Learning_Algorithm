#include <iostream>
#include <vector>
using namespace std;

#define INF 999
typedef vector<vector<int> > matrix_t;

void floyd2(int n, matrix_t& W, matrix_t& D, matrix_t& P)
{
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= n; j++) {
            D[i][j] = W[i][j];
            P[i][j] = 0;
        }
    }
    for (int k = 1; k<= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }
            }
        }
    }
}

void path(matrix_t& P, int u, int v, vector<int>& p)
{
    int k = P[u][v];
    if (k != 0) {
        path(P, u, k, p);
        p.push_back(k);
        path(P, k, v, p);
    }
}
int main()
{
    int n, m, u, v, w, t, start, end;
    cin >> n;   
    cin >> m;   
    matrix_t W, D, P;
    vector<int> p(0);
    vector<vector<int> > T;  

    W.assign(n+1, vector<int> (n+1, INF));
    D.assign(n+1, vector<int> (n+1, INF));
    P.assign(n+1, vector<int> (n+1, 0));
    
    // 간선 정보 저장
    for (int i = 1; i <= m; i++) {
        cin >> u;
        cin >> v;
        cin >> w;
        W[u][v] = w;
    }
    
    for (int i = 1; i <= n; i++) {
        W[i][i] = 0;
    }
    
    cin >> t;
    T.assign(t, vector<int> (2));
    
    for (int i = 0; i < t; i++) {
        cin >> start;
        cin >> end;
        T[i][0] = start;
        T[i][1] = end;
    }
    
    floyd2(n, W, D, P);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << D[i][j];
            if(j != n)
                cout << " ";
        }
        cout << endl;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << P[i][j];
            if(j != n)
                cout << " ";
        }
        cout << endl;
    }
    
    for (int i = 0; i < t; i++) {
        start = T[i][0];
        end = T[i][1];

        if(D[start][end] == INF){
            cout << "NONE" << endl;
        }
        else{
            path(P, start, end, p);
            cout << start << " ";
            for (int j = 0; j < p.size(); j++) {
                cout << p[j] << " ";
            }
            cout << T[i][1] << endl;
            p.clear();
        }
    }
    return 0;
}
