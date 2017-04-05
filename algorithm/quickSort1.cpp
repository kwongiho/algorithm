#include<stdio.h>
void quickSortStart(int * , int size);
void quickSort(int *, int left , int right);
int main(){
    int array[] ={1,6,2,3,9,7,8,4,5,10};
    int itemSize = sizeof(array)/sizeof(array[0]) , i = 0;
    quickSortStart(array,itemSize);
    for(i=0 ; i < itemSize ; i++ )
        printf("%3d",array[i]);
}
void quickSortStart(int *array , int size) {
    quickSort(array , 0, size-1 );
}
void quickSort(int *array, int left , int right) {
    int pivot , leftHold , rightHold ;
    leftHold = left ;
    rightHold = right;

    pivot = array[left];

    while(left<right) {
        while( (array[right] >= pivot ) && (left<right) )
            --right;

        if(left!=right)
            array[left]=array[right];

        while( (array[left] <=pivot) && (left < right)  )
            ++left;

        if(left!=right)
            array[right--] = array[left];
    }

    array[left] = pivot;
    pivot = left;
    left = leftHold;
    right = rightHold;
    if(left<pivot)
        quickSort(array,left,pivot-1);
    if(right>pivot)
        quickSort(array,pivot+1,right);
}
