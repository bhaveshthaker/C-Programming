/**
 * @author  Bhaveshkumar Thaker
 */
#include <stdio.h>

int main()
{
    int a[] = {7, 9, 16, -2, 8};

    printf("%d %d %d", &a[0], &a[1], &a[2]);
    printf("\n\n");
    printf("%d %d %d", a, a + 1, a + 2);

    printf("\n\n");
    int size = sizeof a / sizeof a[0];
    for (int i = 0; i < size; i++)
    {
        //Pointer Notation is faster than Subscript Notation.
        printf("%d\t", *(a + i)); //Pointer Notation
    }
    printf("\n\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", a[i]); //Subscript Notation
    }
    printf("\n\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", i[a]); //a[i] == i[a]
    }
    return 0;
}