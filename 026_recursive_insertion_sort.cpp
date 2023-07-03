#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n, int s=1){
    if(s>n)
    return;
    for(int i=s-1; i>=0; i--)
    if(arr[i]>arr[i+1])
    swap(arr[i], arr[i+1]);
    insertion_sort(arr, n, s+1);
}
int main(){
    int arr[]={23, 21, 12, 11, 14, 2, 3, 44, 5};
    insertion_sort(arr, 9);
    for(int i=0; i<9; i++)
    cout<<arr[i]<<" ";
    return 0;
}