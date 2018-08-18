/* 
    Author: Pham Trong Nhan 
    Date: 18/8/2018
    This is another solution for exercise which apply Recursion & Math.
    Just text me if there is any trouble, I still try to explain every function in this file.
*/

#include <iostream>
#include <climits>
#include <math.h>

// I can create dynamic allocation, but with N=100, it's necessary
const int N = 100;
int dim;           // Dimension
int max = INT_MIN; // Max sum
int array[N][N];
int sum[N][N];          // sum of rectangle from (0,0) to (a,b)
bool check[N][N][N][N]; // Check rectangle (a, b) -> (c,d) has been calculate

// This function calculate the sum of rectangle from (0,0) to (a,b)
void calculate_sum()
{
    sum[0][0] = array[0][0];

    for (int i = 1; i < dim; i++)
    {
        // Sum (0,0) -> (i, 0)
        sum[i][0] = sum[i - 1][0] + array[i][0];
    }
    for (int i = 1; i < dim; i++)
    {
        // Sum (0,0) -> (0, i)
        sum[0][i] = sum[0][i - 1] + array[0][i];
    }

    for (int i = 1; i < dim; i++)
    {
        for (int j = 1; j < dim; j++)
        {
            // Sum (0,0) -> (a,b)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + array[i][j] - sum[i - 1][j - 1];
        }
    }
}

void divide_max(int a, int b, int c, int d)
// Max sum in rectangle (a,b) -> (c,d)
{

    if (check[a][b][c][d] == 1)
    {
        return;
    }

    // Sum (a,b) -> (c,d)
    int value = sum[c][d] + sum[a - 1][b - 1] - sum[a - 1][d] - sum[c][b - 1];
    if (value > max)
    {
        max = value;
        check[a][b][c][d] = 1;
    }

    // Split rectangle to smaller one
    // Divide by row
    for (int i = a; i < c; i++)
        // Divide by column
        for (int j = b; j < d; j++)
        {
            divide_max(a, b, i, j);
            divide_max(a, j + 1, i, d);
            divide_max(i + 1, b, c, j);
            divide_max(i + 1, j + 1, c, d);
        }
}

int main()
{
    // I assumed that CodeForces input type just like VNOI's
    // If it doesn't work, just let me know

    std::cin >> dim;

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            int temp;
            std::cin >> temp;
            array[i][j] = temp;
        }
    }

    calculate_sum();
    divide_max(0, 0, dim - 1, dim - 1);
    std::cout << max;
}