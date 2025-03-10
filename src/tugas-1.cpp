#include <iostream>
#include <vector>
using namespace std;

void maxHeap(int lastIndex, int i, vector<int>& arr) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < arr.size() && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < arr.size() && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        maxHeap(lastIndex, largest, arr);
    }
}

void minHeap(int lastIndex, int i, vector<int>& arr) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;

    if (l < arr.size() && arr[l] < arr[smallest]) {
        smallest = l;
    }

    if (r < arr.size() && arr[r] < arr[smallest]) {
        smallest = r;
    }

    if (smallest != i) {
        swap(arr[smallest], arr[i]);
        minHeap(lastIndex, smallest, arr);
    }
}

void printHeap(vector<int>arr){
    for (int x : arr){
        cout << x << " ";
    }
    cout << "\n";
}

void buildMaxHeap(vector<int>arr){
    int lastIndex = arr.size()/2 - 1;

    for(int i = lastIndex; i >= 0; i--){
        maxHeap(lastIndex, i, arr);
    }
    printHeap(arr);
}

void buildMinHeap(vector<int>arr){
    int lastIndex = arr.size()/2 - 1;

    for(int i = lastIndex; i >= 0; i--){
        minHeap(lastIndex, i, arr);
    }
    printHeap(arr);
}

int main(){
    vector<int> oriArr = {1, 9, 6, 8, 19, 7, 2, 13};
    buildMaxHeap(oriArr);
    buildMinHeap(oriArr); 

    return 0;
}