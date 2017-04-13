/* 
Baekjoon online judge problem and my answer
https://www.acmicpc.net/problem/11404  */
#include<stdio.h>
int city;
int bus;
int graph[101][101];
void floyed();
void init();
int main() {
    int i = 0, j = 0, a = 0, b = 0, c = 0;
    scanf("%d%d", &city, &bus);
    init();
    for (i = 0; i < bus; i++) {
        scanf("%d%d%d", &a, &b, &c);
        if(graph[a][b]>c) graph[a][b] = c;
    }
    floyed();
}
void floyed() {
    for (int i = 1; i <= city; i++)
        for (int j = 1; j <= city; j++)
            for (int k = 1; k <= city; k++)
                if (j!=k && graph[j][k] > graph[j][i] + graph[i][k])
                    graph[j][k] = graph[j][i] + graph[i][k];
    for (int i = 1; i <= city; i++) {
        for (int j = 1; j <= city; j++)
            if (graph[i][j] == 999999)
                printf("0 ");
            else
                printf("%d ", graph[i][j]);
        printf("\n");
    }
}
void init() {
    for (int i =1; i <= city; i++)
        for (int j = 1; j <= city; j++)
            graph[i][j] = 999999;
}
