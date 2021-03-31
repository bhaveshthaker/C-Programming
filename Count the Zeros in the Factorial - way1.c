/**
 * @author  Bhaveshkumar Thaker
 */
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main()
{
    int num = 0, count = 0;
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Invalid input");
    }
    else
    {
        while (num >= 1)
        {
            if ((num % 5) == 0)
            {
                count++;
            }
            num--;
        }
        printf("%d", count);
    }

    return 0;
}