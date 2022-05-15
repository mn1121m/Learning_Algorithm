#include <iostream>
#include <vector>

using namespace std;

//  Global variable
int n, m;
vector<vector<int> > W;
vector<int> vindex;
bool flag;
int h_count = 0; // Hamiltonian Circulits's Count

// Functions
bool promising(int i);
void hamiltonian(int i);

//  Main
int main()
{

    //  input
    cin >> n >> m;
    
    // 초기화
    W.resize(n + 1, vector<int>(n + 1));
    vindex.resize(n);

    for (int i = 1; i <= m; i++)
    {
        int s, e;
        cin >> s >> e;
        W[s][e] = 1;
        W[e][s] = 1;
    }

    vindex[0] = 1;
    hamiltonian(0);

    //  printf("Print the Hamiltonian Circulits's Count\n");
    cout << h_count;

    return 0;
}

// Functions
bool promising(int i)
{

    int j;
    // v번 진행했으나 다시 첫 지점으로 돌아가는 간선이 없는 경우 false
    if (i == n - 1 && !W[vindex[n - 1]][vindex[0]])
        flag = false;
    //간선이 없는 경우 false
    else if (i > 0 && !W[vindex[i - 1]][vindex[i]])
        flag = false;
    //나머지 경우는 true
    else
    {
        flag = true;
        j = 1;
        //이미 방문했던 곳이면 false
        while (j < i && flag)
        {
            if (vindex[i] == vindex[j])
                flag = false;
            j++;
        }
    }
    return flag;
}

// i : 마지막 방문한 index
void hamiltonian(int i)
{

    int j;

    if (promising(i))
    {
        if (i == n - 1)
        {
            h_count++;
        }
        else
        {
            for (j = 2; j <= n; j++)
            {
                vindex[i + 1] = j;
                hamiltonian(i + 1);
            }
        }
    }
}