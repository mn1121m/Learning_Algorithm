#include <iostream>
#include <vector>

using namespace std;

//  Functions
vector<int> sol(int n, vector<int> S, vector<int> F)
{
    vector<int> R;
    int f = 0;
    for(int k = 1; k <= n; k++)
    {
        if(f <= S[k])
        {
            R.push_back(k);
            f = F[k];
        }
    }
    return R;
}

//  Main
int main()
{
    int n;
    vector<int> S, F, R;
    
    cin >> n;
    S.resize(n+1);
    F.resize(n+1);
    
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
        cin >> F[i];
    }
    R = sol(n, S, F);
    
    cout << R.size() << endl;
    
    for(int i = 0; i < R.size(); i++)
    {
        cout << S[R[i]] << " " << F[R[i]];
        if(i != R.size()-1)
            cout << endl;
    }
    
    return 0;
}
