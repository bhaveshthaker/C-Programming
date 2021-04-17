#include <stdio.h>

int main()
{

    int a[][4] = {{3, 6, 8, 9}, {2, 4, 5, 7}, {10, 34, 25, 78}};
    //int *r;

    int *p[4];

    p[0] = &a[0][0];

    p[1] = p[2] = p[3] = &a[2][2];

    printf("%u", p);
    printf("\n%u", *p);
    printf("\n%d", *p[0]);
    printf("\n%u", &a[0][0]);

    int *r = &a[0][0];
    printf("\n\n%u", r);
    r++;
    printf("\n%u", r);
    //p++; // Since p[] is an array, increment of p cannot be performed. Hence p++ is an invalid statement.
    return 0;
}