#include <stdio.h>

int main()
{
    int a = 25, *b;
    float i = 3.14, *j;
    char ch = 'z', *dh;

    b = &a;
    j = &i;
    dh = &ch;

    printf("%u %u %u\n", b, j, dh);
    b++, j++, dh++;
    printf("%u %u %u\n", b, j, dh);
    b += 4, j += 12, dh -= 8;
    printf("%u %u %u\n", b, j, dh);

    /*
    Array elements using pointers
    */
    int x[] = {7, 9, 16, -2, 8};
    int *ptr;
    ptr = x;            // ptr = &x[0];
    printf("%d", *ptr); // Value at location x
    printf("\n");
    printf("%u", ptr); // Address of location x

    printf("\n");
    int size = sizeof(x) / sizeof(x[0]);
    for (int z = 0; z < size; z++)
    {
        printf("%d\t", *ptr); // Value at location
        printf("%u\n", ptr);  // Address of location
        ptr++;                // Pointer increment to get next location
    }

    printf("\n%d\n", *ptr++); // *ptr = *ptr + 1

    for (int z = 0; z < size; z++)
    {
        printf("%u\t%u\t%u\t%u\n", *(ptr + z), *(z + ptr), ptr[z], z[ptr]);
    }
}