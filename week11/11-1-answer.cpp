#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int knapsack3(int n, int W, vector<pair<int,int>> wp, map<pair<int, int>, int> &P)
{
    if(n == 0 || W <= 0)
        return 0;
    int lvalue = (P.find(make_pair(n-1, W)) != P.end()) ?
        P[make_pair(n-1, W)] : knapsack3(n-1, W, wp, P);
    int rvalue = (P.find(make_pair(n-1, W-wp[n].first)) != P.end()) ?
        P[make_pair(n-1, W)] : knapsack3(n-1, W-wp[n].first, wp, P);
    P[make_pair(n, W)] = (wp[n].first > W) ? lvalue : max(lvalue, wp[n].second + rvalue);
    return P[make_pair(n, W)];
}

int main() {
    int n;  // 아이템 개수
    int T;  // 배낭 무게 개수
    vector<int> w, p, t;
    map<pair<int, int>, int> P;
    vector<pair<int, int>> wp;  // 무게 이익 쌍
    
    cin >> n;
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
    
    // wp 인덱스 0번 사용 안함
    wp.insert(wp.begin(), make_pair(0, 0));
   
    // 배낭무게 입력
    cin >> T;
    
    t.resize(T);
    for (int i = 0; i < T; i++) {
        cin >> t[i];
    }
    
    // 배낭 무게 개수 T번 반복
    for(int k = 0; k < T; k++)
    {
        P.clear();
        // maxprofit 출력
        cout << knapsack3(n, t[k], wp, P) << endl;
        
        // map의 키를 vector에 저장
        vector<pair<int, int>> v;
        map<pair<int, int>, int>::iterator iter;
        for (iter = P.begin(); iter != P.end(); iter++) {
            v.push_back((*iter).first);
        }
        
        // vector에 저장한 map의 키 pair를 first와 second 모두 오름차순 정렬
        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            if(a.first == b.first)
                return a.second < b.second;
            else return a.first < b.first;
        });

        // 정렬된 key pair와 value 값 출력
        for (int i = 0; i < v.size(); i++) {
            cout << v[i].first << " " << v[i].second << " " << P[(make_pair(v[i].first, v[i].second))];
            if(i != v.size()-1)
                cout << endl;
        }
        
        if(k != T-1)
            cout << endl;
    }
        
    
    return 0;
}
