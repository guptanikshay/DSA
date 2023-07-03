#include <iostream>
using namespace std;
void printarray(int *arr, int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void swap(int *arr, int a, int b){
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
void dnfsort(int *arr, int size){
    int low=0, mid=0, high=size-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr, mid, low);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr, mid, high);
            high--;
        }
    }
}
int main(){
    int arr[]={0,1,1,0,2,2,1,0,2};
    dnfsort(arr, 9);
    printarray(arr, 9);
    return 0;
}