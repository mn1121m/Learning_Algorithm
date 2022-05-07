#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct item {
    int weight;
    int profit;
    int profit_per_unit;
} item_t;

bool cmp(item_t i, item_t j)
{
    if (i.profit_per_unit > j.profit_per_unit)
        return true;
    return false;
}

void knapsack(int n, vector<item_t> items, vector<pair<int, int>>& WP, int& maxprofit, int& w)
{
    int totweight = 0;
    maxprofit = 0;
    WP.clear();

    for (int i = 0; i < n; i++) {
        if(totweight + items[i].weight <= w)
        {
            maxprofit += items[i].profit;
            totweight += items[i].weight;
            WP.push_back(make_pair(items[i].weight, items[i].profit));
        }
        else
        {
            int profit = (w - totweight) * items[i].profit_per_unit;
            int weight = (w - totweight);
            maxprofit += profit;
            totweight += weight;
            WP.push_back(make_pair(weight, profit));
            break;
        }
    }
}

int main()
{
    int n, w, p;
    int wn; // 배낭무게 개수
    int maxprofit;
    vector<item_t> items;
    vector<int> W; // 배낭 무게
    vector<pair<int, int>> WP; // 담은 아이템 무게와 이익쌍

    items.clear();
    W.clear();
    
    // 아이템 초기화
    cin >> n;

    for (int i = 0; i < n; i++) {
        item_t temp;
        items.push_back(temp);
    }

    for (int i = 0; i < n; i++) {
        cin >> w;
        items[i].weight = w;
    }

    for (int i = 0; i < n; i++) {
        cin >> p;
        items[i].profit = p;
    }


    for (int i = 0; i < n; i++) {
        items[i].profit_per_unit = items[i].profit/items[i].weight;
    }

    // 무게당 이익 내림차순 정렬
    sort(items.begin(), items.end(), cmp);

    // 배낭무게 초기화
    cin >> wn;
    W.resize(wn);

    for (int i = 0; i < wn; i++) {
        cin >> W[i];
    }

    // Knapsack 수행, 결과 출력
    for (int i = 0; i < wn; i++) {
        knapsack(n, items, WP, maxprofit, W[i]);
        cout << maxprofit << endl;
        for (int j = 0; j < WP.size(); j++) {
            cout << WP[j].first << " " << WP[j].second;
            if(j != WP.size()-1)
                cout << endl;
        }
        if(i != wn - 1)
            cout << endl;
    }

    return 0;
}
