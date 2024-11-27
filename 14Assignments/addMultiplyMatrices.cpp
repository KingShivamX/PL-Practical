#include <iostream>
using namespace std;

void addmatrices(int matrix[10][10], int matrixb[10][10], int rowsa, int colsa, int summatrix[10][10]){
    for(int i = 0; i < rowsa; i++){
        for(int j = 0; j < colsa; j++){
            summatrix[i][j] = matrix[i][j] + matrixb[i][j];
        }
    }
}

void multiplymatrices(int matrix[10][10], int matrixb[10][10], int rowsa, int colsa, int multiplymatrix[10][10]){
    for(int i = 0; i < rowsa; i++){
        for(int j = 0; j < colsa; j++){
            multiplymatrix[i][j] = 0;
            for(int k = 0; k < colsa; k++){
                multiplymatrix[i][j] += matrix[i][k] * matrixb[k][j];
            }
        }
    }
}

int main() {
    int rowsa, rowsb, colsa, colsb;
    int matrix[10][10], matrixb[10][10], summatrix[10][10], multiplymatrix[10][10];

    cout << "Enter rows and columns for matrix A : " << endl;
    cin >> rowsa >> colsa;

    cout << "Enter elements of Matrix A : " << endl;
    for(int i = 0; i < rowsa; i++){
        for(int j = 0; j < colsa; j++){
            cin >> matrix[i][j];
        }
    }

    cout << "Elements of Matrix A : " << endl;
    for(int i = 0; i < rowsa; i++){
        for(int j = 0; j < colsa; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter rows and columns of matrix B : " << endl;
    cin >> rowsb >> colsb;

    cout << "Enter elements of Matrix B : " << endl;
    for(int i = 0; i < rowsb; i++){
        for(int j = 0; j < colsb; j++){
            cin >> matrixb[i][j];
        }
    }

    if(colsa != rowsb){
        cout << "Error: Matrix dimensions do not allow multiplication.\n";
        return 0; // Exit the program
    }

    cout << "Elements of Matrix B : " << endl;
    for(int i = 0; i < rowsb; i++){
        for(int j = 0; j < colsb; j++){
            cout << matrixb[i][j] << " ";
        }
        cout << endl;
    }

    if(colsa == colsb && rowsa == rowsb){
        addmatrices(matrix, matrixb, rowsa, colsa, summatrix);

        cout << "Sum of Matrices : " << endl;
        for(int i = 0; i < rowsa; i++){
            for(int j = 0; j < colsa; j++){
                cout << summatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Error: Matrix dimensions do not match for addition.\n";
    }

    multiplymatrices(matrix, matrixb, rowsa, colsa, multiplymatrix);

    cout << "Product of the matrices:\n";
    for (int i = 0; i < rowsa; i++) {
        for (int j = 0; j < colsb; j++) {
            cout << multiplymatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
