#include <iostream>
#include <vector>

using namespace std;

int pathCnt = 0;    // 해밀턴 경로 개수
int circuitCnt = 0; // 해밀턴 회로 개수

void make_graph(vector<vector<int>> &graph, int n, int m)
{
    int imove[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int jmove[] = {1, 2, 2, 1, -1, -2, -2, -1};
    graph.assign(n * m, vector<int>());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 8; k++) {
                int ni = i + imove[k];
                int nj = j + jmove[k];
                if((0 <= ni && ni < n) && (0 <= nj && nj < m))
                    graph[i * m + j].push_back(ni * m + nj);
            }
        }
    }
}

void tour(int k, int v, int s, int n, int m, vector<vector<int>> graph, vector<int> &mark)
{
    int i;
    for (i = 0; i < graph[v].size(); i++) {   // s와 v가 인접한지 체크
        if(graph[v][i] == s)
            break;
    }

    if(k == n * m)  // 해밀턴 경로
    {
        mark[v] = k;
        pathCnt++;
    }
    if(k == n * m && i != graph[v].size())    // 해밀턴 회로
    {
        mark[v] = k;
        circuitCnt++;
    }
    else
    {
        for (int u : graph[v]) {
            if(mark[u] == 0)
            {
                mark[u] = k + 1;
                tour(k + 1, u, s, n, m, graph, mark);
                mark[u] = 0;
            }
        }
    }
}

int main()
{
    int n, m;   // 체스보드 row, col;
    int T; // 출발정점 개수
    int i, j, s;
    vector<pair<int, int>> t; // 출발 정점 쌍
    vector<vector<int>> graph;  // 인접
    vector<int> mark;   // 방문여부 저장
    
    cin >> n >> m;
    cin >> T;
    
    // 출발정점쌍 저장
    for (int k = 0; k < T; k++) {
        cin >> i >> j;
        t.push_back(make_pair(i, j));
    }
    
    // 인접리스트 생성
    make_graph(graph, n, m);

    for (int k = 0; k < T; k++) {
        s = t[k].first * m + t[k].second;   // 출발 노드
        mark.clear();
        mark.resize(n * m);
        mark[s] = 1;
        pathCnt = 0;
        
        tour(1, s, s, n, m, graph, mark);
        if(k == 0)
            cout << circuitCnt;
        cout << endl << pathCnt;
    }

    return 0;
}
