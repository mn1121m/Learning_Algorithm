#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int> > matrix_t;

void triangle(int n, int& maxSum, matrix_t& T, matrix_t& D, vector<int>& r)
{
    maxSum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i+1; j++) {
            if(i==0){
                D[i][j] = T[0][0];
            }
            else if(i==1){
                D[i][j] = D[0][0] + T[i][j];
            }
            else if(j==0){
                D[i][j] = D[i-1][j] + T[i][j];
            }
            else if(j==i){
                D[i][j] = D[i-1][j-1] + T[i][j];
            }
            else{
                if(D[i-1][j] >= D[i-1][j-1]){
                    D[i][j] = D[i-1][j] + T[i][j];
                    //r[i-1] = T[i-1][j];
                }
                else{
                    D[i][j] = D[i-1][j-1] + T[i][j];
                    //r[i-1] = T[i-1][j-1];
                }
            }
        }
    }
    maxSum = D[n-1][0];
    int k = 0, m = 0;
    for (k = 1; k < n; k++) {
        if(D[n-1][k] >= maxSum){
            maxSum = D[n-1][k];
            m = k;
        }
    }
    r[n-1] = T[n-1][m];
    for (int i = n-1; i >= 1; i--) {
        
        if(D[i-1][m] == -1){
            cout << "a" << endl;
            r[i-1] = T[i-1][m-1];
            m--;
        }
        else if(D[i-1][m-1] == -1){
            cout << "b" << endl;
            r[i-1] = T[i-1][m];
        }
        else if(D[i-1][m] >= D[i-1][m-1]){
            cout << "c" << endl;
            r[i-1] = T[i-1][m];
        }
        else{
            cout << "d" << endl;
            r[i-1] = T[i-1][m-1];
            m--;
        }
    }
}

int main()
{
    int n, maxSum = 0;
    matrix_t T, D;
    vector<int> r;

    cin >> n;
    T.assign(n, vector<int>(n, -1));
    D.assign(n, vector<int>(n, -1));
    r.assign(n, -1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i+1; j++) {
            cin >> T[i][j];
        }
    }

    triangle(n, maxSum, T, D, r);
    
    cout << maxSum << endl;
    for (int i = 0; i < n; i++) {
        cout << r[i];
        if(i != n-1)
            cout << " ";
    }
    
    return 0;
}
