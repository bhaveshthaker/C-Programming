/*
#include <stdio.h>

int main()
{
    int i = 10;
    int *ptr;
    ptr = &i;
    printf("%d\n", ++(*ptr));
    return 0;
}
*/
#include <stdio.h>

int main()
{
    int i = 10;
    int *ptr;
    ptr = &i;
    printf("%d\n", ++*ptr);
    return 0;
}
/*
#include <stdio.h>

int main()
{
    int i = 10;
    int *ptr;
    ptr = &i;
    printf("%d\n", ptr);
    printf("%d\n", ++ptr);
    return 0;
}
*/