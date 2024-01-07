#include <iostream>
using namespace std;

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void sort(int arr[], int n)
{ // Insertion sort
    for (int i = 1; i < n; i++)
    {
        int j = i - 1, key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            swap(arr[j + 1], arr[j]);
            j--;
        }
        arr[j + 1] = key;
    }
}
int binSearch(int arr[], int n, int key)
{
    sort(arr, n);
    int s = 0, e = n - 1, mid;
    while (s <= e)
    {
        // mid=(s+e)/2; --> Not entirely correct.
        mid = s + (e - s) / 2; // Did this to avoid a fatal error, i.e., when s= 2^31-1 and e= 2^31-1, then s+e will exceed the maximum integer range, which will lead to failure of program.
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 4, 5, 6, 3, 8};
    cout << binSearch(arr, 7, 0);
    return 0;
}