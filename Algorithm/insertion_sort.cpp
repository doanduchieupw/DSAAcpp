#include <iostream>

using namespace std;

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        //gan phan tu can duyet vao bien tam thoi
        int key = arr[i];  
        int j = i - 1;   

        //so sanh cac phan tu truoc phan tu dang duyet   
        while(j >= 0 && key < arr[j]) { 
            arr[j + 1] = arr[j];
            j--;
        }

        // gan vao vi tri de mang thanh day tang dan
        arr[j + 1] = key;

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
    insertionSort(arr, n);
    cout << "Sau khi sap xep: ";
    printArr(arr, n);
    return 0;
}