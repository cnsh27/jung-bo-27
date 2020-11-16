#include <stdio.h>
#define MAX 1<<5

int d[MAX];
int main(){
	int s, n, i = 0;
	scanf("%d", &s);
	scanf("%d", &n);
	for(int m = 1; m <= n; m++){
		scanf("%d", &d[m]);
	}
	while(d[i] != s && i <= n) i++;
	if(i > n){
		printf("Not Found!");
	}else{
		printf("%d", i);
	}
}
