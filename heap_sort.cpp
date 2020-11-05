#include <stdio.h>
#define MAX 1<<5

int n, d[MAX];

void shiftdown(int k, int m) {
   if(k > m/2) return; 
   
   int i = 2*k;
   if (d[i+1] > d[i] && i < m) i++;
   
   if(d[i] > d[k]) {  
      int t = d[k];
      d[k] = d[i];
      d[i] = t;
      
      shiftdown(i, m); 
   } 
}

void heapify (int k) {
   for (int i = k/2; i >= 1; i--) 
      shiftdown(i, k); 
}

void heapsort(int k) {
   heapify(k);
   
   for (int i = k; i >= 1; i--) { 
      int t = d[1];
      d[1] = d[i];
      d[i] = t;
      
      shiftdown(1, i-1);
   }
}

int main() {
   scanf("%d", &n);
   
   for (int i = 1; i <= n; i++) 
	scanf("%d", &d[i]);
   
   heapsort(n);
   
   for (int i = 1; i <= n; i++) 
   	printf("%d ", d[i]);
   
   return 0;
}
