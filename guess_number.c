#include <stdio.h>
#include <stdlib.h>
#include <time.h> //for random number generator seed

int main()
{
	int randomNumber = 0;
    int guess = 0;
    int numberOfGuesses;
    char playAgain;
    time_t t;
    
    //initialize random number generator
    srand((unsigned) time(&t));
    
    while(1)
    {
    
        //get random number
        randomNumber = rand() % 101; //random number is between 0 and 100
        
        printf("\nThis is a guessing game!");
        printf("\nI have chosen a number between 0 and 100 which you must guess. \n");
        
        for (numberOfGuesses = 10; numberOfGuesses > 0; --numberOfGuesses)
        {
            printf("\nYou have %d tr%s left.", numberOfGuesses, numberOfGuesses == 1 ? "y" : "ies");
            printf("\nEnter a guess: ");
            scanf("%d", &guess);
            
            if (guess == randomNumber)
            {
                printf("\nCongratulations! You guessed it!\n");
                break;
            }
            
            else if (guess < 0 || guess > 100) //checking for invalid guess
                printf("I said the number is between 0 and 100.\n");
                
            else if (randomNumber > guess)
                printf("Sorry, %d is wrong. My number is greater than that.\n", guess);
                
            else if (randomNumber < guess)
                printf("Sorry, %d is wrong. My number is less than that.\n", guess);
        }
        
        if (guess != randomNumber)
            printf("\nYou had 10 tries and failed. The number was %d\n", randomNumber);
        
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain); //space before %c to consume leftover newline
        
        if (playAgain != 'y' && playAgain != 'Y')
        {
            printf("\nThank you for playing! Goodbye!\n");
            break;
        }
    
    }
    
	return 0;
}
