#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
struct Node
{
    Node *prev;
    char name[20];
    Node *next;
};
typedef struct _linkedlist
{
    Node *headp;
    Node *tailp;
    Node *curp;
    int len;
}LinkedList;

void fflush();
char * getString(char *);
char tolower(char);
void create(LinkedList *);
void sortList(LinkedList *);
void Destroy(LinkedList *);
void display(LinkedList *);
void input(LinkedList *);
void search(LinkedList *);
void Delete(LinkedList *);
void Addinfo(LinkedList *);
bool isVariable(int value);
int inputIntValue(char *);

Node * appendFromHead(LinkedList *,char *);
Node * appendFromTail(LinkedList *,char *);
Node * insertBefore(LinkedList *,char *);
Node * inserAfter(LinkedList *,char *);
Node * deleteNode(LinkedList *,Node *);
Node * searchUnique(LinkedList *,char *);
char description[][50] ={"1. 값 입력하기","2. 값 출력하기","3. 값 검색하기","4. 값 삭제하기","5. 값 소트하기","6. 값 추가하기","7. 종료하기"};
int size = sizeof(description)/ sizeof(description[0]);
int main()
{
    int menu,
        i=0;
    LinkedList list;
    create(&list);


    while(1)
    {
        for(i = 0 ; i < size ; i ++)
            printf("%s\n",description[i]);
        menu = inputIntValue(" # 메뉴를 선택하세요 : ");
        if(!isVariable(menu))
            continue;
        switch(menu)
        {
            case 1 : input(&list);break;
            case 2 : display(&list);break;
            case 3 : search(&list);break;
            case 4 : Delete(&list);break;
            case 5 : sortList(&list);break;
            case 6 : Addinfo(&list);break;
            case 7 : Destroy(&list); return 0;
        }

    }
}
void create(LinkedList *lp)
{
    lp->headp= (Node *) malloc(sizeof(Node));
    assert(lp->headp!=NULL);
    lp->tailp=(Node *)malloc(sizeof(Node));
    assert(lp->tailp!=NULL);
    lp->headp->next=lp->tailp; // head노드를 tail노드로 가르킴.
    lp->tailp->prev=lp->headp; // tail노드를 head노드로 가르킴.
    lp->headp->prev=lp->headp; // head노드의 첫 포인터를 자신을 가르키게 함.
    lp->tailp->next=lp->tailp; // tail노드의 뒷 포인터를 자신을 가르키게 함.
    lp->curp=NULL;
    lp->len=0;
}


void input(LinkedList *lp)
{
    char NameTemp[20];
    char yn;
    int res;


    printf("성명을 입력하세요  : ");
    getString(NameTemp);


    while(1)
    {
        printf("맨 앞에 추가할까요(Y/N) : ");
        res=scanf(" %c",&yn);
        if(res!=1)
            continue;
        if ( tolower(yn)=='y' ) {
            appendFromHead(lp,NameTemp);
            break;
        }
        else if( tolower(yn)=='n') {
            appendFromTail(lp,NameTemp);
            break;
        }

    }


}
Node * appendFromHead(LinkedList *lp,char *NameTemp)
{
    lp->curp=(Node *)malloc(sizeof(Node));
    assert(lp->curp!=NULL);
    lp->curp->prev=lp->headp; // 노드 왼팔 뻗음.
    lp->curp->next=lp->headp->next;//노드 오른팔 뻗음.
    lp->headp->next=lp->curp;
    lp->headp->next->next->prev=lp->curp;
    strcpy(lp->curp->name,NameTemp);
    lp->len++;
    return lp->curp;

}
Node * appendFromTail(LinkedList *lp,char *NameTemp)
{
    lp->curp=(Node *)malloc(sizeof(Node));
    assert(lp->curp!=NULL);
    lp->curp->next=lp->tailp; // 노드 오른팔 뻗음.
    lp->curp->prev=lp->tailp->prev; // 노드 왼팔 뻗음.
    lp->tailp->prev->next=lp->curp; // 왼팔을 잡아줌.
    lp->tailp->prev=lp->curp;
    strcpy(lp->curp->name,NameTemp);
    lp->len++; // 노드 1개 추가하라는 뜻.
    return lp->curp; // 임시 return code


}
void display(LinkedList *lp)
{
    int i=1;

    lp->curp=lp->headp->next;
    while(lp->curp!=lp->tailp)
    {
        printf("%d 번째의 사람 이름 : %s\n",i++,lp->curp->name);
        lp->curp=lp->curp->next;
    }

}
void search(LinkedList *lp)
{
    char searchTemp[20];


    printf("찾으실분 이름을 입력하세요 : ");
    getString(searchTemp);

    if( searchUnique(lp,searchTemp) !=NULL)
        printf("%s씨는 존재합니다.\n",lp->curp->name);
    else
        printf("%s씨는 존재하지 않습니다. \n",searchTemp);

}
Node * searchUnique(LinkedList *lp, char *searchTemp)
{
    lp->curp=lp->headp->next;
    while(lp->curp != lp->tailp)
    {
        if(strcmp(lp->curp->name,searchTemp)==0) // 만약 찾는 이름이 있다면
            return lp->curp;// 그 주소 리턴
        lp->curp=lp->curp->next; // 다음 포인터 ㄱ
    }
    return NULL;

}

