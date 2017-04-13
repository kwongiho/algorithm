/* 
alloc을 사용한 BFS DFS
https://www.acmicpc.net/problem/1260 에서는 메모리초과 발생. 
*/
#include<stdio.h>
#include<stdlib.h>
bool ** t;
bool * t_v;
bool * t_vv;
int que[1001];
int n, m, v;
int front = 0;
int rear = 0;
int b=0;
void dfs(int);
void bfs(int);
void init();
int main(){
    int a,b;
    init();
    for(int i=1;i<=n;i++) {
        t[i]=(bool*) calloc(n,n*sizeof(bool));
    }
    for (int i = 0; i <m ; i++){
        scanf(" %d%d",&a,&b);
        t[b][a]=t[a][b] = true;
    }
    dfs(v);
    printf("\n");
    bfs(v);
    printf("\n");
}
void init(){
    scanf(" %d%d%d",&n,&m,&v);
    t = (bool**) calloc(n,n*sizeof(bool*));
    t_v=(bool*) calloc(n,n*sizeof(bool));
    t_vv=(bool*) calloc(n,n*sizeof(bool));
}
void dfs(int a){
    t_v[a]=true;
    printf("%d ",a);
    for (int i = 1; i <= n; i++)
        if (!t_v[i] && t[a][i])
            dfs(i);
}
void bfs(int a){
    t_vv[a] = true;
    que[rear ++ ] = a;
    while (front != rear){
        printf("%d ",b=que[front++]);
        for (int i = 1; i <=n ; i++)
            if (!t_vv[i] && t[b][i]){
                que[rear++] = i;
                t_vv[i] = true;
            }
    }
}

