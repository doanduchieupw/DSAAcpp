#include <iostream>

using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void interchangeSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[i])
                swap(arr[i], arr[j]); 
        }
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {22, 23, 52, 11, 03, 97, 54, 33, 07, 64};
    int n = sizeof(arr) / sizeof(arr[0]);
    interchangeSort(arr, n);
    cout << "Sau khi sap xep: ";
    printArr(arr, n);
    return 0;
}