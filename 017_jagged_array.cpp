// An array in which the number of columns in a specific row are variable is called a Jagged array
#include <iostream>
using namespace std;

int main()
{
    int row;
    cout << "Enter the number of rows: ";
    cin >> row;
    // Creating a Jagged array
    int **arr = new int *[row];
    int *col = new int[row];
    for (int i = 0; i < row; i++)
    {
        cout << "Enter the size of row " << i + 1 << ": ";
        cin >> col[i];
        arr[i] = new int[col[i]];
    }
    // Taking inputs in the Jagged array
    for (int i = 0; i < row; i++)
    {
        cout << "Enter elements of row " << i + 1 << "\n";
        for (int j = 0; j < col[i]; j++)
            cin >> arr[i][j];
    }
    // Printing the jagged array
    cout<<"The array is \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col[i]; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    return 0;
}