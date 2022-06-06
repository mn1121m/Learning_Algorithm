#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int maxprofit = 0;  // 최대이익
int W;              // 배낭무게
int n;              // 아이템 개수
vector<int> w, p;   // 무게, 이익
vector<pair<int, int>> wp;  // 무게 이익 쌍


typedef struct node* node_pointer;
typedef struct node{
    int level;
    int weight;
    int profit;
    float bound;
}nodetype;

struct compare{
    bool operator()(node_pointer u, node_pointer v) {
        if(u->bound < v->bound)
            return true;
        return false;
    }
};

typedef priority_queue<node_pointer, vector<node_pointer>, compare> priority_queue_of_node;

float bound(node_pointer u)
{
    int j, k, totweight;
    float result;
    if(u->weight >= W)
        return 0;
    else {
        result = u->profit;
        j = u->level + 1;
        totweight = u->weight;
        while(j <= n && totweight + wp[j].first <= W)
        {
            totweight += wp[j].first;
            result += wp[j].second;
            j++;
        }
        k = j;
        if(k <= n)
            result += (W - totweight) * ((float)wp[k].second / wp[k].first);
        return result;
    }
}

node_pointer create_node(int level, int weight, int profit)
{
    node_pointer v = (node_pointer)malloc(sizeof(nodetype));
    v->level = level;
    v->weight = weight;
    v->profit = profit;
    v->bound = bound(v);
    return v;
}

void knapsack6()
{
    priority_queue_of_node PQ;
    node_pointer u, v;
    maxprofit = 0;
    PQ.push(create_node(0, 0, 0));
    v = PQ.top();
    cout << v->level << " " << v->weight << " " << v->profit << " " << v->bound << endl;
    while(!PQ.empty())
    {
        v = PQ.top(); PQ.pop();
        if(v->bound > maxprofit)
        {
            u = create_node(v->level + 1, v->weight + wp[v->level + 1].first, v->profit + wp[v->level + 1].second);

            if(u->weight <= W && u->profit > maxprofit)
            {
               
                maxprofit = u->profit;
            }

            cout << u->level << " " << u->weight << " " << u->profit << " " << u->bound << endl;
            if(u->bound > maxprofit)
            {
                
                PQ.push(u);
            }
           
            u = create_node(v->level + 1, v->weight, v->profit);
            cout << u->level << " " << u->weight << " " << u->profit << " " << u->bound << endl;
            if(u->bound > maxprofit)
                PQ.push(u);
        }
    }
}

int main()
{
    priority_queue_of_node PQ;
    cin >> n >> W;
    w.resize(n);
    p.resize(n);
    wp.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        wp[i] = make_pair(w[i], p[i]);
    }
    // 단위무게당 이익의 내림차순으로 무게이익쌍 정렬
    sort(wp.begin(), wp.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second/a.first > b.second/b.first;
    });
    
    // 인덱스 0번 사용 안함
    wp.insert(wp.begin(), make_pair(0, 0));
    w.insert(w.begin(), 0);
    p.insert(p.begin(), 0);
    
    // knapsack
    knapsack6();
    
    // 최대이익 출력
    cout << maxprofit;
    
    return 0;
}
