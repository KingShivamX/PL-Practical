#include <iostream>
using namespace std;

class SparseMatrix
{
    int triplet[50][3];
    int result[150][3];
    int rows, cols, nonZeroCount;

public:
    SparseMatrix(int r = 0, int c = 0, int n = 0) : rows(r), cols(c), nonZeroCount(n) {}

    void getTriplet()
    {
        cout << "Enter the matrix dimensions and number of non-zero elements: ";
        cin >> rows >> cols >> nonZeroCount;
        for (int i = 1; i <= nonZeroCount; i++)
        {
            cin >> triplet[i][0] >> triplet[i][1] >> triplet[i][2];
        }
        triplet[0][0] = rows;
        triplet[0][1] = cols;
        triplet[0][2] = nonZeroCount;
    }

    void displayTriplet()
    {
        for (int i = 0; i <= nonZeroCount; i++)
        {
            cout << triplet[i][0] << "\t" << triplet[i][1] << "\t" << triplet[i][2] << endl;
        }
    }

    void addition(SparseMatrix s2)
    {
        int result[100][3];
        int i = 1, j = 1, k = 1;

        if (triplet[0][0] == s2.triplet[0][0] && triplet[0][1] == s2.triplet[0][1])
        {
            result[0][0] = triplet[0][0];
            result[0][1] = triplet[0][1];

            while (i <= nonZeroCount && j <= s2.nonZeroCount)
            {
                if (triplet[i][0] == s2.triplet[j][0])
                {
                    if (triplet[i][1] == s2.triplet[j][1])
                    {
                        result[k][0] = triplet[i][0];
                        result[k][1] = triplet[i][1];
                        result[k][2] = triplet[i][2] + s2.triplet[j][2];
                        i++;
                        j++;
                    }
                    else if (triplet[i][1] < s2.triplet[j][1])
                    {
                        result[k][0] = triplet[i][0];
                        result[k][1] = triplet[i][1];
                        result[k][2] = triplet[i][2];
                        i++;
                    }
                    else
                    {
                        result[k][0] = s2.triplet[j][0];
                        result[k][1] = s2.triplet[j][1];
                        result[k][2] = s2.triplet[j][2];
                        j++;
                    }
                }
                else if (triplet[i][0] < s2.triplet[j][0])
                {
                    result[k][0] = triplet[i][0];
                    result[k][1] = triplet[i][1];
                    result[k][2] = triplet[i][2];
                    i++;
                }
                else
                {
                    result[k][0] = s2.triplet[j][0];
                    result[k][1] = s2.triplet[j][1];
                    result[k][2] = s2.triplet[j][2];
                    j++;
                }
                k++;
            }

            while (i <= nonZeroCount)
            {
                result[k][0] = triplet[i][0];
                result[k][1] = triplet[i][1];
                result[k][2] = triplet[i][2];
                i++;
                k++;
            }

            while (j <= s2.nonZeroCount)
            {
                result[k][0] = s2.triplet[j][0];
                result[k][1] = s2.triplet[j][1];
                result[k][2] = s2.triplet[j][2];
                j++;
                k++;
            }

            result[0][2] = k - 1;
        }
        else
        {
            cout << "Matrices cannot be added" << endl;
            return;
        }

        for (int i = 0; i < k; i++)
        {
            cout << result[i][0] << "\t" << result[i][1] << "\t" << result[i][2] << endl;
        }
    }

    void transpose()
    {
        int k = 1;
        for (int i = 0; i < cols; i++)
        {
            for (int j = 1; j <= nonZeroCount; j++)
            {
                if (triplet[j][1] == i)
                {
                    result[k][0] = triplet[j][1];
                    result[k][1] = triplet[j][0];
                    result[k][2] = triplet[j][2];
                    k++;
                }
            }
        }

        result[0][0] = cols;
        result[0][1] = rows;
        result[0][2] = nonZeroCount;
    }

    void displayResult()
    {
        for (int i = 0; i <= result[0][2]; i++)
        {
            cout << result[i][0] << "\t" << result[i][1] << "\t" << result[i][2] << endl;
        }
    }

    void fastTranspose()
    {
        int total[50] = {0};
        int index[50];

        for (int i = 1; i <= nonZeroCount; i++)
        {
            ++total[triplet[i][1]];
        }

        index[0] = 1;
        for (int i = 1; i < cols; i++)
        {
            index[i] = index[i - 1] + total[i - 1];
        }

        for (int i = 1; i <= nonZeroCount; i++)
        {
            int col = triplet[i][1];
            int pos = index[col];
            result[pos][0] = triplet[i][1];
            result[pos][1] = triplet[i][0];
            result[pos][2] = triplet[i][2];
            ++index[col];
        }

        result[0][0] = triplet[0][1];
        result[0][1] = triplet[0][0];
        result[0][2] = triplet[0][2];
    }

    void multiplication(SparseMatrix s2)
    {
        int product[100][3] = {0};

        if (cols != s2.rows)
        {
            cout << "Multiplication not possible" << endl;
            return;
        }

        int k = 1;
        for (int i = 1; i <= nonZeroCount; i++)
        {
            int row1 = triplet[i][0];
            int col1 = triplet[i][1];
            int val1 = triplet[i][2];

            for (int j = 1; j <= s2.nonZeroCount; j++)
            {
                int row2 = s2.triplet[j][0];
                int col2 = s2.triplet[j][1];
                int val2 = s2.triplet[j][2];

                if (col1 == row2)
                {
                    bool found = false;

                    for (int l = 1; l < k; l++)
                    {
                        if (product[l][0] == row1 && product[l][1] == col2)
                        {
                            product[l][2] += val1 * val2;
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        product[k][0] = row1;
                        product[k][1] = col2;
                        product[k][2] = val1 * val2;
                        k++;
                    }
                }
            }
        }

        product[0][0] = rows;
        product[0][1] = s2.cols;
        product[0][2] = k - 1;

        for (int i = 0; i < k; i++)
        {
            cout << product[i][0] << "\t" << product[i][1] << "\t" << product[i][2] << endl;
        }
    }
};

int main()
{
    SparseMatrix matrix1, matrix2;
    int rowCount, colCount, nonZeroCount;
    char choice;
    bool continueProgram = true;

    matrix1.getTriplet();

    do
    {
        cout << endl;
        cout << "1. Display triplet representation of first matrix" << endl;
        cout << "2. Add two sparse matrices" << endl;
        cout << "3. Transpose of the first matrix" << endl;
        cout << "4. Fast Transpose of the first matrix" << endl;
        cout << "5. Multiply two sparse matrices" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        int option;
        cin >> option;

        switch (option)
        {
        case 1:
            matrix1.displayTriplet();
            break;

        case 2:
            matrix2.getTriplet();
            matrix1.addition(matrix2);
            break;

        case 3:
            matrix1.transpose();
            matrix1.displayResult();
            break;

        case 4:
            matrix1.fastTranspose();
            matrix1.displayResult();
            break;

        case 5:
            matrix2.getTriplet();
            matrix1.multiplication(matrix2);
            break;

        case 6:
            continueProgram = false;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    } while (continueProgram);

    return 0;
}