#include <iostream>
#include <vector>

using namespace std;

#define INF 9999
typedef vector<vector<int> > matrix_t;
typedef pair<int,int> edge_t;
typedef vector<pair<int, int> > set_of_edges;

vector<int> dijkstra(int n, matrix_t& W, set_of_edges& E, set_of_edges& F)
{
    int vnear, min, u = 1;
    vector<int> touch(n+1), length(n+1);
    
    F.clear();
    for(int i = 2; i <= n; i++)
    {
        touch[i] = 1;
        length[i] = W[1][i];
    }
    
    for(int k = 2; k <= n; k++)
    {
        for(int i = 2; i <= n; i++)
        {
            cout << touch[i];
            if(i != n)
                cout << " ";
        }
        cout << endl;
        
        min = INF;
        for(int i = 2; i <= n; i++)
            if(0 <= length[i] && length[i] < min)
            {
                min = length[i];
                vnear = i;
            }
        
        edge_t e = make_pair(touch[vnear], vnear);
        
        F.push_back(e);
        for (int i = 2; i <= n; i++) {
            if(length[i] > length[vnear] + W[vnear][i])
            {
                length[i] = length[vnear] + W[vnear][i];
                touch[i] = vnear;
            }
        }
        
        length[vnear] = -1;
        u = vnear;
    }
    
    for(int i = 2; i <= n; i++)
    {
        cout << touch[i];
        if(i != n)
            cout << " ";
    }
    cout << endl;
    
    return touch;
}
// 1번 정점으로부터 정점 v로 가는 최단 경로 출력
void print_route(vector<int> touch, int v)
{
    if(v == 1)
    {
        cout << 1;
        return;
    }
       
    print_route(touch, touch[v]);
    cout << " " << v;
}

int main() {
    set_of_edges E, F;
    matrix_t W;
    vector<int> touch;
    vector<int> T;
    int n, m, u, v, w, t, tmp;
    
    cin >> n;
    cin >> m;
    
    W.assign(n+1, vector<int>(n+1, INF));
    
    for (int i = 0; i < m; i++)
    {
        cin >> u;
        cin >> v;
        cin >> w;
        W[u][v] = w;
        E.push_back(make_pair(u, v));
    }
    
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> tmp;
        T.push_back(tmp);
    }
    
    for(int i = 1; i <= n; i++)
    {
        W[i][i] = 0;
    }
    
    touch = dijkstra(n, W, E, F);
    
    // F 간선 순서대로 출력
    for (int i = 0; i < F.size(); i++) {
        u = F[i].first;
        v = F[i].second;
        cout << u << " " << v << " " << W[u][v];
        if(i != F.size())
            cout << endl;
    }
    
    for (int i = 0; i < t; i++) {
        print_route(touch, T[i]);
        if(i != t-1)
            cout << endl;
    }
    
    return 0;
}
