#include <iostream>
#include <algorithm>

using namespace std;

struct Num{
    int two = 0;
    int five = 0;
};

Num matrix[301][301];

int factorization(int ori, int mod)
{
    int count_num = 0;

    if(ori == 0)
        return 0;

    while(ori % mod == 0)
    {
        count_num++;
        ori /= mod;
    }
    return count_num;
}

void create_matrix(int n_size)
{
    for(int i = 0; i < n_size; i++)
    {
        for(int j = 0; j < n_size; j++)
        {
            int origin;
            cin >> origin;
            matrix[i][j].five = factorization(origin, 5);
            matrix[i][j].two = factorization(origin, 2);
        }
    }
    return;
}

int find_min_trailing_zeros(int n_size)
{
    int row = 0, column = 1;
    while(1)
    {
        int i = row;
        int j = column;
        for(; j >= 0; i++, j--)
        {
            // the case is the top row
            if(i == 0)
            {
                matrix[i][j].five += matrix[i][j-1].five;
                matrix[i][j].two += matrix[i][j-1].two;
            }
            // the case is the leftmost column
            else if(j == 0)
            {
                matrix[i][j].five += matrix[i-1][j].five;
                matrix[i][j].two += matrix[i-1][j].two;
            }
            // others
            else
            {
                matrix[i][j].five += min(matrix[i][j-1].five, matrix[i-1][j].five);
                matrix[i][j].two += min(matrix[i][j-1].two, matrix[i-1][j].two);
            }
        }
        if(row == n_size-1 && column == n_size-1)
            break;
        else if(column == n_size-1)
            row++;
        else
            column++;
    }
    return min(matrix[n_size-1][n_size-1].five, matrix[n_size-1][n_size-1].two);
}

int main()
{
    int n_size;

    cin >> n_size;
    create_matrix(n_size);
    cout << find_min_trailing_zeros(n_size) << endl;

    return 0;
}
