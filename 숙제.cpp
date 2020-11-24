#include <stdio.h>

int ckwrl(int t){
    if(t == 1){
        return 1;
    }
    int sum = 0;
    for(int i = 1; i < t; i++){
        sum += ckwrl(i);
    }
    return sum;
}

int main(){
    int s;
    scanf("%d", &s);
    printf("%d", ckwrl(s));
}
