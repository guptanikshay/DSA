#include <iostream>
#include <queue>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i, right = 2*i+1;
    if(left<=n && arr[left]>arr[largest])
        largest = left;
    if(right<=n && arr[right]>arr[largest])
        largest = right;
    if(largest!=i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for(int i=n/2; i>0; i--)
    heapify(arr, n, i);
    int t = n;
    while(t>1){
        swap(arr[t], arr[1]);
        t--;
        heapify(arr, t, 1);
    }
}
int main(){
    // int arr[] = {-1, 2, 3, 1, 8, 5, 4, 6};
    // int n = 7;
    // heapSort(arr, 7);
    // cout<<"After Sorting\n";
    // for(int i=1; i<=n; i++)
    // cout<<arr[i]<<" ";
    // cout<<"\n";

    
    // USING PRIORITY QUEUE
    // MaxHeap
    priority_queue <int> pq;
    pq.push(4);
    pq.push(5);
    pq.push(1);
    pq.push(8);

    cout<<"Element at top "<<pq.top()<<"\n";
    pq.pop();
    cout<<"Element at top "<<pq.top()<<"\n";
    
    // MinHeap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(4);
    minHeap.push(5);
    minHeap.push(1);
    minHeap.push(8);

    cout<<"Element at top "<<minHeap.top()<<"\n";
    minHeap.pop();
    cout<<"Element at top "<<minHeap.top()<<"\n";
    return 0;
}