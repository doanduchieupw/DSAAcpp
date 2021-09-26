#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* pNext;
    Node* pPrev;
};

struct List
{
    Node* pHead;
    Node* pTail;
};

/*---------------1_Khoi tao danh sach---------------*/
void initList(List& lst);

/*---------------2_Tao node-------------------------*/
Node* createNode(int data);

/*---------------3_Kiem tra trang thai--------------*/
bool checkEmpty(List lst);

/*---------------4_Chen dau danh sach---------------*/
void addHead(List& lst, int x);

/*---------------5_Chen cuoi danh sach--------------*/
void addTail(List& lst, int x);

/*---------------6_Chen vi tri bat ky---------------*/
void addAt(List& lst, int idx, int x);

/*---------------7_So luong phan tu trong List------*/
int getSize(List lst);

/*---------------8_In danh sach---------------------*/
void printList(List lst);

/*---------------9_Xoa dau danh sach----------------*/
void delHead(List& lst);

/*---------------10_Xoa cuoi danh sach--------------*/
void delTail(List& lst);

/*---------------11_Xoa vi tri bat ky --------------*/
void delAt(List& lst, int idx);

#endif