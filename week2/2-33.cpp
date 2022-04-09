#include <iostream>
#include <vector>

using namespace std;


// Function
void binsearch(int n, vector<int>& S, int& location, int& cnt);


// Main
int main()
{
    int location=0, cnt=0;
    int n; cin >> n;
    vector<int> S(n);
    for(int i=0; i<n; i++){
        cin >> S[i];
    }
    binsearch(n, S, location, cnt);
    cout << location << endl << cnt << endl;
    
    return 0;
}


void binsearch(int n, vector<int>& S, int& location, int& cnt)
{
    int low, high, mid;
    low = 0; high = n-1;
    location = -1;
    cnt = 0;
    while(low <= high && location == -1){
        cnt++;
        mid = (low+high)/2;
        if(mid==S[mid])
            location = mid;
        else if(mid < S[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }

    }
}