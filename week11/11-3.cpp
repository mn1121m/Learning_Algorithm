#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100

//int **W;
int T, row[MAX], col[MAX];
int n, m, cnt, cnt2 = 0;

vector<vector<int>> W;
vector<int> vindex;
vector<vector<int>> graph;

bool promising(int i);
void hamiltonian(int i, int start);
bool promising2(int i);
void hamiltonian2(int i, int start);
void make_graph();
void resize(int n, int m);

int main()
{
   cin >> n >> m;
   resize(n*m, n*m);
   
   cin >> T;
   //출발 정점의 쌍
   for (int i = 0; i < T; i++)
      cin >> row[i] >> col[i];
   /*
   W = (int**)malloc(sizeof(int*)*(n + 1));
   for (int i = 0; i <= n; i++)
      W[i] = (int*)malloc(sizeof(int)*(m + 1));
   
   for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
         W[i][j] = 0;
   */
   make_graph();

   vindex.resize(n*m, 0);
   vindex[0] = 1;

   cnt=0;
   hamiltonian(0, 1);
   cout << cnt << '\n';

   for (int i = 0; i < T; i++)
   {
      vindex[0] = row[i] * m + col[i];
      cnt2 = 0;
      hamiltonian2(0, row[i] * m + col[i]);
      cout << cnt2 << endl;
   }

}

void resize(int n, int m)
{
   for (int i = 0; i < n; i++)
   {
      vector<int> line(m);
      W.push_back(line);
   }
}

//회로
void hamiltonian(int i, int start)
{
   int j;
   if (promising(i))
   {
      if (i == n*m - 1)
            cnt++;
      else
         for (j = 0; j < n*m; j++)
         {
            if (j != start)
            {
               vindex[i + 1] = j;
               hamiltonian(i + 1, start);
            }
         }
   }
}

//경로
void hamiltonian2(int i, int start)
{
   int j;
   if (promising2(i))
   {
      if (i == n * m - 1)
         cnt2++;
      else
         for (j = 0; j < n * m; j++)
         {
            if (j != start)
            {
               vindex[i + 1] = j;
               hamiltonian2(i + 1, start);
            }
         }
   }
}

//회로
bool promising(int i)
{
   int j;
   bool flag;
   if (i == n*m - 1 && !W[vindex[n*m - 1]][vindex[0]])
      flag = false;
   else if (i > 0 && !W[vindex[i - 1]][vindex[i]])
      flag = false;
   else
   {
      flag = true;
      j = 0;
      while (j < i && flag)
      {
         if (vindex[i] == vindex[j])
            flag = false;
         j++;
      }
   }
   return flag;
}

//경로
bool promising2(int i)
{
   int j;
   bool flag;
   if (i > 0 && !W[vindex[i - 1]][vindex[i]])
      flag = false;
   else
   {
      flag = true;
      j = 0;
      while (j < i && flag)
      {
         if (vindex[i] == vindex[j])
            flag = false;
         j++;
      }
   }
   return flag;
}

void make_graph()
{
   int imov[8] = { -2,-1,1,2, 2,1,-1,-2 };
   int jmov[8] = { 1, 2, 2, 1,-1,-2,-2,-1 };
   for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
         for (int k = 0; k < 8; k++)
         {
            int ni = i + imov[k];
            int nj = j + jmov[k];
            if (ni >= 0 && nj >= 0 && ni < n &&nj < m)
            {
               W[i*m + j][ni*m + nj] = 1;
               W[ni*m + nj][i*m + j] = 1;
            }
         }

}