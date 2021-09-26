#include "double_linked_list.h"

/*---------------1_Khoi tao danh sach---------------*/
void initList(List& lst) 
{
    lst.pHead = lst.pTail = NULL;
}

/*---------------2_Tao node-------------------------*/
Node* createNode(int data)
{
    Node *pNode = new Node;
    if (pNode == NULL) return NULL;
    
    pNode->data = data;
    pNode->pPrev = NULL;
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
    if (checkEmpty(lst)) lst.pHead = lst.pTail = pNode;
    else
    {
        pNode->pNext = lst.pHead;   //con tro pNext tro vao node dau tien cua List
        lst.pHead->pPrev = pNode;   //con tro prev tro vao node moi them vao
        lst.pHead = pNode;          //cap nhat lai node
    }
}

/*---------------5_Chen cuoi danh sach--------------*/
void addTail(List& lst, int x)
{
    Node* pNode = createNode(x);
    if (checkEmpty(lst)) lst.pHead = lst.pTail = pNode;
    else
    {
        lst.pTail->pNext = pNode;
        pNode->pPrev = lst.pTail;
        lst.pTail = pNode;
    }
}

/*---------------6_Chen vi tri bat ky---------------*/
void addAt(List& lst, int idx, int x)
{
    Node* pNewNode = createNode(x);
    if (checkEmpty(lst)) lst.pHead = lst.pTail = pNewNode;
    else 
    {
        if(idx == 0) addHead(lst, x);
        else if (idx == getSize(lst) - 1) addTail(lst, x);
        else 
        {
            int idxCurrent = 0;
            Node* pNode = lst.pHead;
            while (pNode != NULL && idxCurrent < idx) 
            {
                idxCurrent++;
                pNode = pNode->pNext;
            }
            
            pNewNode->pNext = pNode->pNext;
            pNewNode->pPrev = pNode;
            pNode->pNext->pPrev = pNewNode;
            pNode->pNext = pNewNode;
        }
    }
}

/*---------------7_So luong phan tu trong List------*/
int getSize(List lst)
{
    if(!checkEmpty(lst)) 
    {
        Node* pNode = lst.pHead;
        int nCount = 0;
        while (pNode != NULL)
        {
            nCount++;
            pNode = pNode->pNext;
        }
        return nCount;
    } else return 0;
}

/*---------------8_In danh sach---------------------*/
void printList(List lst)
{
    if (checkEmpty(lst)) {
        cout << "Linked list is empty" << endl;
    } else {
        Node* pNode = lst.pHead;
        while (pNode != NULL)
        {
            cout << pNode->data << " ";
            pNode = pNode->pNext;
        } 
    cout << endl;    
    }
}

/*---------------9_Xoa dau danh sach----------------*/
void delHead(List& lst) 
{
    if (!checkEmpty(lst)) 
    {
        lst.pHead = lst.pHead->pNext;
        lst.pHead->pPrev = NULL;
    } else cout << "Khong co phan tu nao trong danh sach !!!" << endl;
}

/*---------------10_Xoa cuoi danh sach--------------*/
void delTail(List& lst)
{
    if(!checkEmpty(lst)) 
    {
        lst.pTail = lst.pTail->pPrev;
        lst.pTail->pNext = NULL;
    } else cout << "Khong co phan tu nao trong danh sach !!!" << endl;
}

/*---------------11_Xoa vi tri bat ky --------------*/
void delAt(List& lst, int idx)
{
    if(!checkEmpty(lst))
    {
        if(idx == 0) delHead(lst);
        else if (idx == getSize(lst) - 1) delTail(lst);
        else
        {
            int idxCurrent = 0;
            Node* pNode = lst.pHead;
            while(pNode != NULL && idxCurrent < idx)
            {
                idxCurrent++;
                pNode = pNode->pNext;
            }
            pNode->pPrev->pNext = pNode->pNext;
            pNode->pNext->pPrev = pNode->pPrev;
        }
    } else cout << "Khong co phan tu nao trong danh sach !!!" << endl;
}
