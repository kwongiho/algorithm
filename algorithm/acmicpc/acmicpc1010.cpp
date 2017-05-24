#include<cstdio>
int main()
{
    int ary[31][31], input, N, M;
    for (int i = 0; i < 31; i++)
        for (int j = 0; j < 31; j++)
            ary[i][j] = 0;

    for (int i = 0; i < 31; i++)
        ary[1][i] = i;

    for (int i = 2; i < 31; i++)
        for (int k = i; k < 31; k++)
            for (int l = k-1; l >= i-1; l--)
                ary[i][k] += ary[i - 1][l];

    scanf("%d",&input);
    for (int i = 0; i < input; i++)
    {
        scanf(" %d %d",&N,&M);
        printf("%d\n",ary[N][M]);
    }
    return 0;
}

