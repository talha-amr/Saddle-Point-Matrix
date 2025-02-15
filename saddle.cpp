#include <iostream>
using namespace std;

// Function prototypes
bool isMinimumRow(int arr[][50], int row, int columns, int rowNo, int value);
bool isMaximumColumn(int arr[][50], int rows, int columns, int colNo, int value);
bool isSaddlePoint(int arr[][50], int rows, int columns, int rowNo, int colNo, int value);
void printSaddle(int arr[][50], int rows, int columns);

int main() {
    int array[50][50];
    int rows, columns;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> columns;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++)
	{
            cin >> array[i][j];
        }
    }

    printSaddle(array, rows, columns);

    return 0;
}
bool isMinimumRow(int arr[][50], int row, int columns, int rowNo, int value) 
{
    for (int i = 0; i < columns; i++) \
    {
        if (arr[rowNo][i] < value)
	{
            return false;
        }
    }
    return true;
}

bool isMaximumColumn(int arr[][50], int rows, int columns, int colNo, int value) 
{
    for (int i = 0; i < rows; i++) 
    {
        if (arr[i][colNo] > value) 
	{
            return false;
        }
    }
    return true;
}
bool isSaddlePoint(int arr[][50], int rows, int columns, int rowNo, int colNo, int value) 
{
    return isMinimumRow(arr, rows, columns, rowNo, value) && isMaximumColumn(arr, rows, columns, colNo, value);
}

void printSaddle(int arr[][50], int rows, int columns)
{
    bool found = false;
    for (int i = 0; i < rows; i++) 
   {
        for (int j = 0; j < columns; j++) 
	{
            if (isSaddlePoint(arr, rows, columns, i, j, arr[i][j])) 
	    {
                found = true;
                cout << "Saddle Point: (" << i << ", " << j << ") -> " << arr[i][j] << endl;
            }
        }
    }
    if (!found)
    {
        cout << "No saddle point found." << endl;
    }
}
