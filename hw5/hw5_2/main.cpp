#include <iostream>
#define MAX 10000000

using namespace std;

long long int max(long long int a, long long int b)
{
    return a >= b ? a : b;
}


// read file and create an n*n matrix
void create_matrix(long long int n_size,long long int *matrix)
{
    for(long long int i = 0; i < n_size; i++)
    {
        for(long long int j = 0; j < n_size; j++)
        {
            cin >> matrix[i*n_size + j];
        }
    }
    return;
}

// calculate the max sum from the upper-left corner to the lower-right corner
long long int maximum_sum(long long int n_size,long long int *matrix)
{
    /***********************
    *ex: n_size = 4        *
    * 0  1  2  3           *
    * 4  5  6  7           *
    * 8  9  10 11          *
    * 12 13 14 15          *
    ***********************/
    // index is for 1D array turn into 2D
    long long int index = 1;
    while(1)
    {
        // row and column are for 2D array index
        long long int row = index / n_size;
        long long int column = index % n_size;

        for(; column >= 0; row++, column--)
        {
            // target is the index needed to be conquered
            long long int target = row*n_size + column;
            // the case is the top row
            if(row == 0)
                matrix[target] += matrix[target-1];
            // the case is the leftmost column
            else if( target % n_size == 0)
                matrix[target] += matrix[ (row-1)*n_size + column];
            // others
            else
                matrix[target] += max(matrix[target-1], matrix[ (row-1)*n_size + column] );
        }


        /*************************************
        * so the index will go on            *
        * 0 1 2 3 7 11 15, and break;        *
        *************************************/
        if(index == n_size*n_size - 1)
            break;
        else if(index % n_size == n_size-1)
            index += n_size;
        else
            index++;
    }

    return matrix[n_size*n_size-1];
}

int main()
{
    long long int n_size;
    long long int *matrix;
    matrix = new long long int[MAX]();

    cin >> n_size;
    create_matrix(n_size, matrix);
    cout << maximum_sum(n_size, matrix) << endl;

    return 0;
}
