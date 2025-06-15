#include <stdio.h>
#include <stdlib.h>

int stringLength(const char *string);

int main()
{
	printf("%d \n", stringLength("stringLength test"));
    printf("%d \n", stringLength(""));
    printf("%d \n", stringLength("bimboje"));
    printf("%d \n", stringLength("smrad"));
    printf("%d \n", stringLength("bu"));
    
	return 0;
}

int stringLength(const char *string)
{
    const char *lastAddress = string; //local pointer that points to the address before null terminator
    
    while(*lastAddress)
        ++lastAddress;
        
    return lastAddress - string;
}