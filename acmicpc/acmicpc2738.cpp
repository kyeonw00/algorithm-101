#include <iostream>

using namespace std;

int main()
{
    const int MatrixMaxSize = 100;

    int matrix[MatrixMaxSize][MatrixMaxSize];

    int n, m;
    cin >> n >> m;

    int element;

    // read elements for matrix A
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            cin >> element;
            matrix[row][column] = element;
        }
    }

    // read elements for matrix B
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            cin >> element;
            matrix[row][column] += element;
        }
    }

    // write out the matrix summary
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < m; column++)
        {
            cout << matrix[row][column] << ' ';
        }

        cout << '\n';
    }

    return 0;
}

// int main()
// {
//     const int MatrixMaxSize = 100;

//     int matrixA[MatrixMaxSize][MatrixMaxSize];
//     int matrixB[MatrixMaxSize][MatrixMaxSize];

//     int n, m;
//     cin >> n >> m;

//     // read elements for matrix A
//     for (int row = 0; row < n; row++)
//     {
//         for (int column = 0; column < m; column++)
//         {
//             cin >> matrixA[row][column];
//         }
//     }

//     // read elements for matrix B
//     for (int row = 0; row < n; row++)
//     {
//         for (int column = 0; column < m; column++)
//         {
//             cin >> matrixB[row][column];
//         }
//     }

//     // write out the matrix summary
//     for (int row = 0; row < n; row++)
//     {
//         for (int column = 0; column < m; column++)
//         {
//             cout << (matrixA[row][column] + matrixB[row][column]) << ' ';
//         }

//         cout << '\n';
//     }

//     return 0;
// }