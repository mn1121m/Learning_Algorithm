#include <iostream>
using namespace std;

int fib(int n, int max)
{
    int n1 = 0, n2 = 1, n3 = 0;
    if(n == 0) return n1;
    else if(n == 1) return n2;
    else
    {
        for(int i = 2; i <= n; i++)
        {
            n3 = (n1 + n2) % max;
            n1 = n2;
            n2 = n3;
        }
        return n3;
    }
}

int main()
{
    int n, max;
    cin >> n;
    cin >> max;
    
    cout << fib(n, max) << endl;
    return 0;
}
