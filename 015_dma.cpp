// When a program is executed, it comes with two types of memories, one is the stack which is used for static memory allocation and one is the heap which is for dynamic memory allocation.
#include <iostream>
using namespace std;

int main()
{
    // int n;
    // cin>>n;
    // int arr[n] --> It is a very bad practice to create an array like this as we don't know whether the required memory is available in the stack or not. The right way of creating an array whose size will be known at runtime is shown below.
    int n;
    cin >> n;
    int *arr = new int[n]; // Total memory used will be (n*4 + 8) bytes, for the integers and pointer.
    // NOTE:- Static memory gets cleared automatically when the block ends but dynamic memory needs to be cleared manually and it is very important to clear the dynamically allocated memory, or else the program might crash if the memory in the heap runs out. delete keyword is used to delete memory from heap.
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Your array is ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    // To delete an array:-
    delete[] arr;
    return 0;
}