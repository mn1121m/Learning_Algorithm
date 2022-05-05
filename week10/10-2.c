#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define MAX 1028


//  Global varible
int include[MAX];
int w[MAX];
int W;
int n;
int count = 0; // count about subsets
int IsPrint;


//  Function
bool promising(int i, int weight, int total);
void sum_of_subsets(int i, int weight, int total, int IsPrint);
void printSubset();

//  Main
int main(void)
{
   int total = 0;
   scanf("%d %d", &n, &W);
   for (int i = 1; i <= n; i++) {
      scanf("%d", &w[i]);
      total += w[i];
      include[i] = false;
   }

   sum_of_subsets(0, 0, total, 0);
   printf("%d\n", count);
   total = 0;
   for (int i = 1; i <= n; i++) {
      total += w[i];
      include[i] = false;
   }
   sum_of_subsets(0, 0, total, 1);
}

//  Function
bool promising(int i, int weight, int total)
{
   return (weight + total >= W) && (weight == W || weight + w[i + 1] <= W);
}

void sum_of_subsets(int i, int weight, int total, int IsPrint)
{
   if (promising(i, weight, total)) {
      if (weight == W) {
         if(IsPrint)
            printSubset();
         else
            count++;
      }
      else {
         include[i + 1] = true;
         sum_of_subsets(i + 1, weight + w[i + 1], total - w[i + 1],IsPrint);
         include[i + 1] = false;
         sum_of_subsets(i + 1, weight, total - w[i + 1],IsPrint);
      }
   }
}


void printSubset()
{
   int dummy = 0;
   for (int i = 0; i < MAX; i++) {
      if (include[i] != false)
      {
         if (dummy == 0)
            dummy = 1;
         else
            printf(" ");
         printf("%d", w[i]);
      }
   }
   printf("\n");
}
