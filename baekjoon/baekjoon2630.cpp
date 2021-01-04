#include<iostream>

int blue = 0;
int white = 0;
int Is_same_color(int** Square, int row, int col, int length)
{
    for (int i = row; i < row+length; i++)
    {
        for (int j = col; j < col+length; j++)
        {
            if (Square[row][col] != Square[i][j])
            {
                Is_same_color(Square, row, col, length / 2);
                Is_same_color(Square, row, col+length / 2, length / 2);
                Is_same_color(Square, row+length / 2, col, length / 2);
                Is_same_color(Square, row+length / 2, col+length / 2, length / 2);
                return 0;
            }
        }
     }

    if (Square[row][col] == 1)
        blue++;
    else
        white++;
     return 0;
    
 }




int main()
{
    int N = 0;
    std::cin >> N;
    int** Square = new int* [N];
    for (int i = 0; i < N; i++)
    {
        Square[i] = new int[N];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> Square[i][j];
        }
    }
    Is_same_color(Square, 0, 0, N);
    std::cout << white <<std::endl << blue;
    

}