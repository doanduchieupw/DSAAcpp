#include <iostream>
#include <list>

using namespace std;

class Hashing {
private:
    int bucket;
    list<int> *sc;
public:
    Hashing(int n);
    void insertKey(int key);
    void delKey(int key);
    int hashFunction(int okey);
    void printHashTable();
};

//khoi tao gia tri cho bucket 
Hashing::Hashing(int n) {
    this->bucket = n;   
    sc = new list<int>[bucket];
}

int Hashing::hashFunction(int okey) {
    return okey % bucket;
}

void Hashing::insertKey(int key) {
    int nkey = hashFunction(key);
    sc[nkey].push_back(key);
}

void Hashing::delKey(int key) {
    // get the hash index of key
    int nkey = hashFunction(key);

    // find the key in (index)th list
    list<int>::iterator i; // ham tao con tro de tim kiem phan tu
    for(i = sc[nkey].begin(); i != sc[nkey].end(); i++) {
        if(*i == key) 
            break;// xoa tai dia chi con tro i tro toi
    }
    
    // if key is found in hash table, remove it
        if(i != sc[nkey].end()) 
            sc[nkey].remove(*i);
}


void Hashing::printHashTable() {
    for(int i = 0; i < bucket; i++) {
        cout << i;
        list<int>::iterator j;
        for(j = sc[i].begin(); j != sc[i].end(); j++) {
            cout << "-->" << *j;
        }
        cout << endl;
    }
}

int main() {
    Hashing h(7);
    int arr[] = {120, 35, 99 , 23, 63, 41, 30, 99, 14};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < arrSize; i++) {
        h.insertKey(arr[i]);
    }
    
    h.delKey(991);
    h.printHashTable();
    
    return 0;
}