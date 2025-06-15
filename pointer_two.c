#include <stdio.h>
#include <stdlib.h>

void square(int * x);


int main()
{
	int *num = (int *)malloc(sizeof(int));
    *num = 4;
    int bum = 5;
    
    square(&bum);
    square(num);
    
    printf("The square of the given number num is: %d\n", *num);
    printf("The square of the given number bum is: %d\n", bum);
    
	return 0;
}

void square(int * x)
{
    *x = (*x) * (*x);
}
