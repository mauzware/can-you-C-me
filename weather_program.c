#include <stdio.h>

#define MONTHS 12
#define YEARS 5

int main()
{
	//initialize rainfall data from 2020 to 2025
    float rain[YEARS][MONTHS] =
    {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.1,0.4,2.4,6.6},
        {8.5,8.6,8.2,1.6,6.4,5.7,0.0,2.3,9.1,3.3,2.0,0.8},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,6.2,1.8,4.7,2.6},
        {9.1,2.5,3.4,1.0,1.2,5.4,4.0,5.8,6.2,0.7,8.4,6.3},
        {7.4,5.6,0.0,2.0,6.5,4.3,5.1,1.0,1.5,4.9,7.7,6.2}
    };
    
    int year, month;
    float subtotal, total;
    
    printf("YEAR\t\tRAINFALL (inches) \n");
    
    for (year = 0, total = 0; year < YEARS; year++)
    {
        for (month = 0, subtotal = 0; month < MONTHS; month++)
        {
            subtotal += rain[year][month];
        }
            
        printf("%5d \t%15.1f\n", 2020 + year, subtotal);
        total += subtotal;
    }
    
    printf("\n The yearly average is %.1f inches.\n\n", total/YEARS);
    
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec\n");
    
    for (month = 0; month < MONTHS; month++)
    {
        for (year = 0, subtotal = 0; year < YEARS; year++)
            subtotal += rain[year][month];
            
        printf("%4.1f ", subtotal/YEARS);
    }
    
    printf("\n");
    
	return 0;
}
