#include <iostream>
#include <vector>
#include <algorithm>
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
vector<item_t> printweight;
vector<int> include;
vector<int> bestset;

int n,W, maxprofit;
float bound;

// Functions
bool compare_item(item_t i, item_t j) {
    if (i.profit_per_unit > j.profit_per_unit)
        return true;
    return false;
};

bool promising(int i, int profit, int weight) {
    int j, k, totweight; //
    if(weight >= W){
         cout << i << " " << weight << " " << profit << " " << bound << " " << maxprofit << endl;
        return false;
    }
    else{
        j = i + 1;
        bound = profit;
        totweight = weight;
        while(j <= n && totweight + items[j].weight <= W){
            totweight += items[j].weight;
            bound += items[j].profit; 
            j++;
        }
        k = j;
        if(k <= n)
            bound += (W - totweight) * ((float) items[k].profit/items[k].weight);
            cout << i << " " << weight << " " << profit << " " << bound << " " << maxprofit << endl;
        return (bound > maxprofit);
    }
}

void knapsack4(int i,int profit,int weight){
    if(weight <= W && profit > maxprofit){
        maxprofit = profit; 
        copy(include.begin(), include.end(), bestset.begin()); //c++ copy 함수를 이용하여 배열 복사
        // copy from include to bestset.
    }

    if(i<=n && promising(i, profit, weight)) {
        include[i+1] = true;
        knapsack4(i+1, profit + items[i+1].profit, weight + items[i+1].weight);
        include[i+1] = false; 
        knapsack4(i+1, profit, weight);
    }
}

// Main
int main(){
    cin >> n >> W;
    items.resize(n+1);
    include.resize(n+1); bestset.resize(n+1);

    for(int i=1;i<=n;i++){
        cin >>items[i].weight;
    }
    for(int i=1;i<=n;i++){
        cin >>items[i].profit;
    }
    for(int i=1;i<=n;i++){
        items[i].profit_per_unit = items[i].profit / items[i].weight;
    }

    //배열 1부터 시작했으니깐 begin +1
    sort(items.begin()+1,items.end(),compare_item);

    maxprofit =0;
    knapsack4(0,0,0);
    cout <<maxprofit <<endl;

    for(int i=1;i<=n;i++){
        if(bestset[i] == true){
            cout << items[i].weight << " " << items[i].profit << endl;
        }
    }
}