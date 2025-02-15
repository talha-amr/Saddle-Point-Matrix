#include < iostream>
using namespace std;
bool isMinimumRow(int arr[][50], int row, int columns, int rowNo, int value)
{
	for (int i = 0; i < columns; i++)
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
bool isSaddlePoint(int arr[][50], int row, int columns, int rowNo, int colNo, int value)
{
	if (isMinimumRow(arr, row, columns, rowNo, value) && isMaximumColumn(arr, row, columns, colNo, value))
	{
		return true;
	}
	return false;
}
void printSaddle(int arr[][50], int rows, int columns)
{
	bool found = false;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			int value = arr[i][j];
			if (isSaddlePoint(arr, rows, columns, i, j, value)) {
				found = true;
				cout << "Saddle Point is "<<"(" << i << "," << j << ")";
			}
		}
	}
	if (!found) {
		cout << "No saddle point\n";
	}
}

int main()
{
	int array[50][50];
	int rows, columns;
	cin >> rows >> columns;
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