// PS: Execute linear search using recursion
#include <iostream>
using namespace std;

int linearSearch(int * arr, int n, int key){
    static int count=0;
    if(n==0)
    return -1;
    if(arr[0]==key)
    return count;
    count++;
    return linearSearch(arr+1, n-1, key);
}
int main(){
    int arr[]={1, 2, 3, 4, 5};
    cout<<"Element is present in the array at index "<<linearSearch(arr, 5, 8)<<"\n";
    return 0;
}