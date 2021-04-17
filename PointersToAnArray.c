#include <stdio.h>

int main()
{
                //502           518
    int a[][4] = {{7, 2, 6, 1}, {9, 3, 4, 5}, {10, 12, 16, 18}};
    int (*q)[4];
    q = a;  //502
    q++;    //518

    int (*z)[3][4];
    z = a;  //502
    z++; // 550     Which is next Array

    return 0;
}