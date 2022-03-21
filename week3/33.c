# include <stdio.h>

# define MAX_LIST_SIZE 128
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

// 1. Divide into two partial lists based on pivot.
// 2. All values smaller than pivot are moved to the left substitute list, and larger values are moved to the right substitute list.
/* two unequal arrangement list[left...Pivot-1] and list[pivot+1...right] merge process */
/* (Actually, the process of sorting numbers) */

// Global variable
int cnt = 0;  // variable that counts the number of times the partition() function is called

// Functions
void quick_sort(int list[], int left, int right);
int partition(int list[], int left, int right);

// Main
int main()
{
    int n;
    int list[MAX_LIST_SIZE];

    // Input n, list
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    // Perform quick sort (left: beginning of an array = 0, right: end of an array  = 8)
    
    quick_sort(list, 0, n-1);

    // Print
    // 1. The result of calling the partition (1, n) function as an input of S is output => ?
    
    // 2. print cnt / cnt: variable that counts the number of times the partition() function is called
    printf("%d\n", cnt);
    // 3. Print sort(resulted)
    for(int i = 0; i < n; i++){
        printf("%d ", list[i]);
    }

    return 0;
}

// Functions
void quick_sort(int list[], int left, int right)
{

    /* If there are more than two data to sort (unless the size of the list is 0 or 1) */
    if(left<right){

        // The partition function is called to divide the list unevenly based on the pivot. - (Divide)
        int q = partition(list, left, right); // q: 피벗의 위치
        cnt++;

        // A circular call is made to two partial lists excluding pivot.
        quick_sort(list, left, q-1); // Sort the front part list (left to just before pivot) - (Conquer)
        quick_sort(list, q+1, right); // (Right after pivot) Sort the list of subsequent parts - (Conquer)
    }

}

int partition(int list[], int left, int right)
{
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left]; // Select the leftmost data of the list to be sorted as pivot.(Select any value as pivot)
    
    /* Repeat until low and high intersect (low < high) */
    do{
        /* If list[low] is less than pivot, it continues to increase low */
        do {
        low++; // low starts at left+1
        } while (low<=right && list[low]<pivot);

        /* If list[high] is greater than pivot, it continues to decrease high */
        do {
        high--; // high begins with right
        } while (high>=left && list[high]>pivot);

        // If low and high do not intersect, exchange list[low] with list[high]
        if(low<high){
        SWAP(list[low], list[high], temp);
        }
    } while (low<high);

    // When low and high intersect, exit the do-while() and exchange list[left] and list[high].
    SWAP(list[left], list[high], temp);
    // Returns the pivot position, high.
    return high;
}
