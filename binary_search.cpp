#include <stdio.h>
#define MAX 1<<5

int d[MAX];
int main(){
	int n, s, m;
	scanf("%d", &n);
	int l = 1;
	int r = n;
	for(int i = 1; i <= n; i++){
		scanf("%d", &d[i]);
	}
	scanf("%d", &s);
	
	while(l <= r){
		m = (l + r) / 2;
		if(s == d[m]){
			break;
		}else if(s > d[m]){
			l = m + 1;
		}else if(s < d[m]){
			r = m - 1;
		}
	}
	
	if(l <= r){
		printf("%d", m); 
	}else{
		printf("Not Found!");
	}
}
