/*
 Q. Sort an array containing only 0, 1 and 2.
 Soln: Here we divide our array into 4 regions that are
 > 0-low
 > low-mid
 > mid-high (This is our unknown region, array is sorted when this region reduces to 0)
 > high-n
 Firstly we place low and mid on index 0 and high on index n. Then we check the value of arr[mid]. If
 > arr[mid] = 1, we simply do mid++
 > arr[mid] = 0, we swap arr[low] and arr[mid] and do low++ and mid++
 > arr[mid] = 2, we swap arr[mid] and arr[high] and do mid++ and high--
 and we continue this until mid!=high.
 When mid==high, our array is sorted
 */
#include <iostream>
using namespace std;
void printarray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void swap(int *arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void dnfsort(int *arr, int size)
{
    int low = 0, mid = 0, high = size - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr, mid, low);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr, mid, high);
            high--;
        }
    }
}
int main()
{
    int arr[] = {0, 1, 1, 0, 2, 2, 1, 0, 2};
    dnfsort(arr, 9);
    printarray(arr, 9);
    return 0;
}