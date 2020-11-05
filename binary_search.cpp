#include <stdio.h>
#define MAX 1<<5

int d[MAX];
int main(){
	int n, s, m;
	scanf("%d", &n);
	scanf("%d", &s);
	int l = 1;
	int r = n;
	for(int i = 1; i <= n; i++){
		scanf("%d", &d[i]);
	}
	
	while(l <= r){
		m = (l + r) / 2;
		if(s = d[m]){
			break;
		}else if(s > d[m]){
			l = m + 1;
		}else if(s < d[m]){
			r = m - 1;
		}
	}
	
	if(l <= m){
		printf("%d", m-1); //거0번째 항 제 
	}else{
		printf("Not Found!");
	}
}
