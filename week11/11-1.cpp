#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 128
using namespace std;

// Data structure
typedef struct item {
    int weight;
    int profit;
    int profit_per_unit;    // = profit / weight
} item_t;

// Functions
void knapsack2(int n, vector<int> W, int w[], int p[], int P[][MAX]);
int max(int n, int m);

// Global variable


// Main
int main()
{
    int n; //  number
    int w[MAX] = {0, }, p[MAX] = {0, };    // weight, profit
    int wn; // 배낭 무게 개수
    int maxProfit;  // 배낭에 담을 수 있는 최대 이익
    vector<int> W;  // 배낭 무게
    int P[MAX][MAX]; // 테이블
    vector<item_t> items;

    
    items.clear();
    W.clear();
    
    // 아이템 초기화
    cin >> n;

    for(int i = 0; i < n; i++) {
        item_t temp;
        items.push_back(temp);
    }

    for(int i = 0; i < n; i++) {
        cin >> w[i];
        items[i].weight = w[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> p[i];
        items[i].profit = p[i];
    }

    // 무게당 이익 오름차순 정렬
    sort(items.begin(), items.end());

    // 배낭 무게 개수 초기화
    cin >> wn;

    for(int i = 0; i < wn; i++) {
        cin >> W[i];
        // Knapscak 수행 후 결과 출력
        knapsack2(n, W, w, p, P);
        cout << maxProfit << endl;
        cout << P[n][w] << " "<< P[n-1][W] << " "<<P[n-1][W - w[n]] << endl;
    }
    

    return 0;
}

// Functions
void knapsack2(int n, vector<int> W, int w[], int p[], int P[][MAX])
{
    for(int i = 0; i < n; i++)
        P[i][0] = 0;
    for(int j = 1; j < W; j++)
        P[0][j] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= W; j++)
            P[i][j] = (w[i] > j) ? P[i-1][j] : max(P[i-1][j], p[i] + P[i-1][j - w[i]]);
}

int max(int n, int m) {
	if (n > m) {
		return n;
	}
	else {
		return m;
	}
}