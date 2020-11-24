#include <stdio.h>
#define N 100
FILE*in = fopen("in.txt", "r");
FILE*out = fopen("out.txt", "w");
int n, s, G[N][N], v[N];
int Q[N], rear=1, front = 1;

bool Q_empty(){
    return rear < front;
}

int Q_top(){
    return Q[front];
}

void Q_pop(){
    front++;
}

void Q_push(int k){
    rear++;
    Q[rear] = k;
}

void BFS(){
    int i;
    Q_push(s);
    Q_pop();
    while(!Q_empty()){
        s = Q_top();
        fprintf(out, "%d", s);
        v[s] = 1;
        for(i = 1; i <= n; i++){
            if(G[s][i] == 1 && v[i] == 0){
                v[i] = 1;
                Q_push(i);
                
            }
        }
    }
}

int main(){
    int x, y;
    fscanf(in, "%d %d", &n, &s);
    while(fscanf(in, "%d %d", &x, &y) != EOF){
        G[x][y] = G[y][x] = 1;
    }
    BFS();
    fclose(in);
    fclose(out);
}
