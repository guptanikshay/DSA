#include <iostream>
using namespace std;
int binary_search(int arr[], int s, int e, int key){
    if(s>e)
    return -1;
    int mid=(s+e)/2;
    if(arr[mid]==key)
    return mid;
    else if(arr[mid]>key)
    return binary_search(arr, s, mid-1, key);
    else
    return binary_search(arr, mid+1, e, key);
}
int main(){
    int arr[]={2, 4, 6, 7, 8 ,10 ,14};
    cout<<"Element is present at index "<<binary_search(arr, 0 ,6, 3);
    return 0;
}