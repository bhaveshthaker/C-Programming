#include <stdio.h>

void fun(int *i)
{
    ++*i;
}

int main()
{
    int i = 1;
    i++;
    fun(&i);
    printf("%d", i);
    return 0;
}