// BOJ # 16563. 어려운 소인수분해 (에라토스테네스의 체 응용
#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define MAX 1234

using namespace std;

int n;
int minFactor[MAX+1];

void updateFactor(){
  for (int i=2; i<=MAX; i++)
    minFactor[i] = i;
  
  for (int i=2; i<=sqrt(MAX); i++)
    if (minFactor[i] == i)
      for (int j=i*i; j<=MAX; j+=i)
        if (minFactor[j] == j)
          minFactor[j] = i;
}

void solve(int num){
  while (num > 1){
    cout << minFactor[num] << " ";
    num /= minFactor[num];
  }
  cout << endl;
}

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // ifstream cin;
  // cin.open("input.txt");

  cin >> n;

  updateFactor();

  for (int i=0; i<n; i++){
    int num;
    cin >> num;
    solve(num);
  }

}