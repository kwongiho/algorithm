//
// Created by Kwongiho on 2017. 5. 2..
//

#ifndef UNTITLED_STACK_HPP_H
#define UNTITLED_STACK_HPP_H

typedef struct _Node Node;
typedef struct _Stack Stack;
struct _Node{
    int value;
    Node * next;
};
struct _Stack {
    Node * top;
    int size;
};


#endif //UNTITLED_STACK_HPP_H

