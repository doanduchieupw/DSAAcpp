#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node *pNext;    
};

struct List
{
    Node *pHead;
    Node *pTail;
};

//Create node
Node* createNode(int data);

//Create list
void initList(List& lst);

//Check linked list null
bool checkEmpty(List lst);

//add head
void addHead(List& lst, Node* pNode);
void addHead(List& lst, int n);

//add tail
void addTail(List& lst, Node* pNode);
void addTail(List& lst, int n);

//chen vao vi tri bat ky 
void addAt(List& lst, Node* q, Node* pNewNode);
void addAt(List& lst, int idx, Node* pNewNode);

//check list
void printList(List lst);

//get size 
int getSize(List lst);

//search node
Node* searchNode(List lst,int k);

//chen node x sau node co gia tri bang k
void addMid(List& lst, int x, int k);

//delete node head
void delHead(List& lst);

//delete node tail
void delTail(List& lst);

//delete node bat ky
void delAt(List& lst, int idx);
#endif