#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;  // 아이템 개수
int W;  // 배낭 무게
int maxprofit = 0;
float bound;
vector<int> include, bestset, w, p;
vector<pair<int, int>> wp;  // 무게 이익 쌍

bool promising(int i, int profit, int weight)
{
    int j, k, totweight;

    if(weight >= W)
        return false;
    else {
        j = i + 1;
        bound = profit;
        totweight = weight;
        while (j <= n && totweight + wp[j].first <= W)
        {
            totweight += wp[j].first;
            bound += wp[j].second;
            j++;
        }
        k = j;
        if(k <= n)
            bound += (W - totweight) * ((float)wp[k].second / wp[k].first);

        return bound > maxprofit;
    }
}

void knapsack4(int i, int profit, int weight)
{
    if(weight <= W && profit > maxprofit)
    {
        maxprofit = profit;
        copy(include.begin(), include.end(), bestset.begin());
    }
    if(promising(i, profit, weight))
    {
        
        
        cout << i << " " << weight << " " << profit << " " << bound << " " << maxprofit << endl;
        include[i+1] = true;
        knapsack4(i+1, profit + wp[i+1].second, weight + wp[i+1].first);
        include[i+1] = false;
        knapsack4(i+1, profit, weight);
    }
    else
    {
        cout << i << " " << weight << " " << profit << " " << bound << " " << maxprofit << endl;
    }
    
}
int main()
{
    cin >> n;
    cin >> W;
    
    w.resize(n+1);
    p.resize(n+1);
    wp.resize(n);
    include.resize(n+1);
    bestset.resize(n+1);

    
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
    knapsack4(0, 0, 0);
    
    // maxprofit 출력
    cout << maxprofit;
    
    // 담은 아이템의 무게, 이익 출력
    for (int i = 1; i <= n; i++) {
        if(bestset[i])
            cout << endl << wp[i].first << " " << wp[i].second;
    }
    return 0;
}
