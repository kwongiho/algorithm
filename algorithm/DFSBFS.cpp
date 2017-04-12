#include<stdio.h>
bool t[1001][1001];
bool t_v[1001];//dfs에서 사용할 visit
bool t_vv[1001];//bfs에서 사용할 visit
int que[1001];
int n, m, v;
int front = 0;
int rear = 0;
int b=0;
void dfs(int);
void bfs(int);

int main(){
    int a,b;
    scanf(" %d%d%d",&n,&m,&v);
    for (int i = 0; i <m ; i++){
        scanf(" %d%d",&a,&b);
        t[b][a]=t[a][b] = true;
    }

    dfs(v);
    printf("\n");

    bfs(v);
    printf("\n");

}
void dfs(int a){
    t_v[a]=true;
    printf("%d ",a);
    for (int i = 1; i <= 1000; i++)
        if (!t_v[i] && t[a][i])
            dfs(i);
}
void bfs(int a){
    t_vv[a] = true;
    que[rear ++ ] = a;
    while (front != rear){
        printf("%d ",b=que[front++]);
        for (int i = 1; i <=1000 ; i++)
            if (!t_vv[i] && t[b][i]){
                que[rear++] = i;
                t_vv[i] = true;
            }
    }
}

