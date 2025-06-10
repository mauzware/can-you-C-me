#include <stdio.h>
#include <stdlib.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int choice, player;

int checking_for_win();
void display_board();
void mark_board(char mark);

int main()
{
	int game_status; //return value for checking for win
    char mark;
    char replay;
    
    while(1)
    {
        //reset board to initial values
        for (int i = 1; i <= 9; i++)
        {
            square[i] = i + '0';
        }
        
        player = 1;
        display_board();
    
        do
        {
            player = (player % 2) ? 1 : 2; //switching players from 1 to 2 - changing turns
            
            printf("Player %d, enter a number: ", player);
            
            mark = (player == 1) ? 'X' : 'O'; //if player is 1 assign X otherwise is player 2 assign O
            
            //set board based on user choice or invalid choice
            mark_board(mark);
            display_board();
            
            game_status = checking_for_win();
            
            player++;
            
        }while (game_status == -1);
        
        if (game_status == 1)
        {
            printf("==>\aPlayer %d won!\n", --player);
        }
       
        else
        {
            printf("==>\aGame draw!");
        }
        
        //ask if player wants to replay
        printf("Do you want to play again? (y/n): ");
        getchar(); //consume new line
        scanf("%c", &replay);
        
        if (replay != 'y' && replay != 'Y')
        {
            printf("Thanks for playing! Bye!\n");
            break;
        }
    }
    
	return 0;
}

/*
Function to return game status
1 for game is over with result
-1 for game is in progress
0 game is over and no result (tie)
*/
int checking_for_win()
{
    int return_value = 0;
    
    if (square[1] == square[2] && square[2] == square[3])
        return_value = 1;
    
    else if (square[4] == square[5] && square[5] == square[6])
        return_value = 1;
    
    else if (square[7] == square[8] && square[8] == square[9])
        return_value = 1;
    
    else if (square[1] == square[4] && square[4] == square[7])
        return_value = 1;
        
    else if (square[2] == square[5] && square[5] == square[8])
        return_value = 1;
        
    else if (square[3] == square[6] && square[6] == square[9])
        return_value = 1;
        
    else if (square[1] == square[5] && square[5] == square[9])
        return_value = 1;
        
    else if (square[3] == square[5] && square[5] == square[7])
        return_value = 1;
    
    //checking if the numbers are the same as initialized
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' 
        && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        
        return_value = 0;
        
    else
        return_value = -1;
        
    return return_value;
}

//function that displays the board
void display_board()
{
    printf("\n\n\tTic Tac Toe - Created by mauzware\n\n");
    
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    
    //using 4 spaces
    printf("    |    |    \n");
    printf("  %c |  %c |  %c  \n", square[1], square[2], square[3]);
    
    printf("____|____|____\n");
    printf("    |    |    \n");
    
    printf("  %c |  %c |  %c  \n", square[4], square[5], square[6]);
    
    printf("____|____|____\n");
    printf("    |    |    \n");
    
    printf("  %c |  %c |  %c  \n", square[7], square[8], square[9]);
    
    printf("    |    |    \n\n");
}

/*
set the board with the correct character, 
x or o in the correct spot in the array
*/
void mark_board(char mark)
{
    while (1)
    {
        //input can only be number not character/letter
        if ( scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number between 1 and 9: ");
            while (getchar() != '\n'); //clear buffer
            continue;
        }
        
        //check if choice is within valid range
        
        if (choice < 1 || choice > 9)
        {
            printf("Invalid range! Try again: ");
            continue;
        }
        
        //check if the square is not already taken
        if (square[choice] != 'X' && square[choice] != 'O')
        {
            printf("Square already taken! Choose another: ");
        }
        
        square[choice] = mark;
        break;
    }
}