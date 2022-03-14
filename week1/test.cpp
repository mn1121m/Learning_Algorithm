#include <iostream>

#define MAX_ARY_SIZE 100
using namespace std;
int main(void) {

    int arr[MAX_ARY_SIZE],num, n, i, pos;
    i = 0;

    cout<<" enter ary size: ";
    cin>>num;
    while(i < num){
        cout<<" enter value in element "<<i<<" :";
        cin>>arr[i];
        i++;
    }
    pos = 0;
    cout<<" enter any value :";
    cin>>n;
    i = 0;
    while(i < num) {
        if(n == arr[i]) {
            pos = i+1;
            break;
        }
        i++;
    }
    if(pos == 0)
        cout<<" value not found"<<endl;
    else
        cout<<" value found at position = "<<pos<<endl;
    return 0;
}