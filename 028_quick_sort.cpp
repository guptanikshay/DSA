// Quick Sort: In this sorting algo, one element (usually the first one) is set as reference in the first iteration and then i=ref+1 and j=n-1 (n => total number of elements) are set and 'i' is incremented until an element larger than the reference is found and 'j' is decremented until an element smaller than or equal to reference is found and then arr[i] and arr[j] are swapped and the process is repeated until i<j. When i>=j, ref and arr[j] are interchanged and ref+1 is set as the new reference and this process is repeated until ref<n. The result is a sorted array.
#include <iostream>
using namespace std;

void quickSort(int *arr, int n)
{
    int ref = 0;
    while (ref<n)
    {
        int i = ref + 1, j = n - 1;
        while (i < j)
        {
            while (arr[i] < arr[ref] && i<n)
                i++;
            while (arr[j] > arr[ref] && j>=0)
                j--;
            if (i < j)
                swap(arr[i], arr[j]);
            else
                swap(arr[j], arr[ref]);
        }
        ref++;
    }
}

int main()
{
    int arr[] = {23, 11, 12, 25, 9, 1, 4, 3, 2, 18, 56, 34};
    quickSort(arr, 12);
    for(int i=0; i<12; i++)
    cout<<arr[i]<<" ";
    return 0;
}