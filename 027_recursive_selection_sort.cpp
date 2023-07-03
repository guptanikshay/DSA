#include <iostream>
using namespace std;

void selectionSort(int arr[], int n, int s = 0)
{
    if (s >= n)
        return;
    int min = arr[s], index = s;
    for (int i = s + 1; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            index = i;
        }
    }
    swap(arr[s], arr[index]);
    selectionSort(arr, n, s + 1);
}
int main()
{
    int arr[] = {23, 21, 12, 11, 14, 2, 3, 44, 5};
    selectionSort(arr, 9);
    for (int i = 0; i < 9; i++)
        cout << arr[i] << " ";
    return 0;
}