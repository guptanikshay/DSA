#include <iostream>
using namespace std;

int main()
{
    // int n;
    // cout << "Enter the value of n: ";
    // cin >> n;
    // // Creating an array of n x n
    // int **arr = new int *[n];
    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = new int[n];
    // }
    // // Taking Inputs
    // cout << "Enter the 2D array: \n";
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         cin >> arr[i][j];

    // // Printing the array
    // cout << "The array is: \n";
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cout << arr[i][j] << " ";
    //     cout << "\n";
    // }
    // // DELETING THE ARRAY
    // for (int i = 0; i < n; i++)
    //     delete[] arr[i]; // Deleting the 1-D arrays associated with the pointers
    // delete[] arr;        // Deleting the array of pointers in Heap

    // For different values of rows and columns
    int m, n;
    cout << "Enter the value of m and n: ";
    cin >> m >> n;

    // Creating the array
    int **arr = new int *[n];
    for (int i = 0; i < m; i++)
        arr[i] = new int[m];
    // Taking inputs
    cout << "Enter the array: \n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    // Printing the array
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    // Deleting the array
    for (int i = 0; i < m; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}