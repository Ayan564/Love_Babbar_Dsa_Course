#include<iostream>
using namespace std;

class Heap{
    public:
    int *arr;
    int capacity;
    int index;

    Heap(int cap){
        this->capacity = cap;
        this->arr = new int[capacity];
        this->index = 0;
    }

    void printHeap(){
        for(int i=0;i<capacity;i++){
            if(arr[i] > 1000) cout << 0 << " ";
            else cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void insertInHeap(int val){
        cout << "Inserting " << val << " in heap" << endl;
        if(index == capacity-1){
            cout<<"Heap is full"<<endl;
            return;
        }
        index++;
        arr[index] = val;
        int i = index;
        while(i>1){
            int parent = i/2;
            if(arr[parent] < arr[i]){
                swap(arr[parent], arr[i]);
                i = parent;
            }
            else break;
        }
    }

    void heapify(int *arr, int n, int currIndex){
        int i = currIndex;
        int leftIndex = 2*i;
        int rightIndex = 2*i+1;
        int largestIndex = i;
        if(leftIndex < n && arr[leftIndex] > arr[largestIndex]){
            largestIndex = leftIndex;
        }
        if(rightIndex < n && arr[rightIndex] > arr[largestIndex]){
            largestIndex = rightIndex;
        }
        if(largestIndex != i){
            swap(arr[i], arr[largestIndex]);
            heapify(arr, n, largestIndex);
        }
    }

    void deleteFromHeap(){
        cout << "Deleting " << arr[1] << " from heap" << endl;
        // replacement
        swap(arr[1], arr[index]);
        // size decrease
        index--;
        // heapify
        heapify(arr, index, 1);
    }
};

void heapify(int *arr, int n, int currIndex){
    int i = currIndex;
    int leftIndex = 2*i;
    int rightIndex = 2*i+1;
    int largestIndex = i;
    if(leftIndex < n && arr[leftIndex] > arr[largestIndex]){
        largestIndex = leftIndex;
    }
    if(rightIndex < n && arr[rightIndex] > arr[largestIndex]){
        largestIndex = rightIndex;
    }
    if(largestIndex != i){
        swap(arr[i], arr[largestIndex]);
        heapify(arr, n, largestIndex);
    }
}

void buildHeap(int *arr, int n){
    for(int i=n/2;i>0;i--){
        heapify(arr, n, i);
    }
}

void heapSort(int *arr, int n){
    for(int i=n-1;i>0;i--){
        swap(arr[1], arr[i]);
        heapify(arr, i, 1);
    }
}

int main(){
    Heap pq(10);
    pq.insertInHeap(10);
    pq.printHeap();
    pq.insertInHeap(20);
    pq.printHeap();
    pq.insertInHeap(30);
    pq.printHeap();
    pq.insertInHeap(40);
    pq.printHeap();
    pq.insertInHeap(50);
    // 50 40 20 10 30
    pq.printHeap();
    pq.deleteFromHeap();
    pq.printHeap();
    pq.deleteFromHeap();
    pq.printHeap();
    pq.deleteFromHeap();
    pq.printHeap();
    pq.deleteFromHeap();
    pq.printHeap();
    

    // Heap pq(10);
    // int arr[] = {-1, 10, 20, 30, 40, 50};
    // int n = 6;
    // buildHeap(arr, n);
    // cout << "Heap is: ";
    // for(int i=1;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // heapSort(arr, n);
    // cout << "Sorted array is: ";
    // for(int i=1;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    return 0;
}