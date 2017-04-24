#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "SingleLinkedList.h"
#define SWAP(a,b) {int t=a;a=b;b=t;}
Node * createNode();
LinkedList * createLinkedList();
void deleteNode();
void updateNode();
int inputValue(char *);
void addLastNode();
void nodePrint();
int programExit();
void fflush();
bool isVariable(int);
void sortByValue();
void reverse();
char description[][50] ={"1. 값 추가하기","2. 값 삭제하기","3. 값 업데이트","4. 값 출력하기","5. 값 정렬하기","6. 값 뒤집기","7. 종료"};
LinkedList * linkedList;

int main() {
    int i=0,
        selectedIndex=0,
        arraySize=sizeof(description)/ sizeof(description[0]);

    linkedList = createLinkedList();
    linkedList->hp = NULL;
    linkedList->cp = NULL;
    linkedList->tp = NULL;
    linkedList->size=0;

    while(true) {

        for(i = 0 ; i < arraySize;i++)
            printf("%s\n",description[i]);

        selectedIndex = inputValue("메뉴를 선택해 주세요 : ");
        if(selectedIndex <=0 || selectedIndex >=arraySize)
            continue;
        switch( selectedIndex ) {
            case 1 : addLastNode(); break;
            case 2 : deleteNode(); break;
            case 3 : updateNode(); break;
            case 4 : nodePrint(); break;
            case 5 : sortByValue(); break;
            case 6 : reverse(); break;
            case 7 : return programExit(); 
        }

    }
}
LinkedList * createLinkedList(){

    LinkedList * linkedList = (LinkedList *) malloc(sizeof(LinkedList));

    assert(linkedList);

    return linkedList;

}
Node * createNode() {

    Node * node = (Node *)malloc( sizeof ( Node ) );

    assert(node);

    return node;
}

void addLastNode() {
    Node* node = createNode();

    node->value = inputValue("값을 하나 입력해주세요 : ");
    node->next=NULL;

    if( linkedList -> hp == NULL ) {

        linkedList->hp = node;
        linkedList->cp = node;
        linkedList->tp = node;
        return;

    }
    linkedList->tp->next=node;
    linkedList->tp=node;
    linkedList->size++;
}
void updateNode() {
    int updateNode = 0 ;

    while(!isVariable(updateNode))
        updateNode = inputValue("값을 변경할 노드의 번호를 입력해 주세요.");
    linkedList->cp=linkedList->hp;
    while(--updateNode)
        linkedList->cp=linkedList->cp->next;
    linkedList->cp->value = inputValue("값을 하나 입력해 주세요 : ");

}
void deleteNode() {

    int deleteNodeNo = 0;

    while(!isVariable(deleteNodeNo))
        deleteNodeNo = inputValue("삭제할 노드의 번호를 입력해 주세요"); // 삭제할 노드를 입력받음

    Node * tempNode=NULL; // SingleLinkedList는 단방향의 자료구조이므로 Node의 address를 저장할 포인터변수 선언

    linkedList->cp = linkedList->hp; // 맨 앞부터 달릴거야

    /* 이전 노드를 가르키는 포인터가 없기때문에 일부러 index -1이전에서 끝내고 연결해주기 위해 */
    while(--deleteNodeNo-1)
        linkedList->cp=linkedList->cp->next;

    tempNode = linkedList->cp->next;

    linkedList->cp->next=linkedList->cp->next->next;

    free(tempNode);

    linkedList->size--;
}
void nodePrint() {
    int i=0;

    linkedList->cp=linkedList->hp;

    do{

        printf("%d번째 노드 값 : %d\n", ++i, linkedList->cp->value);

        linkedList->cp = linkedList->cp->next;

    }while(linkedList->cp!=NULL);
}

int programExit() {
    return 0;
}

int inputValue(char * str){
    int res =0,
    inputValue = 0;

    while(res!=1) {

        printf("%s\n", str);
        res = scanf(" %d", &inputValue );
        fflush();

    }
    return inputValue;
}
/**
 * Check the index before can change index
 * @param value
 * @return
 */
bool isVariable(int value){
    //printf(" if( value<=0 || linkedList->size(%d)<%d) =>%d",linkedList->size,value,( value<=0 || linkedList->size<value)); // for debug
    if( value<=0 || linkedList->size<value-1)
        return false;
    return true;
}
void fflush(){
    while(getchar()!='\n');
}
/**
 * The node never changed
 * Just change each value.
 * will changed to insertSort or mergeSort
 */
void sortByValue() {
    int i=0,j=0;
    Node * suppoter;

    linkedList->cp=linkedList->hp;
    for(i=0;i<=linkedList->size;i++) {
        suppoter = linkedList->cp;
        for(j=i;j<=linkedList->size;j++) {
            if(suppoter->value < linkedList->cp->value)
                SWAP(suppoter->value,linkedList->cp->value);
            suppoter=suppoter->next;
        }
        linkedList->cp = linkedList->cp->next;
    }
}
void reverse(){
    Node * nn;//nextNode
    Node * cn;//currentNode
    Node * pn; //preNode
    nn = linkedList->hp;
    cn = NULL;
    pn = NULL;
    while(nn!=NULL) {
        pn = cn;
        cn = nn;
        nn = nn->next;
        cn->next=pn;
    }
    linkedList->hp=cn;

}
