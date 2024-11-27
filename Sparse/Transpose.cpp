#include <iostream>
using namespace std;

class SparseMatrix
{
    int triplet[50][3], result[50][3];
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

        cout << "Transpose of the Matrix:" << endl;
        for (int i = 0; i <= nonZeroCount; i++)
        {
            cout << result[i][0] << "\t" << result[i][1] << "\t" << result[i][2] << endl;
        }
    }
};

int main()
{
    SparseMatrix matrix;
    cout << "Enter details for the matrix:" << endl;
    matrix.getTriplet();

    cout << "Original Matrix:" << endl;
    matrix.displayTriplet();

    cout << "Calculating Transpose..." << endl;
    matrix.transpose();

    return 0;
}