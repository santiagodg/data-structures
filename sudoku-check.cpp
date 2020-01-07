#include <iostream>    /* cout, cin, endl */
#include <cmath>       /* sqrt */
using namespace std;

bool checkSudoku(int **sudoku, const int size);

int main()
{
    const int size = 9;
    int **sudoku, row, col, index;

    // allocate matrix
    sudoku = new int *[size];
    for (index = 0; index < size; ++index)
    {
        sudoku[index] = new int[size];
    }

    // input
    /*
    int testSudoku[size][size] = {{4, 3, 5, 2, 6, 9, 7, 8, 1},
                                  {6, 8, 2, 5, 7, 1, 4, 9, 3},
                                  {1, 9, 7, 8, 3, 4, 5, 6, 2},
                                  {8, 2, 6, 1, 9, 5, 3, 4, 7},
                                  {3, 7, 4, 6, 8, 2, 9, 1, 5},
                                  {9, 5, 1, 7, 4, 3, 6, 2, 8},
                                  {5, 1, 9, 3, 2, 6, 8, 7, 4},
                                  {2, 4, 8, 9, 5, 7, 1, 3, 6},
                                  {7, 6, 3, 4, 1, 8, 2, 5, 9}};
    for (row = 0; row < size; ++row)
    {
        for (col = 0; col < size; ++col)
        {
            sudoku[row][col] = testSudoku[row][col];
        }
    }
    */
    for (row = 0; row < size; ++row)
    {
        for (col = 0; col < size; ++col)
        {
            cin >> sudoku[row][col];
        }
    }
    
    // output
    cout << (checkSudoku(sudoku, size) ? "YES" : "NO") << endl;
    
    // deallocate matrix
    for (index = 0; index < size; ++index)
    {
        delete[] sudoku[index];
    }
    delete[] sudoku;

    // end
    return 0;
}

bool checkSudoku(int **sudoku, const int size)
{
    bool array[size];
    int squareSize = sqrt(size), squareRow, squareCol, posX, posY, index, row, col;
    
    // check rows
    for (row = 0; row < size; ++row)
    {
        for (index = 0; index < size; ++index)
        {
            array[index] = false;
        }
        for (col = 0; col < size; ++col)
        {
            array[sudoku[row][col] - 1] = !array[sudoku[row][col] - 1];
        }
        for (index = 0; index < size; ++index)
        {
            if (!array[index])
            {
                return false;
            }
        }
    }

    // check columns
    for (col = 0; col < size; ++col)
    {
        for (index = 0; index < size; ++index)
        {
            array[index] = false;
        }
        for (row = 0; row < size; ++row)
        {
            array[sudoku[row][col] - 1] = !array[sudoku[row][col] - 1];
        }
        for (index = 0; index < size; ++index)
        {
            if (!array[index])
            {
                return false;
            }
        }
    }

    // check small squares
    for (squareRow = 0; squareRow < squareSize; ++squareRow)
    {
        for (squareCol = 0; squareCol < squareSize; ++squareCol)
        {
            for (index = 0; index < size; ++index)
            {
                array[index] = false;
            }
            for (posY = 0; posY < squareSize; ++posY)
            {
                for (posX = 0; posX < squareSize; ++posX)
                {
                    array[sudoku[posY + (3 * squareRow)][posX + (3 * squareCol)] - 1] = !array[sudoku[posY + (3 * squareRow)][posX + (3 * squareCol)] - 1];
                }
            }
            for (index = 0; index < size; ++index)
            {
                if (!array[index])
                {
                    return false;
                }
            }
        }
    }

    return true;
}
