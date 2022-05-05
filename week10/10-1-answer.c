#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 128
#define MAX1 1028

// Global variable
int n;
int col[MAX] = { 0, };
int arr[MAX1] = { 0, };
int count = 0;
long long maxNum = -1;


// Functions
int dummy(int n);
long long makeMax();
void queens(int i, int n);
int abs(int n);
bool promising(int i);


// Main
int main(void) {

   int max = 0;

   scanf("%d", &n);

   //queens
   queens(0, n);

   //print count, max
   printf("%d\n", count);   
   printf("%lld\n", maxNum);   

   return 0;
}

// Functions

int dummy(int n)
{
   int answer = 0;
   while (n)
   {
      n /= 10;
      answer++;
   }
   int answer2 = 1;
   for (int i = 0; i < answer; i++)
      answer2 *= 10;
   return answer2;
}

long long makeMax()
{
   long long answer = 0;
   for (int i = 1; i <= n; i++) {
      answer += col[i];
      if (i != n)
         answer *= dummy(col[i + 1]);
   }
   return answer;
}

void queens(int i, int n) {
   int j;

   if (promising(i)) {
      if (i == n) {
         long long dummy = makeMax();
         if (maxNum < 0 || dummy > maxNum)
         {
            maxNum = dummy;
         }
         count++;
      }
      else
         for (j = n; j >=1; j--) {
            col[i + 1] = j;
            queens(i + 1, n);
         }
   }
}


bool promising(int i) {
   int k = 1;
   bool flag = true;
   while (k < i && flag) {
      if ((col[i] == col[k]) || (abs(col[i] - col[k]) == i - k))
         flag = false;
      k++;
   }
   return flag;
}

int abs(int n) {
   if (n > 0) {
      return n;
   }
   else
      return -n;
}