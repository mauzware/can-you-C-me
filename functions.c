#include <stdio.h>

int gcd(int a, int b);
float absolute_value(float x);
float square_root(float y);

int main()
{
	int result = 0;
    
    float f1 = 15.5, f2 = 20.0, f3 = -5.0;
    int i1 = -716;
    float absolute_result = 0.0;
    
    
    //testing gcd function
    result = gcd(150, 35);
    printf("The gcd of 150 and 35 is: %d\n", result);
    
    result = gcd(1026, 405);
    printf("The gcd of 1026 and 405 is: %d\n", result);
    
    printf("The gcd of 83 and 240 is: %d\n", gcd(83, 240));
    
    printf("\n");
    
    //testing absolute value function
    absolute_result = absolute_value(f1);
    printf("Result = %.2f\n", absolute_result);
    printf("f1 = %.2f\n", f1);
    
    absolute_result = absolute_value(f2) + absolute_value(f3);
    printf("Result = %.2f\n", absolute_result);
    
    absolute_result = absolute_value((float) i1);
    printf("Result = %.2f\n", absolute_result);
    
    printf("Result = %.2f\n", absolute_value((-6.0) / 4));
    
    printf("\n");
    
    //testing square root function
    
    printf("%.2f\n", square_root(-3.0));
    printf("%.2f\n", square_root(16.0));
    printf("%.2f\n", square_root(25.0));
    printf("%.2f\n", square_root(9.0));
    printf("%.2f\n", square_root(125.0));
    
    
	return 0;
}

//gcd function
int gcd(int a, int b)
{
    int temp;
    
    while( b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    
    return a;
}

//square root function
float square_root(float y)
{
    const float epsilon = .00001;
    float guess = 1.0;
    float return_value = 0.0;
    
    
    if (y < 0)
    {
        printf("Negative argument %.2f to square root. You suck broski!\n", y);
        return_value = 1.0;
    }
    
    else
    {
        while (absolute_value(guess * guess - y) >= epsilon)
            guess = (y / guess + guess) / 2.0;
            
        return_value = guess;
    }
    
    return return_value;
}



//absolute value function
float absolute_value(float x)
{
    if (x < 0)
        x = -x;
        
    return x;
    
}
