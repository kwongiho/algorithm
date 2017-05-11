#include<stdio.h>
#include "Stack.hpp"
#include<stdlib.h>
#include<assert.h>

  void push(int value);
 int pop();
 int peek();
 int inputValue(char *);
 void fflush(); 
char description[][50] ={"1. value add","2. value pop","3. value peek","4 print size","5. exit"}; 
/**  * delete is already used in system.  */

 Stack * createStack();
 Node * createNode(); 
 Stack * stack ; 

int main() { 
    int i=0,
        selectedIndex=0,
        arraySize = sizeof(description)/ sizeof(description[0]),
        printfValue = 0; 
    stack = createStack(); 
    while(true) { 
        for(int i=0;i<arraySize;i++) 
            printf("%s\n",description[i]);  
        switch(inputValue("메뉴를 선택해 주세요 : ")) {
            case 1: push( inputValue("추가할 숫자를 입력해 주세요 : ") ); break;
            case 2 : printfValue = pop(); printf("pop value - %d\n",printfValue); break;
            case 3 : printfValue = peek(); printf("peek value - %d\n",printfValue); break;
            case 4 : printf("stack size = %d\n",stack->size); break;
            case 5 : return 0;
            default : continue;
        }

    }
  } 
void push( int value ) { 
    Node * newNode = createNode();
     newNode->value=value;
    if(stack->top!=NULL) 
        newNode->next = stack->top; 
    stack->top = newNode; 
    stack->size++;
} 
int pop() { 
    int value = stack->top->value; 
    Node * node = stack->top; 
    stack->top = stack->top->next; 
    stack->size--;
    free(node); 
    return value; 
}
 Node * createNode() { 
    Node * ptr = (Node *)malloc(sizeof(Node)); 
    assert(ptr); 
    ptr->next=NULL; 
    return ptr;
}
 Stack * createStack() { 
    Stack * ptr = (Stack *)malloc(sizeof(Stack)); 
    assert(ptr); 
    ptr->top=NULL; 
    ptr->size=0;
    return ptr; 
}
int peek() {
    return stack->top->value;
}
 int inputValue(char * str){ 
    int res =0,
            insertValue = 0;  
    while(res!=1) {  
        printf("%s\n", str); 
        res = scanf(" %d", &insertValue ); 
        fflush();  
    } 
    return insertValue; 
}
 void fflush(){ 
    while(getchar()!='\n');
}

