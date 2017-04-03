//If you want to operate this program, you will be using GCC compiler and this program requrie int agument
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(a,b)  {int t; t = a; a=b; b=t;}//a와 b를 교환


void ShellSort(int *base, int n);
void InsertionSort2(int *base, int size, int step);
void InsertionSort(int *base, int n);
void ShellSort(int *base, int n);
void bubbleSort(int *base, int n);
int main(int argc , char* argv[])
{
   if (argc == 0) {
      fputs("옵션을 입력하지 않았습니다.",stderr);
      exit(1);
   }
   int inputValue = atoi(argv[1]);

   
   int *ary , *ary2, *ary3 , i=0;
   ary = (int *)calloc(inputValue, sizeof(int));
   ary2 = (int *)calloc(inputValue, sizeof(int));
   ary3 = (int *)calloc(inputValue, sizeof(int));
   
   double result;
   clock_t before;
   for (i = 0; i < inputValue; i++) {
      ary3[i] = ary2[i] = ary[i] = rand() % inputValue;
   }
   printf("ShelSort Start.. ");
   before = clock();
   ShellSort(ary, inputValue);
   result = (double)(clock() - before) / CLOCKS_PER_SEC;
   printf("result time - %f\n", result ) ;

   printf("InsertionSort Start.. ");
   before = clock();
   InsertionSort(ary2, inputValue );
   result = (double)(clock() - before) / CLOCKS_PER_SEC;
   printf("result time - %f\n", result);

   printf("BubbleSort Start.. ");
   before = clock();
   bubbleSort(ary3, inputValue );
   result = (double)(clock() - before) / ((double)CLOCKS_PER_SEC);
   printf("result time - %lf\n", result);

   return 0;
}

void ShellSort(int *base, int size)
{
   int i, step;
   for (step = size / 2; step>0; step /= 2)//step의 폭을 1/2로 줄여간다.
      for (i = 0; i<step; i++) //step 간격에 있는 요소들을 삽입정렬
         InsertionSort2(base + i, size - i, step);
}

void InsertionSort2(int *base, int size, int step)
{
   int i, j;
   for (i = step; i<size; i += step)//정렬 대상 원소는 step 간격으로 이동
      for (j = i; j>0; j -= step)//step 간격으로 앞으로 이동
         if (base[j - step]>base[j])//앞쪽이 더 클 때
         {
            SWAP(base[j - step], base[j]);//교환
         }
         else
            break;
}

void InsertionSort(int *base, int n)
{
   int i, j;
   for (i = 1; i<n; i++)//정렬할 범위를 확대
      for (j = i; j>0; j--)
         if (base[j - 1]>base[j])//앞쪽 원소가 더 크면
         {
            SWAP(base[j - 1], base[j]);//교환
         }
         else
            break;
}
void bubbleSort(int *base, int n) {
   int i, j;
   for (i = 0; i < n; i++) 
      for (j = 0; j < n; j++)
         if (base[i] < base[j])
            SWAP(base[i], base[j]);
}
