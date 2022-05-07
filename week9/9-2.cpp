#include <iostream>
#include <vector>

using namespace std;

bool isFeasible(vector<int> deadline, vector<int>& K)
{
    for (int i = 1; i < K.size(); i++) {
        if(deadline[K[i]] < i)
            return false;
    }
    return true;
}

void schedule(int n, vector<int> deadline, vector<int>& J)
{
    vector<int> K;
    K.clear();
    K.push_back(0);
    K.push_back(1);
    for (int i = 2; i <= n; i++) {
        int j = 1;
        while(j < K.size() && deadline[i] >= deadline[K[j]])
            j++;
        K.insert(K.begin()+j, i);
        
        if (isFeasible(deadline, K) == true)
        {
            J.resize(K.size());
            copy(K.begin(), K.end(), J.begin());
        }
        else
        {
            K.erase(K.begin()+j);
        }
    }

}

int main()
{
    int n, sum = 0;
    vector<int> deadline, profit, J;
    
    cin >> n;
    
    deadline.resize(n+1);
    profit.resize(n+1);
    
    for (int i = 1; i<=n; i++)
    {
        cin >> deadline[i];
    }
    
    for (int i = 1; i<=n; i++)
    {
        cin >> profit[i];
    }

    schedule(n, deadline, J);
    for(int i = 1; i < J.size(); i++)
    {
        sum += profit[J[i]];
    }
    
    cout << sum << endl;    // 최대 이익 값 출력
    
    // job profit 순서대로 출력
    for(int i = 1; i < J.size(); i++)
    {
        cout << profit[J[i]];
        if(i != J.size()-1)
            cout << " ";
    }
    return 0;
}
