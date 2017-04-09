#include<stdio.h>
#define SWAP(a,b) {int t=a;a=b;b=t;}
void quickSort(int *, int left , int right);
void insertionSort(int *,int );
int main(){
    int array[] ={6,7,4,2,1,9,5,8,3,10};
    int itemSize = sizeof(array)/sizeof(array[0]) , i = 0;
    //quickSort(array,0,itemSize-1);
    insertionSort(array,itemSize);
    for(i=0 ; i < itemSize ; i++ )
        printf("%3d",array[i]);
}
void insertionSort ( int *array, int size )
{
    int i, j, remember;
    for ( i = 1; i < size; i++ )
    {
        remember = array[(j=i)];
        while ( --j >= 0 && remember < array[j] )
            array[j+1] = array[j];
        array[j+1] = remember;
    }
}
