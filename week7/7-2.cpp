#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//  Data structure
typedef struct edge
{
    int u, v, w;
} edge_t;

struct edge_compare
{
    bool operator()(edge_t e1, edge_t e2)
    {
        if(e1.w > e2.w) return true;
        else return false;
    }
};

//  Global variable
vector<int> dset;

typedef vector<edge_t> set_of_edges;
typedef priority_queue<edge_t, vector<edge_t>, edge_compare> PriorityQueue;


//  Functions
void dset_init(int n)
{
    dset.resize(n + 1);
    for(int i = 1; i <= n; i++){
        dset[i] = i;
    }
}

int dset_find(int i)
{
    while(dset[i] != i)
        i = dset[i];
    return i;
}

void dset_merge(int p, int q)
{
    dset[p] = q;
}

void kruskal(int n, int m, set_of_edges& E, set_of_edges& F)
{
    int p, q;
    edge_t e;
    PriorityQueue PQ;
    
    for(edge_t e: E)
        PQ.push(e);
    F.clear();
    dset_init(n);
    while(F.size() < n-1)
    {
        e = PQ.top(); PQ.pop();
        p = dset_find(e.u);
        q = dset_find(e.v);
        if(p!=q){
            dset_merge(p, q);
            F.push_back(e);
        }
    }
}


//  Main
int main()
{
    set_of_edges E, F;
    int n, m;
    
    cin >> n;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        edge_t e;
        cin >> e.u;
        cin >> e.v;
        cin >> e.w;
        E.push_back(e);
    }
    
    kruskal(n, m, E, F);
    
    for (int i = 0; i < F.size(); i++) {
        cout << F[i].u << " " << F[i].v << " " << F[i].w;
        if(i != F.size())
            cout << endl;
    }
    return 0;
}
