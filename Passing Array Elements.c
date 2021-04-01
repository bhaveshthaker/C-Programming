#include <stdio.h>

void display(int);
void displayNum(int *, int);

int main()
{
    int arr[] = {1,
                 2,
                 3,
                 4,
                 5,
                 6,
                 7,
                 8,
                 9,
                 10,
                 11,
                 12,
                 13,
                 14,
                 15};

    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        display(arr[i]);
    }
    printf("\n\n");

    displayNum(arr, size);
    return 0;
}

void display(int j)
{
    printf("%d ", j);
}

void displayNum(int *arrptr, int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("%d ", *(arrptr + i));
        //printf("%d ", arrptr[i]);
    }
}