#include <iostream>
#include <vector>
using namespace std;

void seqsearch(int n, vector<int> S, int x, int location)
{
    location = 0;
    while(location < n && S[location] != x)
        location++;
    if(location >= n)
        location = -1;
}
int main() {
    int n;
    cin >> n;

    vector<int> S(n, 0);

    for(int i = 0; i < n; i++)
        cout << S[i] << " ";
    cout << endl;

    for(int i = 0; i < n; i++)
        cin >> S[i];

    for(int i = 0; i < n; i++)
        cout << S[i] << " ";
    cout << endl;
}