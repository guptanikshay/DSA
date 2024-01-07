#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
// BUBBLE SORT: Compares the adjacent elements, swaps them if first one is smaller. In this algo, the largest element is placed at its right position in the first iteration and then the second largest and so on.
void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}
// INSERTION SORT: Set a marker for sorted section after the first element. Repeat the following until the unsorted section (array after first element) is empty:- Select the first unsorted element and shift the elements of the sorted section by one position until the correct position of the unsorted element is found.
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1, key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            swap(arr[j], arr[j + 1]);
            j--;
        }
        arr[j + 1] = key;
    }
}
// SELECTION SORT: We select one position and find the element that should be placed in that position. Basically, we select the first position and find the minimum element in the entire array and swap that element with the first position element. Then we select the second position and find the minimum element in the array after first element and swap it with the second position element and so on.
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        swap(arr[i], arr[min]);
    }
}
int main()
{
    int arr[] = {2, 4, 1, 5, 3};
    // insertionSort(arr, 5);
    selectionSort(arr, 5);
    printarray(arr, 5);
    return 0;
}