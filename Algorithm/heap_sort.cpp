#include <iostream>

using namespace std;

int N = 7;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void maxHeap(int A[], int i) {
    int largest;
    int left = 2*i;
    int right = 2*i + 1;
    
    if (left <= N && A[left] > A[i])
        largest = left;
    else    
        largest = i;
    
    if (right <= N && A[right] > A[largest])
        largest = right;

    if (largest != i) {
        swap(A[largest], A[i]);

        maxHeap(A, largest);
    }
}

void runMaxHeap(int A[]) {
    for(int i = N/2; i >= 1; i--) {
        maxHeap(A, i);
    }
}

void printArr(int A[]) {
    for (int i = 1; i < N+1; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int A[N+1] = {-1,1,4,3,7,8,9,10};
    runMaxHeap(A);
    cout << "Sau khi chay max heap: ";
    printArr(A);
    return 0;
}