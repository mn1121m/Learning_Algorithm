#include <stdio.h>
#define MAX_SIZE 128

// i: index for sorted left-hand lists
// j: index for sorted right-hand lists
// k: index to sorted list
/* The process of merging two adjacent arrays, list[left...mid] and list[mid+1...right] */
/* Actually, the process of sorting numbers */

// Global variable
int sorted[MAX_SIZE]; // additional space requirement
int cnt = 0;    // variable that counts the number of times the merge() function is called

//Functions
void merge_sort(int list[], int left, int right);
void merge(int list[], int left, int mid, int right);

//Main
int main() 
{
    int n, list[MAX_SIZE];

    // number of elements in S
    scanf("%d", &n);

    // n integers
    for(int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    // perform merge sort(left: beginning of an array = 0, right: end of an arrangement = 7)
    merge_sort(list, 0, n-1);

    // output the number of calls
    printf("%d\n", cnt);

    // output sorting results
    for(int i = 0; i< n; i++) {
        printf("%d ", list[i]);
    }
}

// Functions
void merge_sort(int list[], int left, int right)
{
    int mid;

    if(left < right) {
        mid = (left + right) / 2; // calculate the intermediate position and divide the list equally - (Divide)
        merge_sort(list, left, mid); // sort the previous list. - (Conquer)
        merge_sort(list, mid+1, right); // sort the back of the list - (Conquer)
        merge(list, left, mid, right); // the process of merging two ordered subsequences - (Combine)

    }
}
void merge(int list[], int left, int mid, int right) 
{
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    /* merge a split-sorted list */
    while(i <= mid && j <= right) {
        if(list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    // copy the remaining values in batches
    if(i > mid) {
        for(l = j; l <= right; l++)
            sorted[k++] = list[l];
    }
    
    // copy the remaining values in batches
    else {
        for(l = i; l <= mid; l++)
            sorted[k++] = list[l];
    }
    
    // recopy the list of array sorted[] into array list[]
    for(l = left; l <= right; l++) {
        list[l] = sorted[l];
    }
    cnt++;
}