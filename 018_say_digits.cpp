// PS:- For a given number, print it in words in its individual digits.
// e.g. 412 will be printed as Four One Two
#include <iostream>
#include <string>
using namespace std;
string arr[10]={"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
void sayDigits(int n){
    if(n==0)
    return;
    sayDigits(n/10);
    cout<<arr[n%10]<<" ";
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n; 
    cout<<"The number in digits is ";
    sayDigits(n);
    return 0;
}