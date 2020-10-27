#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n = 50000, pi, pivot;
int d[50001];

void Partition(int left, int right)
{
    int low = 0, high = 0;
   
    if(pi == left) low = left+1;
    else low = left;
 
    if(pi == high) high = right-1;
    else high = right;

    while(low < high)
    {
        while(d[low] <= pivot && low < right) low++;
        while(d[high] > pivot && high > left) high--;
       
        if(low < high)
        {
            int t = d[low];
            d[low] = d[high];
            d[high] = t;
        }
        else
        {
            int t = d[pi];
            d[pi] = d[high];
            d[high] = t;
        }
    }  
    pi = high;
}
 
void Qsort(int left, int right)
{
    if(left >= right) return;
    pi = left;
    pivot = d[pi];
    Partition(left, right);
    Qsort(left, pi-1);
    Qsort(pi+1, right);
}
 
int main()
{
    int i, j, t;
    srand((unsigned int)time(NULL));
   
    for(i = 1; i <= n; i++)
        d[i] = rand() % n + 1;
   
    Qsort(1, n);
 
    for(i = 1; i <= n; i++)
        printf("%d ", d[i]);
    return 0;
}