void Delete(LinkedList *lp)
{
    char DeleteTemp[20];

    printf("삭제할 사람의 이름을 입력하세요. : ");
    getString(DeleteTemp);

    if( searchUnique(lp,DeleteTemp)!=NULL )
    {
        deleteNode(lp,lp->curp);
        printf("%s씨가 삭제되었습니다 \n",DeleteTemp);
    }
    else
        printf("%s씨는 존재하지 않습니다\n",DeleteTemp);

}
Node * deleteNode(LinkedList *lp,Node *DeleteCurp)
{
    lp->curp->next->prev=lp->curp->prev;
    lp->curp->prev->next=lp->curp->next;

    free(DeleteCurp);
    return NULL;
}
void Destroy(LinkedList *lp)
{
    lp->curp=lp->headp->next;// 노드 첫 위치로 이동.
    while(lp->curp!=lp->tailp) // 꼬리노드까지 이동
    {
        free(lp->curp->prev);//head 노드부터 tail노드 이전까지 다 삭제
        lp->curp=lp->curp->next;//다음 노드로 이동.
    }

    free(lp->tailp->prev);
    free(lp->tailp);
}
void sortList(LinkedList *lp)
{
    char sort[20];
    Node * temp;
    lp->curp=lp->headp->next; // curp가 가르키는곳을 정보가 있는 첫 노드로 변경
    temp=lp->curp->next;
    while(lp->curp != lp->tailp->prev)
    {

        while(temp!= lp->tailp)
        {
            if( strcmp(lp->curp->name , temp->name)>0)
            {
                strcpy( sort,lp->curp->name);
                strcpy( lp->curp->name , temp->name);
                strcpy( temp->name, sort);
            }
            temp=temp->next;
        }
        lp->curp=lp->curp->next;
        temp=lp->curp->next;
    }


}
void Addinfo(LinkedList *lp)
{
    char SearchName[20];
    char temp[20];
    char fb;
    int res;

    printf("누구 기준으로 추가할까요? : ");
    getString(SearchName);

    if( searchUnique(lp,SearchName)==NULL)
    {
        printf(" %s씨는 존재하지 않습니다.\n",SearchName);
        return ;
    }


    printf("추가할 사람의 이름을 입력하세요 : ");
    getString(temp);
    while(1)
    {
        printf("%s씨의 앞('F'ront)에 추가할까요 뒤('B'ack)에 추가할까요 ? : ",SearchName);
        res=scanf(" %c",&fb);fb=tolower(fb);
        if(res!=1)
            continue;
        else if(fb=='f' || fb=='b')
            break;
    }
    if(fb=='f')
        insertBefore(lp,temp);
    else
        inserAfter(lp,temp);


}
Node * insertBefore(LinkedList *lp,char *temp)
{
    Node *tp;
    tp=(Node *)malloc(sizeof(Node));
    assert(tp!=NULL);
    strcpy(tp->name,temp);
    tp->next=lp->curp;
    tp->prev=lp->curp->prev;
    lp->curp->prev->next=tp;
    lp->curp->prev=tp;
    return NULL;
}
Node * inserAfter(LinkedList *lp,char *temp)
{
    Node *tp;
    tp=(Node *)malloc(sizeof(Node));
    assert(tp!=NULL);
    strcpy(tp->name,temp);
    tp->prev=lp->curp;
    tp->next=lp->curp->next;
    lp->curp->next->prev=tp;
    lp->curp->next=tp;
    return NULL;

}
void fflush(){
    while(getchar()!='\n');
}

int inputIntValue(char * str){
    int res =0,
        value = 0;

    while(res!=1) {

        printf("%s\n", str);
        res = scanf(" %d", &value );
        fflush();

    }

    return value;
}
bool isVariable(int value){
    //printf(" if( value<=0 || linkedList->size(%d)<%d) =>%d",linkedList->size,value,( value<=0 || linkedList->size<value)); // for debug
    if( value<=0 || size < value)
        return false;
    return true;
}
/**
 * i donno why the return type is char *
 * but the basic library provide the return type and too, provide same return type.
 * and the return can change in future when i know why using the return type.
 */
char * getString(char * target) {
    int i=0;
    while( (target[i++] = getchar())!='\n' );
    target[i]='\0';
    return target;
}
char tolower(char ch) {
    if(ch>='A' && ch<='Z')
        ch+=32;
    return ch;
}

