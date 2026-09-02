#include <iostream>
#include <vector>
using namespace std;

// perform addition 
int addValue(int num1, int num2) {
    return num1 + num2;   
}

// perform subtration
int subValue(int num1, int num2) {
    return num1 - num2;   
}

// perform multiplication
int mulValue(int num1, int num2) {
    return num1 * num2;   
}

// perform division 
int divValue(int num1, int num2) {
    if (num2 == 0) {
        cout << "Error: Division by zero! ";
        return 0;
    }
    return num1 / num2;   
}

int main() {
    int rows, cols;

    cout << "Enter the no. of rows: ";
    cin >> rows;

    cout << "Enter the no. of columns: ";
    cin >> cols;
    
    if (rows <= 0 || cols <= 0) {
        cout << "Please enter positive numbers!!" << endl;
        return 0;
    }
    
    // accept the input matrix 
   int matrix[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter the element at position " << i << " , " << j << " : ";
            cin >> matrix[i][j];
        }
    }
    
    // perform operation 
    int ch = 0;
    do {
        cout << "\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Display\n6. Exit" << endl;
        cout << "Enter the operation code (1 to 6): ";
        cin >> ch;
        
        if (ch == 6) {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }
        
        if (ch < 1 || ch > 6) {
            cout << "Please enter a valid operation code!!" << endl;
            continue;
        }
        
        cout << "\nResult Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                switch (ch) {
                    case 1:
                        cout << addValue(matrix[i][j], matrix[i][j]) << "\t";
                        break;
                    case 2:
                        cout << subValue(matrix[i][j], matrix[i][j]) << "\t";
                        break;
                    case 3:
                        cout << mulValue(matrix[i][j], matrix[i][j]) << "\t";
                        break;
                    case 4:
                        cout << divValue(matrix[i][j], matrix[i][j]) << "\t";
                        break;
                    case 5:
                        cout << matrix[i][j] << "\t";
                        break;
                }
            }
            cout << "\n";
        }
    } while (ch != 6);

    return 0;
}