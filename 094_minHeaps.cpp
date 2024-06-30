// A Min Heap is the one in which the children of every node are greater than the node itself.
#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int> &arr, int i)
{
    int smallest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    // As the index starts from 0 here, the value of left and right are changed accordingly
    int n = arr.size();
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapify(arr, smallest);
    }
}
void buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, i);
}

int main()
{
    vector<int> arr = {2, 4, 5, 3, 6, 7, 1};
    buildMinHeap(arr);
    for (auto i : arr)
        cout << i << " ";
    cout << "\n";
    return 0;
}
// For, heapify algo, TC = O(N) and SC = O(logN)
// Proof that heapify TC is O(N)
/* TC to maxHeapify a node at height 'h' = O(h)
 * Max no of nodes at height 'h' = smallestIntFunc(N/2^h + 1), where N is the total no. of nodes and h is the height at that level. (Note: Height is considered 0 at last level)
 * Total time at level 'h' = smallestIntFunc(N/2^h + 1) * O(h)
 * Total time for all level (h=0 to h=logN) = Σ(h=0 to h=logN){smallestIntFunc(N/2^h + 1) * O(h)}
 * => Total time = Σ(h=0 to h=logN){smallestIntFunc(N/2^h * 2) * c*h} (c=>  some const)
 * => c*N/2 Σ(h=0 to h=logN)(h/2^h) < O(c*N/2 Σ(h=0 to h=∞)(h/2^h)) {Considering the worst case}
 * As Σ(h=0 to h=∞)(h/2^h) = 4, hence total time = O(c*N/2 * 4) = O(2cN)
 * => Total time complexity = O(N)
 */
// To evaluate Σ(h=0 to h=∞)(h/2^h) = 4, write it in series form, multiply both the sides by 1/2 and then subtract the shifted series from the original series.