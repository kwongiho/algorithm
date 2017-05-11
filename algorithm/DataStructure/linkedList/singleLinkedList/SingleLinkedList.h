//
// Created by Kwongiho on 2017. 4. 18..
//
#pragma once
#pragma waring(disable : 4996)
#ifndef UNTITLED_SINGLELINKEDLIST_H
#define UNTITLED_SINGLELINKEDLIST_H
typedef struct Node node;
typedef struct LinkedListStatus LinkedList ;
struct LinkedListStatus {
    Node * hp;
    Node * cp;
    Node * tp;
    int size;
} ;
struct Node  {
    int value;
    Node * next;
} ;


#endif //UNTITLED_SINGLELINKEDLIST_H
