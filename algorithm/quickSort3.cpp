#include<stdio.h>
#define SWAP(a,b) {int t=a;a=b;b=t;}
void quickSort(int *, int left , int right);
int main(){
    int array[] ={6,7,4,2,1,9,5,8,3,10};
    int itemSize = sizeof(array)/sizeof(array[0]) , i = 0;
    quickSort(array,0,itemSize-1);
    for(i=0 ; i < itemSize ; i++ )
        printf("%3d",array[i]);
}
void quickSort(int *ary, int left, int right) {
    int i = left, j = right;
    int pivot = ary[left];

    while( i <= j ) {
        while (ary[i] < pivot)
            ++i;
        while (ary[j] > pivot)
            --j;
        if (i<= j) {
            SWAP(ary[i],ary[j]);
            ++i;
            --j;
        }
    }
    /* recursion */
    if (left < j)
        quickSort(ary, left, j);

    if (i < right)
        quickSort(ary, i, right);
}
