#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int maxprofit;
int n;
int W;
int w[10];
int p[10];

typedef struct item
{
    int weight;
    int profit;
    double vpw; // profit[i]/ weight[i]
}item_t;

typedef struct node *node_pointer;
typedef struct node {
    int level; // the node's level in the state space tree
    int weight;
    int profit;
    float bound;
} nodetype;


void exchangesort(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (p[i] / w[i] < p[j] / w[j]) {
				int tmp = 0;
				tmp = w[i];
				w[i] = w[j];
				w[j] = tmp;
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}
}

struct compare {
    bool operator()(node_pointer u, node_pointer v) {
        if (u->bound < v->bound)
            return true;
        return false;
    }
};

typedef priority_queue<node_pointer, vector<node_pointer>, compare>
priority_queue_of_node;

float bound(node_pointer u) {
    int j, k, totweight; float result;
    if (u->weight >= W)
        return 0;
    else {
        result = u->profit;
        j = u->level + 1;
        totweight = u->weight;
        while (j <= n && totweight + w[j] <= W) {
            totweight += w[j];
            result += p[j];
            j++;
        }
        k = j;
        if (k <= n)
            result += (W - totweight) * ((float)p[k] / w[k]);
        return result;
    }
}

node_pointer create_node(int level, int weight, int profit) {
    node_pointer v = (node_pointer)malloc(sizeof(nodetype));
    v->level = level;
    v->weight = weight;
    v->profit = profit;
    v->bound = bound(v);
    return v;
}

void knapsack6() {
    priority_queue_of_node PQ; node_pointer u, v;
    maxprofit = 0;
    PQ.push(create_node(0, 0, 0));
    v = PQ.top();
    cout << v->level << " " << v->weight << " " << v->profit << " " << v->bound << endl;
    while (!PQ.empty()) {
        v = PQ.top();
        PQ.pop();
        if (v->bound > maxprofit) {
            u = create_node(v->level + 1,
                            v->weight + w[v->level + 1],
                            v->profit + p[v->level + 1]);
            if (u->weight <= W && u->profit > maxprofit)
                maxprofit = u->profit;
                cout << u->level << " " << u->weight << " " << u->profit << " " << u->bound << endl;
            if (u->bound > maxprofit)
                PQ.push(u);
            u = create_node(v->level + 1, v->weight, v->profit);
            cout << u->level << " " << u->weight << " " << u->profit << " " << u->bound << endl;
            if (u->bound > maxprofit)
                PQ.push(u);
        }
    }
}

int main()
{
    cin >> n >> W;
    for(int i=1; i<=n; i++)
    {
        cin >> w[i];
    }

    for(int i=1; i<=n; i++)
    {
        cin >> p[i];
    }
    exchangesort(n);
    knapsack6();
    cout << maxprofit;
}