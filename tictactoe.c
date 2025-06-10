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
    player = 1;
    
    do
    {
        display_board();
        player = (player % 2) ? 1 : 2; //switching players from 1 to 2 - changing turns
        
        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice);
        
        mark = (player == 1) ? 'X' : 'O'; //if player is 1 assign X otherwise is player 2 assign O
        
        //set board based on user choice or invalid choice
        mark_board(mark);
        
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
    if (choice == 1 && square[1] == '1')
        square[1] = mark;
        
    else if (choice == 2 && square[2] == '2')
        square[2] = mark;
        
    else if (choice == 3 && square[3] == '3')
        square[3] = mark;
        
    else if (choice == 4 && square[4] == '4')
        square[4] = mark;
        
    else if (choice == 5 && square[5] == '5')
        square[5] = mark;
        
    else if (choice == 6 && square[6] == '6')
        square[6] = mark;
        
    else if (choice == 7 && square[7] == '7')
        square[7] = mark;
        
    else if (choice == 8 && square[8] == '8')
        square[8] = mark;
        
    else if (choice == 9 && square[9] == '9')
        square[9] = mark;
    
    else
    {
        printf("Invalid move! ");
        player--;
        getchar();
    }
}