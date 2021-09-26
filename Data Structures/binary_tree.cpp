#include "binary_tree.h"

/*---------------1_Khoi tao cay nhi phan---------------*/
void initTree(TREE& tree)
{
    tree = NULL;
}

/*---------------2_Tao node----------------------------*/
Node* createNode(int data)
{
    Node* pNode = new Node;
    pNode->data = data;
    pNode->pLeft = NULL;
    pNode->pRight = NULL;
    return pNode;
}

/*---------------3_Them node vao cay-------------------*/
void addNode(TREE& tree, int data)
{
    if(tree == NULL)
    {
        Node* pNode = createNode(data);
        tree = pNode;
    } 
    else 
    {
        if(tree->data > data)
        {
            addNode(tree->pLeft, data);
        }
        else if(tree->data < data)
        {
            addNode(tree->pRight, data);
        }
    }
}

/*---------------4_Duyet cay nhi phan------------------*/
void printNLR(TREE tree)
{
    if(tree != NULL) 
    {
        cout << tree->data << " ";
        printNLR(tree->pLeft);
        printNLR(tree->pRight);
    }
}

/*---------------5_Tim kiem nhi phan-------------------*/
Node* searchNode(TREE tree, int x) 
{
    if(tree == NULL) return NULL;
    else 
    {
        if(x < tree->data) return searchNode(tree->pLeft, x);
        else if(x > tree->data) return searchNode(tree->pRight, x);
        else return tree;
    }
}
/*---------------6_Xoa node nhi phan-------------------*/
void delNode(TREE &tree, int x)
{
    if(tree == NULL) return;
    else
    {
        if(x < tree->data) delNode(tree->pLeft, x); // Duyet sang trai 
        else if (x > tree->data) delNode(tree->pRight, x); // Duyet sang phai
        else // Da tim thay node x 
        {
            Node* pNode = tree;
            if (tree->pLeft == NULL) 
            {
                tree = tree->pRight;
                delete pNode;               
            }
            else if (tree->pRight == NULL) 
            {
                tree = tree->pLeft;
                delete pNode;                
            }
            else
            {
                Node* tNode = tree->pRight;
                while(tNode->pLeft != NULL) 
                {
                    tNode = tNode->pLeft;
                }
                pNode->data = tNode->data;
                pNode = tNode;
                delNode(tree->pRight, tNode->data);
            }
            
        }
    }
}

void Menu(TREE& tree)
{
    while(true)
    {
    cout << "\n\t\t================MENU================";
    cout << "\n1. Nhap du lieu: ";
    cout << "\n2. Xuat du lieu cay: ";
    cout << "\n3. Tim kiem node trong cay";
    cout << "\n4. Xoa node trong cay";
    cout << "\n0. Ket thuc.";
    cout << "\n\t\t====================================";
    
    int urChoice;

    cout << "\n Nhap lua chon cua ban: ";
    cin >> urChoice;

    switch (urChoice)
    {
    case 1:
        int data;
        cout << "\nNhap so nguyen: ";
        cin >> data;
        addNode(tree, data);
        break;
    case 2:
        cout << "\nDuyet cay nhi phan theo NLR: ";
        printNLR(tree);
        break;
    case 3:
        {
        cout << "\nNhap so nguyen can tim trong cay: ";
        int x; 
        cin >> x;
        Node* pNode = searchNode(tree, x);
        if(pNode == NULL) cout << "Khong ton tai phan tu " << x << " trong cay" << endl;
        else cout << "Ton tai phan tu" << x << " trong cay" << endl;
        break;
        }
    case 4:
        {
        cout << "\nNhap so nguyen can xoa: ";
        int x;
        cin >> x;
        delNode(tree, x);
        cout << "\nDanh sach sau khi xoa:";
        printNLR(tree);
        break;
        }
    default:
        return;
        break;
    }
    }
}