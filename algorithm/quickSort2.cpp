#include<stdio.h>
#define SWAP(a,b) { int t;t=a;a=b;b=t;}
void quickSort(int *,int,int);
int main() {
    int ary[] ={1,9,4,7,6,8,2,3,5,10},
            i = 0;
    quickSort(ary , 0 , (sizeof(ary)/sizeof(ary[0])) - 1 );

    for(i=0;i<sizeof(ary)/sizeof(ary[0]) ; i++)
        printf("%3d",ary[i]);
    return 0;
}
void quickSort(int *ary ,int left , int right) {
    int pivot = left,
            j = pivot,
            i = left+1;

    if(left < right) {
        for (; i <= right; i++)
            if (ary[i] < ary[pivot]) {
                j++;
                SWAP(ary[j], ary[i]);
            }

        SWAP(ary[left],ary[j]);
        pivot = j;
        quickSort(ary,left,pivot-1);
        quickSort(ary,pivot+1,right);
    }
}
