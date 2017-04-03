#include <stdio.h>
#include <stdlib.h>

int * mergeAry ; // for merge

void divideForMerge(int *,int,int);
void merge(int *,int ,int);
int main(){

    int ary[]={1,9,5,4,6,3,7,8,2,10} , i=0 ;

    mergeAry = (int *) calloc( sizeof(ary)/sizeof(ary[0]) , sizeof(int) );
    printf("array size = %d\n",sizeof(ary)/sizeof(ary[0]));
    printf("show original array  \n");
    for(i = 0 ; i < sizeof(ary)/sizeof(ary[0]) ; i ++)
        printf("%3d",ary[i]);

    divideForMerge( ary , 0 ,sizeof(ary) /sizeof(ary[0]));

    printf(" \nresult \n ");
    for( i = 0 ; i < sizeof(ary) /sizeof(ary[0]);i++)
        printf("%3d",mergeAry[i]);
    return 0;
}
void divideForMerge(int * ary , int start , int end) {
    if( end > start ) {
        int mid = (start + end) / 2; // 배열의 중간 인덱스 get
        divideForMerge(ary, start, mid); // 배열 전체 리스트를 반으로 분할
        divideForMerge(ary, mid + 1, end); // 상동
        merge(ary, start, end);
    }
}
void merge(int * ary , int start , int end) {
    int mid = (start+end)/2/*배열의 끝 인덱스*/ ,
            i = start /*배열의 시작 인덱스*/,
            j = mid + 1/*두번째 배열의 시작 인덱스 */,
            k = start /*mergeSort배열의 시작 인덱스*/,
            t = 0;

    while( i <= mid && j <= end) // 두 배열이 끝날때 까지
        if(ary[i] <= ary[j] ) // 첫번째 배열의값이 두번째 배열의 값보다 작거나 같으면
            mergeAry[k++] = ary[i++]; //배열에 값 추가
        else // 두번째 배열의 값이 더 작거나 같으면
            mergeAry[k++] = ary[j++]; // 배열에 값 추가

    if(i>mid) //첫번째 배열의 값이 모두 추가되면
        t=j; //시작 인덱스를 두번째 배열의 인덱스로 설정
    else // 두번째 배열의 값이 모두 추가되었으면
        t=i; // 시작 인덱스를 첫번째 배열의 시작 인덱스로 설정

    for(;k<=end ;k++,t++) mergeAry[k] = ary[t];

    for(k=0;k<=end;k++) ary[k]=mergeAry[k]; // 원래 배열로 복사

}
