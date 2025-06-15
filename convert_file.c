#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FILENAME "file.txt"


int main()
{
	FILE *fp = NULL;
    FILE *fp1 = NULL;
    char ch;
    
    fp = fopen(FILENAME, "r");
    
    if(fp == NULL)
        return -1;
        
    //create a temp file
    fp1 = fopen("temp.txt", "w");
    
    if(fp1 == NULL)
        return -1;
        
    while((ch = fgetc(fp)) != EOF)
    {
        if(islower(ch))
        {
            ch = ch - 32;
        }
        
        fputc(ch, fp1);
    }
    
    fclose(fp);
    fclose(fp1);
    
    //rename temp file to file.txt file
    rename("temp.txt", FILENAME);
    
    //remove the temp file
    remove("temp.txt");
    
    fp = fopen(FILENAME, "r");
    
    if(fp == NULL)
        return -1;
        
    while((ch = fgetc(fp)) != EOF)
        printf("%c", ch);
        
    fclose(fp);
    fp = NULL;
    fp1 = NULL;
    
	return 0;
}
