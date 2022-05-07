#include <iostream>
#include <vector>
using namespace std;
#define INF 9999

typedef vector<vector<int> > matrix_t;
typedef vector<pair<int, int> > set_of_edges;
typedef pair<int, int> edge_t;
int sum = 0;

void prim(int n, matrix_t& W, set_of_edges& F)
{
    int vnear, min;
    F.clear();
    vector<int> nearest(n+1), distance(n+1);
    
    for(int i = 2; i <= n; i++){
        nearest[i] = 1;
        distance[i] = W[1][i];
    }
    
    for(int k=0; k<n-1; k++){
        // nearest 단계별 출력
        for (int i = 2; i<=n; i++) {
            cout << nearest[i];
            if(i!=n)
                cout << " ";
            else
                cout << endl;
        }
        
        min = INF;
        for (int i = 2; i<=n; i++) {
            if(0<=distance[i] && distance[i] <min){
                min = distance[i];
                vnear = i;
            }
        }
        //cout << "vnear " << vnear << endl;
        F.push_back(make_pair(vnear, nearest[vnear]));
        
        distance[vnear] = -1;
        for (int i = 2; i <= n; i++) {
            if(distance[i] > W[i][vnear]){
                distance[i] = W[i][vnear];
                nearest[i] = vnear;
            }
        }
    }
    // nearest 마지막 출력
    for (int i = 2; i<=n; i++) {
        cout << nearest[i];
        if(i!=n)
            cout << " ";
        else
            cout << endl;
    }
}
int main() {
    int n, m, u, v, w;
    matrix_t W;
    set_of_edges F;
    
    cin >> n;
    cin >> m;
    W.assign(n+1, vector<int>(n+1, INF));
    
    for(int i = 0; i<m; i++){
        cin >> u;
        cin >> v;
        cin >> w;
        W[u][v] = w;
        W[v][u] = w;
    }
    
    for(int i = 1; i <= n; i++){
        W[i][i] = 0;
    }
    
    prim(n, W, F);
   
    for(edge_t e: F){
        u = e.first; v = e.second;
        sum +=W[u][v];
        cout << u << " " << v << " " << W[u][v] << endl;
    }
    //cout << sum;
    return 0;
}
