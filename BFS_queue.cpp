#include <stdio.h>
#include <queue>
#define max 100
std::queue<int> Q;
int G[max+1][max+1], v[max+1], n, k;

void BFS(int t){
    Q.push(t);
    v[t] = 1;
    while(!Q.empty()){
        t = Q.front();
        Q.pop();
        printf("%d ", t);
        for(int i = 1; i <= n; i++){
            if(G[t][i] == 1 && v[i] != 1){
                Q.push(i);
                v[i] = 1;
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
    BFS(1);
}
