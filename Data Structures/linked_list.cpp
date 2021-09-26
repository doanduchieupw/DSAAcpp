#include "linked_list.h"

//Create node
Node* createNode(int data) {
    Node *node = new Node;
    if(node == NULL) {
        return NULL;
    }
    node->data = data;
    node->pNext = NULL;
    return node;
}

//Create list
void initList(List& lst) {
    lst.pHead = NULL;
    lst.pTail = NULL;
}

//Check linked list null
bool checkEmpty(List lst) {
    if (lst.pHead == NULL) {
        return true;
    }
    return false;
}

//add head
void addHead(List& lst, Node* pNode) {
    if (checkEmpty(lst)) {
        lst.pHead = lst.pTail = pNode;
    } else {
        pNode->pNext = lst.pHead;
        lst.pHead = pNode;
    }
}
void addHead(List& lst, int n) {
    Node* pNode = createNode(n);
    addHead(lst, pNode);
}
//add tail
void addTail(List& lst, Node* pNode) {
    if (checkEmpty(lst)) {
        lst.pHead = lst.pTail = pNode;
    } else {
        lst.pTail->pNext = pNode;
        lst.pTail = pNode;
    }
}
void addTail(List& lst, int n) {
    Node* pNode = createNode(n);
    addTail(lst, pNode);
}

//chen vao vi tri bat ky 
void addAt(List& lst, Node* q, Node* pNewNode) {
    if (checkEmpty(lst)) {
        lst.pHead = lst.pTail = pNewNode;
    } else {
        if (lst.pTail == q) {
            addTail(lst, pNewNode);
        } else {
            pNewNode->pNext = q->pNext;
            q->pNext = pNewNode;
        }
    }
}
void addAt(List& lst, int idx, Node* pNewNode) {
    if (checkEmpty(lst)) {
        lst.pHead = lst.pTail = pNewNode;
    } else {
        int idxCurrent = 0;
        Node* pNode = lst.pHead;
        if (pNewNode == NULL || idx < 0) {
            cout << "Invalid" << endl;
        } else {
            while(pNode != NULL && idxCurrent < idx) {
                idxCurrent++;
                pNode = pNode->pNext;
            }
        addAt(lst, pNode, pNewNode);
        }
    }
}

//check list
void printList(List lst) {
    if (checkEmpty(lst)) {
        cout << "Linked list is empty" << endl;
    } else {
        // cout << "Xuat ra danh sach" << endl;
        Node* node = lst.pHead;
        while (node != NULL)
        {
            cout << node->data << " ";
            node = node->pNext;
        } 
         
        cout << endl;    
    }
}

//get size 
int getSize(List lst) {
    if (checkEmpty(lst)) {
        return 0;
    } else {
        int nCount = 0;
        Node* node = lst.pHead;
        while (node != NULL)
        {
            nCount++;
            node = node->pNext;
        }
        return nCount;
    }    
}

//search node
Node* searchNode(List lst,int k) {
    Node* pNode = lst.pHead;
    while(pNode != NULL) {
        if(pNode->data == k) {
            return pNode;
        } else
        pNode = pNode->pNext; 
    }
    return NULL;
}

//chen node x sau node co gia tri bang k
void addMid(List& lst, int x, int k) {
    Node* pNode = searchNode(lst, k);
    Node* PNewNode = createNode(x);
    if (pNode != NULL) {
    addAt(lst, pNode, PNewNode);
    }
    else cout << "Invalid !" << endl;
}

//delete node head
void delHead(List& lst) {
    if(!checkEmpty(lst)) {
        Node* pNode = lst.pHead;
        lst.pHead = lst.pHead->pNext;
        delete pNode;
    } else cout << "Khong co phan tu trong list de xoa !!!" << endl;
}

//delete node tail
void delTail(List& lst) {
    if(!checkEmpty(lst)) {
        Node* pNode = lst.pHead;
        Node* tempNode = new Node;
        while(pNode->pNext != lst.pTail) {
            pNode = pNode->pNext; //tim node ngay truoc tail
        }
        tempNode = pNode; //gan node nay cho node tempNode
        pNode = pNode->pNext; //pNode chinh la nut tail can xoa
        lst.pTail = tempNode;
        lst.pTail->pNext = NULL; // cap nhat lai tail
        delete pNode;
    }
}

//delete node bat ky
void delAt(List& lst, int idx) {
    int idxCurrent = 0;
    if(idx == 0) {
        delHead(lst);
    } else if (idx == getSize(lst) - 1) {
        delTail(lst);
    } else {
        Node* pNode = lst.pHead;
        Node* tempNode = new Node;
        while (pNode != NULL && idxCurrent < idx)
        {
            idxCurrent++;
            pNode = pNode->pNext;
        }
        tempNode = pNode;
        Node* tempNode1 = lst.pHead;
        while (tempNode1->pNext != tempNode) {
            tempNode1 = tempNode1->pNext;
        }
        tempNode1->pNext = tempNode->pNext; // cho node pNext cua node k - 1 tro toi k + 1
        delete tempNode;
    }
}