#include <iostream>
using namespace std;

class SparseMatrix
{
    int triplet[50][3];
    int rows, cols, nonZeroCount;

public:
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

    void multiplication(SparseMatrix s2)
    {
        if (cols != s2.rows)
        {
            cout << "Matrices cannot be multiplied!" << endl;
            return;
        }

        int result[100][3] = {0}, k = 1;

        for (int i = 1; i <= nonZeroCount; i++)
        {
            for (int j = 1; j <= s2.nonZeroCount; j++)
            {
                if (triplet[i][1] == s2.triplet[j][0])
                {
                    bool found = false;
                    for (int l = 1; l < k; l++)
                    {
                        if (result[l][0] == triplet[i][0] && result[l][1] == s2.triplet[j][1])
                        {
                            result[l][2] += triplet[i][2] * s2.triplet[j][2];
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        result[k][0] = triplet[i][0];
                        result[k][1] = s2.triplet[j][1];
                        result[k][2] = triplet[i][2] * s2.triplet[j][2];
                        k++;
                    }
                }
            }
        }

        result[0][0] = rows;
        result[0][1] = s2.cols;
        result[0][2] = k - 1;

        cout << "Resultant Matrix after Multiplication:" << endl;
        for (int i = 0; i < k; i++)
        {
            cout << result[i][0] << "\t" << result[i][1] << "\t" << result[i][2] << endl;
        }
    }
};

int main()
{
    SparseMatrix matrix1, matrix2;
    cout << "Enter details for the first matrix:" << endl;
    matrix1.getTriplet();

    cout << "Enter details for the second matrix:" << endl;
    matrix2.getTriplet();

    cout << "First Matrix:" << endl;
    matrix1.displayTriplet();

    cout << "Second Matrix:" << endl;
    matrix2.displayTriplet();

    cout << "Multiplying Matrices..." << endl;
    matrix1.multiplication(matrix2);

    return 0;
}