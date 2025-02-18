#include <bits/stdc++.h>
using namespace std;

void matrixSwap(vector<vector<int>> &matrix, int x, int y, int &var)
{
    int temp = matrix[x][y];
    matrix[x][y] = var;
    var = temp;
}
void singleRotate(vector<vector<int>> &matrix, int size, int k)
{
    // n is size of the matrix
    // we take coordinate of the matrix
    int c = size - 1;
    for (int shift = 1; shift < c - 2 * k + 1; shift++)
    {
        int temp = matrix[k][k];
        for (int i = k + 1; i <= c - k; i++)
            matrixSwap(matrix, k, i, temp);
        for (int i = k + 1; i <= c - k; i++)
            matrixSwap(matrix, i, c - k, temp);
        for (int i = c - k - 1; i >= k; i--)
            matrixSwap(matrix, c - k, i, temp);
        for (int i = c - k - 1; i >= k; i--)
            matrixSwap(matrix, i, k, temp);
    }
}

int main()
{
    int n;

    // Input the size of the square matrix
    cout << "Enter the size of the square matrix (n x n): ";
    cin >> n;

    // Declare a 2D array
    vector<vector<int>> matrix(n, vector<int>(n));

    // Input matrix elements
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
    for (int k = 0; k <= n / 2; k++)
    {
        singleRotate(matrix, n, k);
    }
    // Output the matrix
    cout << "The matrix is:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
    cout << endl;
    return 0;
}