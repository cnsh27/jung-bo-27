#include <stdio.h>
#include <stack>
#define max 1000

int n, k, G[max+1][max+1];
int v[max+1];
std::stack<int> S;
void DFS(int t){
    S.push(t);
    while(!S.empty()){
        t = S.top();
        S.pop();
        if(v[t] == 0){
            printf("%d", t);
            v[t] = 1;
            for(int i = n; i >= 1; i--){
                if(G[t][i] == 1 && v[i] == 0){
                    S.push(i);
                }
            }
        }
    }
}

int main(){
    int s, e;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= k; i++){
        scanf("%d %d", &s, &e);
        G[s][e] = G[e][s] = 1;
    }
    DFS(1);
    printf("\n");
}
