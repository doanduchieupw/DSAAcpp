#include "circular_linked_list.h"

/*---------------1_Khoi tao danh sach---------------*/
void initList(List& lst) 
{
    lst.pHead = NULL;
}

/*---------------2_Tao node-------------------------*/
Node* createNode(int data)
{
    Node *pNode = new Node;
    if (pNode == NULL) return NULL;
    
    pNode->data = data;
    pNode->pNext = NULL;
    return pNode;
}


/*---------------3_Kiem tra trang thai--------------*/
bool checkEmpty(List lst)
{
    return (lst.pHead == NULL);
}

/*---------------4_Chen dau danh sach---------------*/
void addHead(List& lst, int x)
{
    Node* pNode = createNode(x);
    if (lst.pTail == NULL) lst.pHead = lst.pTail = pNode;
    else 
    {
        pNode->pNext = lst.pHead;   //con tro pNext tro vao node dau tien cua List
        lst.pHead->pNext = pNode;   //con tro prev tro vao node moi them vao
        lst.pHead = pNode;          //cap nhat lai node
    }
}