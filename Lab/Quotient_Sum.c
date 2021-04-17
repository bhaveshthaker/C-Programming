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
    int n = 0, k = 0;
    int quotient_sum = 0;
    scanf("%d %d", &n, &k);

    for (int i = 1; i < n; i = i * k)
    {
        quotient_sum = quotient_sum + n / i;
    }
    printf("%d", quotient_sum);
    return 0;
}
