/**
 * @author  Bhaveshkumar Thaker
 */
#include <stdio.h>

int main()
{
    int num, i, k;
    int count = 0;

    scanf("%d", &num);

    if (num >= 0)
    {
        for (i = 1; i <= num; i++)
        {
            k = i;
            while (k % 5 == 0)
            {
                count++;
                k = k / 5;
            }
        }

        printf("%d", count);
    }
    else
    {
        printf("Invalid input\n");
    }

    return 0;
}