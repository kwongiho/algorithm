#include <stdio.h>

#define SWAP(a,b)  {int t; t = a; a=b; b=t;}

//global
int *origin;
int arraySize ;

void shellSort(int *base, int n);
void insertionSort2(int *base, int size, int step);
void viewArray(int *arr, int n);
void main()
{
    int arr[] = { 9,4,3,10,5,8,7,6,2,1 };
    origin = arr;
    arraySize = sizeof(arr)/sizeof(arr[0]);
    shellSort(arr, 10);
}
void shellSort(int *base, int size)
{
    int i, step;

    for (step = size / 2; step>0; step /= 2)//step의 폭을 1/2로 줄여간다.
    {
        printf("step:%d\n", step);
        for (i = 0; i<step; i++) //step 간격에 있는 요소들을 삽입정렬
            insertionSort2(base + i, size - i, step);
    }
}
void insertionSort2(int *base, int size, int step)
{
    int i, j;
    /**
     *
     */
    for (i = step; i<size; i += step)//정렬 대상 원소는 step 간격으로 이동
        for (j = i; j>0; j -= step)//step 간격으로 앞으로 이동
            if (base[j - step]>base[j])//앞쪽이 더 클 때
            {
                SWAP(base[j - step], base[j]);//교환
                viewArray(origin, arraySize );
            }
}
void viewArray(int *arr, int n)
{
    int i = 0;
    for (i = 0; i<n; i++)
        printf("%2d ", arr[i]);
    printf("\n");
}
