#include <stdio.h>

int main(int argc, char **argv)
{
    int minutes = 0;
    double days = 0.0;
    double years = 0.0;
    double minutesInYear = 0.0;
    
    printf("Please enter a number of minutes: ");
    
    //get input from user
    scanf("%d", &minutes);
    
    minutesInYear = (60 * 24 * 365);
    
    years = (minutes / minutesInYear);
    days = (minutes / 60.0 ) / 24.0;
    
    printf("%d minutes is approximately %f years and %f days\n", minutes, years, days);
    printf("Days are equal to: %f\n", days);
    printf("Years are qual to: %f\n", years);
    
    return 0;
    
    
}
