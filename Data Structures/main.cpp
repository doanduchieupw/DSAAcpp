/* #include "linked_list.h"

int main() {
    List lst;
    //Node 1 
    Node *node_1 = createNode(12);
    //Node 2
    Node *node_2 = createNode(23);
    //Node 3
    Node *node_3 = createNode(34);
    //Tao list
    initList(lst);
    node_1->pNext = node_2;
    node_2->pNext = node_3;
    node_3->pNext = NULL;
    lst.pHead = node_1;
    lst.pTail = node_3;
        
    // In ra danh sach truoc khi them
    cout << "Truoc khi them: " << endl;
    printList(lst);
    cout << "So phan tu trong danh sach la: " << getSize(lst) << endl;

    //Node 4, 5
    Node *node_4 = createNode(45);
    Node *node_5 = createNode(56);
    Node *node_6 = createNode(99); 
    addHead(lst, node_4);
    addTail(lst, node_5);
    addAt(lst, 2, node_6);
    addMid(lst, 11, 45);
    delAt(lst, 3);
    // In ra danh sach sau khi them
    cout << "Sau khi them: " << endl;
    printList(lst);
    cout << "So phan tu trong danh sach la: " << getSize(lst) << endl;
    

    return 0;
}
*/
/*
#include "double_linked_list.h"

int main() {
    List lst;
    //Node 1 
    Node *node_1 = createNode(12);
    //Node 2
    Node *node_2 = createNode(23);
    //Node 3
    Node *node_3 = createNode(34);
    //Tao list
    initList(lst);
    node_1->pNext = node_2;
    node_2->pPrev = node_1;
    node_2->pNext = node_3;
    node_3->pPrev = node_2;
    node_3->pNext = NULL;
    node_1->pPrev = NULL;
    lst.pHead = node_1;
    lst.pTail = node_3;

    // In ra danh sach truoc khi them
    cout << "Truoc khi them: " << endl;
    printList(lst);
    cout << "So phan tu trong danh sach la: " << getSize(lst) << endl;

    //Node 4, 5
    addHead(lst, 45);
    addTail(lst, 56);
    addAt(lst, 2, 999);
    delAt(lst, 3);
    // In ra danh sach sau khi them
    cout << "Sau khi them: " << endl;
    printList(lst);
    cout << "So phan tu trong danh sach la: " << getSize(lst) << endl;
    
    return 0;
}
*/

#include "binary_tree.h"

int main()
{
    TREE tree;
    initTree(tree);
    Menu(tree);
    return 0;
}