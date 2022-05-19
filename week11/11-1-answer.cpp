#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


// Data structure
typedef struct item* item_ptr;
typedef struct item{
    int weight;
    int profit;
    int profit_per_unit;
}item_t;


// Global variable
vector<item_t> items;

int n, W, T , maxprofit;

// Functions
bool compare_item(item_t i, item_t j) {
    if (i.profit_per_unit > j.profit_per_unit)
        return true;
    return false;
};

int knapsack3(int n, int W, vector<item_t> &items, map<pair<int,int>, int> &P){
    if(n==0 || W <=0)
        return 0;

    int lvalue = (P.find(make_pair(n-1,W)) != P.end()) ?
        P[make_pair(n-1, W)] : knapsack3(n-1,W,items,P);
    int rvalue = (P.find(make_pair(n-1,W-items[n].weight)) != P.end()) ?
        P[make_pair(n-1,W)] : knapsack3(n-1,W-items[n].weight,items,P);
    P[make_pair(n,W)] = (items[n].weight >W) ? lvalue : max(lvalue,items[n].profit +rvalue);

    return P[make_pair(n,W)];
}


// Main
int main(){
    cin >> n;
    items.resize(n+1);
    map<pair<int,int>, int> P;

    for(int i=1;i<=n;i++){
        cin >>items[i].weight;
    }
    for(int i=1;i<=n;i++){
        cin >>items[i].profit;
    }
    for(int i=1;i<=n;i++){
        items[i].profit_per_unit = items[i].profit / items[i].weight;
    }

    sort(items.begin()+1,items.end(),compare_item);

    cin >> T;
    
    while(T-- >0){

        cin >> W;
        knapsack3(n,W,items,P);
        cout << P[make_pair(n,W)] << endl;

        for(auto it = P.begin(); it!=P.end();it++){
            cout << it->first.first << " " << it->first.second << " " << it->second << endl; 
        } 
        P.clear();
    }
}
