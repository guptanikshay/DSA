#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n)
{
    if (n == 1)
        return;
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    bubble_sort(arr, n-1);
}
int main()
{
    int arr[]={23, 14, 5, 24, 12};
    bubble_sort(arr, 5);
    for(int i=0; i<5; i++)
    cout<<arr[i]<<" ";
    return 0;
}