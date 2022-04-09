#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> arr(n); //int arr[100];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int largest, smallest;
    
    largest = arr[0];
    smallest = arr[0];
    
    for(int i = 0; i < n; i++){
        if (largest < arr[i]) largest = arr[i];
        if (smallest > arr[i]) smallest = arr[i];
    }
    cout << smallest << endl;
    cout << largest << endl;
    
    return 0;
}
