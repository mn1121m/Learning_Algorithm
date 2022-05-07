#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

//#define DEBUG
#define FOR(i, n) for(int i = 0; i < n; i++)


// Global variables
int n, m;
vector<vector<int> > graph; //그래프를 나타내는 인접행렬
vector<int> path;   //지금까지 색칠한 것들을 저장하는 배열
int color = 1;   //색깔갯수
bool flag = false;   //주어진 색깔 갯수로 전체를 색칠할 수 있는지 여부를 나타내는 boolean 변수
int case_count = 0;

// Functions
bool Promising(int depth);
void Solve(int depth);


// Main
int main() {
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

   cin >> n >> m;

   //vector 초기화
   graph.resize(n + 1);
   for (int i = 1; i <= n; i++) {
      vector<int> arr(n + 1, 0);
      graph[i] = arr;
   }

   //graph 입력받기
   for (int i = 1; i <= m; i++) {
      int s, e;
      cin >> s >> e;
      graph[s][e] = 1;
      graph[e][s] = 1;
   }

   //printf("solution set(숫자는 색깔에 대한 구분)\n");
   for (color = 1; color < 5; color++) {
      path.clear();
      path.resize(n + 1);
      Solve(0);
      if (flag) break;
   }
   //printf("\n");

  // printf("G를 칠할 수 있는 최소 m\n");
   cout << color << endl;
   cout << case_count;
   return 0;
}


bool Promising(int depth) {
   //지금까지 색칠한 것들중,
   //depth로의 간선이 있고 depth와 색깔이 같은 노드가 있으면 non promising
   for (int i = 1; i < depth; i++) {
      if (graph[i][depth] == 1 && path[i] == path[depth])
         return false;
   }
   return true;
}

//depth = 마지막으로 색칠한 vertex
//마지막으로 색칠한 vertex가 주어졌을 때,
void Solve(int depth) {
   if (!Promising(depth)) return;

   //마지막 노드까지 무사히 색칠이 완료되었으면 지금까지 색칠한 것을 출력
   if (depth == n) {
      flag = true;
      case_count++;
      // for (int i = 1; i <= depth; i++) {
      //    printf("%d ", path[i]);
      // }
      // printf("\n");
      
   }
   //다음 색칠할 노드에 종류별로 색을 칠해서 재귀해본다.
   else {
      for (int i = 0; i < color; i++) {
         path.at(depth + 1) = i;
         Solve(depth + 1);
      }
   }
}
