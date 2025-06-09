#include <stdio.h>

//creating constants
#define PAYRATE 12.00
#define TAXRATE_300 .15
#define TAXRATE_150 .20
#define TAXRATE_REST .25
#define OVERTIME 40

int main()
{
	//declaring local variables
    int hours = 0;
    double gross = 0.0;
    double taxes = 0.0;
    double net = 0.0;
    
    printf("Please enter the number of hours worked this week: ");
    
    //get the input
    scanf("%d", &hours);
    
    //calculate the gross pay
    if (hours <= 40)
        gross = hours * PAYRATE;
        
    else
    {
        gross = 40 * PAYRATE;
        double overtimePay = (hours - 40) * (PAYRATE * 1.5);
        gross += overtimePay;
    }
    
    
    //calculate the taxes
    if (gross <= 300) //15% taxes for the first $300
        taxes = gross * TAXRATE_300;
        
    else if (gross > 300 && gross <= 450) //20% taxes for the next $150
    {
        taxes = 300 * TAXRATE_300;
        taxes += (gross - 300) * TAXRATE_150;
    }
    
    else if (gross > 450) //25% taxes for the rest
    {
        taxes = 300 * TAXRATE_300;
        taxes += 150 * TAXRATE_150;
        taxes += (gross - 450) * TAXRATE_REST;
    }
    
    //calculate net pay
    net = gross - taxes;
    
    //display output
    printf("Your gross pay this week is: %.2f\n", gross);
    printf("Your taxes this week is: %.2f\n", taxes);
    printf("Your net pay this week is: %.2f\n", net);
    
    
	return 0;
}
