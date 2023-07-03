// PS: Find the sum of all elements of an array using recursion
#include <iostream>
using namespace std;
int getSum(int * arr, int n){
    if(n==0)
    return 0;
    return arr[0] + getSum(arr+1, n-1);
}
int main(){
    int arr[]={4, 4, 4, 4, 5};
    cout<<getSum(arr, 5)<<"\n";
    return 0;
}