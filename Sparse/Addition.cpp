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

    void addition(SparseMatrix s2)
    {
        int result[100][3], i = 1, j = 1, k = 1;

        if (triplet[0][0] == s2.triplet[0][0] && triplet[0][1] == s2.triplet[0][1])
        {
            result[0][0] = triplet[0][0];
            result[0][1] = triplet[0][1];

            while (i <= triplet[0][2] && j <= s2.triplet[0][2])
            {
                if (triplet[i][0] == s2.triplet[j][0] && triplet[i][1] == s2.triplet[j][1])
                {
                    result[k][0] = triplet[i][0];
                    result[k][1] = triplet[i][1];
                    result[k][2] = triplet[i][2] + s2.triplet[j][2];
                    i++;
                    j++;
                }
                else if (triplet[i][0] < s2.triplet[j][0] ||
                         (triplet[i][0] == s2.triplet[j][0] && triplet[i][1] < s2.triplet[j][1]))
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

            while (i <= triplet[0][2])
            {
                result[k][0] = triplet[i][0];
                result[k][1] = triplet[i][1];
                result[k][2] = triplet[i][2];
                i++;
                k++;
            }
            while (j <= s2.triplet[0][2])
            {
                result[k][0] = s2.triplet[j][0];
                result[k][1] = s2.triplet[j][1];
                result[k][2] = s2.triplet[j][2];
                j++;
                k++;
            }
            result[0][2] = k - 1;

            cout << "Resultant Matrix:" << endl;
            for (int i = 0; i < k; i++)
            {
                cout << result[i][0] << "\t" << result[i][1] << "\t" << result[i][2] << endl;
            }
        }
        else
        {
            cout << "Matrices cannot be added!" << endl;
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

    cout << "Adding Matrices..." << endl;
    matrix1.addition(matrix2);

    return 0;
}