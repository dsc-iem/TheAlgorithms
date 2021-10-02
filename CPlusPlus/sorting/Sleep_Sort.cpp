
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    int a[] = {10,9,8,7,6};
        //int a[]= {9,8,7,6};
    //char a[] = {'c','v','a','d','b'};
        int c = sizeof(a) / sizeof(a[0]);
    while (--c >= 1 && !fork());
        sleep(c = a[c]);
    printf("%d\n", c);
    wait(0);
    return 0;
}