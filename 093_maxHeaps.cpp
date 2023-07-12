// A Heap is a complete binary tree that comes with a heap order property.
// A complete binary tree is tree in which all the levels are completely filled except for the last level and nodes are always added from the left.
// A Max Heap is the one in which children of every node are smaller from the node itself and a Min Heap is the one in which children of every node are greater than the node itself.
/* A Heap is implement using an array starting from its index 1. Index 0 is not used so that we can use the following logic:
 * The parent of 'i'th node is found at 'i/2'th position. 
 * The left child of 'i'th node is found at '2*i'th position and its right child is found at '2*i+1'th position. 
 */
#include <bits/stdc++.h>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size;
    Heap(){
        arr[0] = -1;
        size = 0;
    }
    void insert(int val){
        size++;
        int index = size;
        arr[index] = val;
        while(index>1){
            int parent = index/2;
            if(arr[index]>arr[parent]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            return;
        }
    }
    void deleteRoot(){
        if(size==0)
        return;
        arr[1] = arr[size];
        size--;
        int i=1;
        while(i<=size){
            int left = 2*i, right = 2*i+1;
            if(left<=size && arr[i]<arr[left]){
                swap(arr[i], arr[left]);
                i = left;
            }
            else if(right<=size && arr[i]<arr[right]){
                swap(arr[i], arr[right]);
                i = right;
            }
            else return;
        }
    }
    // The TC of deletion and insertion in a Heap is O(log n)
    void print(){
        for(int i=1; i<=size; i++){
            cout<<this->arr[i]<<" ";
        }
        cout<<"\n";
    }
};

void heapify(int arr[], int n, int i){
    // Setting our target index and finding its right and left node. As it should be larger than its children in a MaxHeap and hence the name.
    int largest = i;
    int left = 2*i, right = 2*i+1;
    // Checking if largest is smaller than left or right and updating it.
    if(left<=n && arr[left]>arr[largest])
        largest = left;
    if(right<=n && arr[right]>arr[largest])
        largest = right;
    // Finally swapping the largest value with given index and calling the function for the tree below it
    if(largest!=i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
int main(){
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.insert(70);
    h.insert(45);
    h.insert(64);
    h.insert(7);
    h.print();
    h.deleteRoot();
    h.print();

    int arrH[] = {-1, 53, 52, 70, 50, 55, 54, 45, 64, 7};
    int n = 9;
    // Heapifying the nodes from 1 to n/2 as the rest are leaf nodes and they are assumed to be heaps
    for(int i=n/2; i>=1; i--)
        heapify(arrH, n, i);
    for(int i=1; i<=n; i++)
    cout<<arrH[i]<<" ";
    cout<<"\n";
    return 0;
}