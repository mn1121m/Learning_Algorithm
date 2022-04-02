
#include <iostream>

using namespace std;

int B[100];

int binom(int n, int k)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < min(i, k); j++) 
            if(j == 0 || j == i)
                B[j] = 0;
            else
                B[j] = B[j] + B[j - 1];
}

int main()
{
    int num;

    cin >> num;
    cout << num << endl;
    
    return 0;
}