#include <stdio.h>

void display(int q[][4] , int, int);

int main()
{
    int a[][4] = {
        {2, 6, 9, 3},
        {5, 3, 7, 1},
        {4, 6, 8, 3}};

    display(a, 3, 4);
    return 0;
}

void display(int q[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", q[i][j]);
        }
        printf("\n");
    }
}