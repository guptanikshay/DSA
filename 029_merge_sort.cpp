// In this sorting algo, we divide the array into two halves and further divide the halves into two halves until it cannot be divided anymore (that is a single element). Then we merge these indivual parts by using the algorithm that is used to merge two sorted arrays. At last we are left with the complete sorted array.
#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2, len1 = mid - s + 1, len2 = e - mid;
    int *arr1 = new int[len1];
    int *arr2 = new int[len2];
    int k = s;
    for (int i = 0; i < len1; i++)
        arr1[i] = arr[k++];
    k = mid + 1;
    for (int i = 0; i < len2; i++)
        arr2[i] = arr[k++];
    int i1 = 0, i2 = 0;
    k = s;
    while (i1 < len1 && i2 < len2)
    {
        if (arr1[i1] <= arr2[i2])
            arr[k++] = arr1[i1++];
        else
            arr[k++] = arr2[i2++];
    }
    while (i1 < len1)
        arr[k++] = arr1[i1++];
    while (i2 < len2)
        arr[k++] = arr2[i2++];
    delete[] arr1;
    delete[] arr2;
}
void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
        return;
    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

int main()
{
    int arr[] = {23, 12, 11, 25, 9, 69, 34, 21, 12, 3, 5, 19};
    mergeSort(arr, 0, 11);
    for (int i = 0; i < 12; i++)
        cout << arr[i] << " ";
    return 0;
}