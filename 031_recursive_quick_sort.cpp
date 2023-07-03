#include <iostream>
using namespace std;
int partition(int arr[], int s, int e){
    int count = 0;
    for(int i=s+1; i<=e; i++)
    if(arr[i]<arr[s])
    count++;
    int i=s, j=e, p=s+count;
    swap(arr[s], arr[p]);
    while(i<p && j>p){
        if(arr[i]>arr[p] && arr[j]<=arr[p]){
        swap(arr[i++], arr[j--]);
        continue;
        }
        if(arr[i]<arr[p])
        i++;
        if(arr[j]>=arr[p])
        j--;
    }
    return p;
}

void quickSort(int arr[], int s, int e){
    if(s>=e)
    return;
    int p=partition(arr, s, e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}
int main(){
    int arr[]={3, 4, 1, 13, 21, 14, 5,  2, 6, 8, 7};
    quickSort(arr, 0, 10);
    for(int i=0; i<11; i++)
    cout<<arr[i]<<" ";
    return 0;
}