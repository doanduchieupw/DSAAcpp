#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* pLeft;
    Node* pRight;
};

typedef struct Node NODE;
typedef NODE* TREE;

/*---------------1_Khoi tao cay nhi phan---------------*/
void initTree(TREE& tree);

/*---------------2_Tao node----------------------------*/
Node* createNode(int data);

/*---------------3_Them node vao cay-------------------*/
void addNode(TREE& tree, int data);

/*---------------4_Duyet cay nhi phan------------------*/
void printNLR(TREE tree);

/*---------------5_Tim kiem nhi phan-------------------*/
Node* searchNode(TREE tree, int x);

/*---------------6_Xoa node nhi phan-------------------*/
void delNode(TREE &tree, int x);

void Menu(TREE& tree);


#endif