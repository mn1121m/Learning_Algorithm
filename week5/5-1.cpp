#include <iostream>
using namespace std;

int MAX = 0;
int temp1 = 0, temp2 = 0;   

int* B;

int bin2(int n, int k)
{
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= k; j++) {
            if(j==0 || j==i)
                B[j] = 1;
            else if(j <= i) {
                
                B[j] = (temp1 + temp2) % MAX;
                
                temp1 = temp2;
                temp2 = B[j+1];
            }
        }
        
        temp1 = B[0];
        temp2 = B[1];
    }
    return B[k];
}

int main()
{
    int n, k;
    
    cin >> n;
    cin >> k;
    cin >> MAX;

    B = new int[n];   
    
    cout << bin2(n, k);
    
    delete[] B;
    return 0;
}
