#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int rowCount = 0, colCount = 0;
    cout << "Enter the No. of rows : ";
    cin >> rowCount;
    if (rowCount <= 0)
    {
        cout << "Invalid Row Count!!" << endl;
        return 0;
    }

    cout << "Enter the No. of cols : ";
    cin >> colCount;
    if (colCount <= 0)
    {
        cout << "Invalid column Count!!" << endl;
        return 0;
    }

    // Added spaces between the closing angle brackets (> >)
    vector<vector<int>> matrix(rowCount, vector<int>(colCount));

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << "Enter the element at index ( " << i << " , " << j << " ) : ";
            cin >> matrix[i][j];
        }
    }

    // Count non-zero elements to size the spare matrix properly
    int nonZeroCount = 0;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            if (matrix[i][j] != 0)
            {
                nonZeroCount++;
            }
        }
    }

    // Sparse matrix always has 3 columns: [Row, Column, Value]
    // Total rows = nonZeroCount + 1 (for metadata)
    vector<vector<int>> sparseMatrix(nonZeroCount + 1, vector<int>(3));

    // Store metadata in the first row
    sparseMatrix[0][0] = rowCount;
    sparseMatrix[0][1] = colCount;
    sparseMatrix[0][2] = nonZeroCount;

    int sparseRowCount = 1;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparseMatrix[sparseRowCount][0] = i;
                sparseMatrix[sparseRowCount][1] = j;
                sparseMatrix[sparseRowCount][2] = matrix[i][j];
                sparseRowCount++;
            }
        }
    }

    cout << "\n --------- Given Matrix ----------" << endl;
    cout << " ---------------------------------" << endl;

    for (int i = 0; i < rowCount; i++)
    {
        cout << " |    " << matrix[i][0] << "    |     " << matrix[i][1] << "    |    " << matrix[i][2] << "    |" << endl;
    }
    cout << " ---------------------------------" << endl;

    cout << "\n -------- Sparse Matrix ----------" << endl;

    cout << " ---------------------------------" << endl;
    cout << " |   Row   |  Column  |  Value  |" << endl;
    cout << " ---------------------------------" << endl;
    for (int i = 0; i < sparseRowCount; i++)
    {
        cout << " |    " << sparseMatrix[i][0] << "    |     " << sparseMatrix[i][1] << "    |    " << sparseMatrix[i][2] << "    |" << endl;
    }
    cout << " ---------------------------------" << endl;

    return 0;
}