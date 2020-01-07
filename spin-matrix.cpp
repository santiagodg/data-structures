#include <iostream>    /* cin, cout, endl */
#include <cmath>       /* abs */
using namespace std;

void spinMatrix(int **matrix, int size, int spins);

int main()
{
    const int size = 4;
    int **matrix, n, row, col;

    // allocate matrix
    matrix = new int *[size];
    for (int i = 0; i < size; ++i)
    {
        matrix[i] = new int[size];
    }

    // input
    cin >> n;
    for (row = 0; row < size; ++row)
    {
        for (col = 0; col < size; ++col)
        {
            cin >> matrix[row][col];
        }
    }

    // process
    spinMatrix(matrix, size, n);

    // output
    for (row = 0; row < size; ++row)
    {
        for (col = 0; col < size; ++col)
        {
            cout << matrix[row][col];
            if (row != size - 1 || col != size - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    // deallocate matrix
    for (int i = 0; i < size; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    // end
    return 0;
}

void spinMatrix(int **matrix, int size, int spins)
{
    int layer, pos, temp;

    // calculate spins
    spins = ((spins >= 0) ? (spins % 4) : ((4 - (abs(spins) % 4)) % 4));

    // transpose
    switch (spins)
    {
        case 0:
            break;

        case 1:
            // layer
            for (layer = 0; layer < size / 2; ++layer)
            {
                // position
                for (pos = layer; pos < size - 1 - layer; ++pos)
                {
                    temp = matrix[layer][pos];
                    matrix[layer][pos] = matrix[size - 1 - pos][layer];
                    matrix[size - 1 - pos][layer] = matrix[size - 1 - layer][size - 1 - pos];
                    matrix[size - 1 - layer][size - 1 - pos] = matrix[pos][size - 1 - layer];
                    matrix[pos][size - 1 - layer] = temp;
                }
            }
            break;

        case 2:
            // layer
            for (layer = 0; layer < size / 2; ++layer)
            {
                // position
                for (pos = layer; pos < size - 1 - layer; ++pos)
                {
                    temp = matrix[layer][pos];
                    matrix[layer][pos] = matrix[size - 1 - layer][size - 1 - pos];
                    matrix[size - 1 - layer][size - 1 - pos] = temp;
                    temp = matrix[pos][size - 1 - layer];
                    matrix[pos][size - 1 - layer] = matrix[size - 1 - pos][layer];
                    matrix[size - 1 - pos][layer] = temp;
                }
            }
            break;

        case 3:
            // layer
            for (layer = 0; layer < size / 2; ++layer)
            {
                // position
                for (pos = layer; pos < size - 1 - layer; ++pos)
                {
                    temp = matrix[layer][pos];
                    matrix[layer][pos] = matrix[pos][size - 1 - layer];
                    matrix[pos][size - 1 - layer] = matrix[size - 1 - layer][size - 1 - pos];
                    matrix[size - 1 - layer][size - 1 - pos] = matrix[size - 1 - pos][layer];
                    matrix[size - 1 - pos][layer] = temp;
                }
            }
            break;
    }
}
