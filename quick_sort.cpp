#include <stdio.h>
#define MAX 1<<5
int n, d[MAX];

void quicksort(int l, int r)
{
    if(l >= r) return;
    
    int pivot = d[l];
    int p = l + 1;
    int q = r;
    
    while(true)
    {
        while(d[p] <= pivot && p < r) p++;
        while(d[q] > pivot && q > l) q--;
        
        if(p < q){
            int t = d[p];
            d[p] = d[q];
            d[q] = t;
        }else{
            int t = d[l];
            d[l] = d[q];
            d[q] = t;
            break;
        }
    }
    
    quicksort(l, q-1);
    quicksort(q+1, r);
}

int main(){
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++){
        scanf("%d", &d[i]);
    }
    quicksort(1, n);
    
    for(int i = 1; i <= n; i++){
        printf("%d\n", d[i]);
    }
}
