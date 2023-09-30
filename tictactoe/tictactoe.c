//
//  main.c
//  Final_Task
//
//  Created by Mahonri Ray on 7/14/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';


void ResetBoard(void);
void PrintBoard(void);
int CheckFreeSpaces(void);
void PlayerMove(void);
void ComputerMove(void);
char CheckWinner(void);
void PrintWinner(char);


int main(int argc, const char * argv[]) {
    // insert code here...
    char winner = ' ';
    char response;
    
    do
    {
        winner = ' ';
        response = ' ';
        ResetBoard();
        
        while(winner == ' ' && CheckFreeSpaces() != 0)
        {
            PrintBoard();
            
            PlayerMove();
            winner = CheckWinner();
            if(winner != ' ' || CheckFreeSpaces() == 0)
            {
                break;
            }
            
            ComputerMove();
            winner = CheckWinner();
            if(winner != ' ' || CheckFreeSpaces() == 0)
            {
                break;
            }
        }
        PrintBoard();
        PrintWinner(winner);
        
        printf("\nWould you like to play again?(Y/N) ");
        scanf("%c", &response);
        scanf("%c", &response);
        response = toupper(response);
    }while(response == 'Y');
    
    printf("Thanks for playing!\n\n");
//    printf("Hello, World!\n");
    return 0;
}
void ResetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j=0; j<3; j++)
        {
            board [i][j] = ' ';
        }
    }
}
void PrintBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
int CheckFreeSpaces()
{
    int freeSpaces = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}
void PlayerMove()
{
    int x;
    int y;
    do
    {
        printf("Enter Row #1-3: ");
        scanf("%d", &x);
        printf("Enter Column #1-3 ");
        scanf("%d", &y);
        x--;
        y--;
        
        if(board[x][y] != ' ')
        {
            printf("Invalid Move\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    }while(board[x][y] != ' ');
}
void ComputerMove()
{
    srand(time(0));
    int x;
    int y;
    
    if(CheckFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board [x][y] != ' ');
        
        board[x][y] = COMPUTER;
    }
    else
    {
        PrintWinner(' ');
    }
}
char CheckWinner()
{
    //Check rows for three in a row
    for(int i = 0; i < 3; i++)
    {
        if(board [i][0] == board [i][1] && board [i][0] == board [i][2])
        {
            return board[i][0];
        }
    }
    //Check columns for three in a row
    for(int i = 0; i < 3; i++)
    {
        if(board [0][i] == board [1][i] && board [0][i] == board [2][i])
        {
            return board[0][i];
        }
    }
    //Check diagonals for three in a row
    if(board [0][0] == board [1][1] && board [0][0] == board [2][2])
    {
        return board[0][0];
    }
    if(board [0][2] == board [1][1] && board [0][2] == board [2][0])
    {
        return board[0][2];
    }
    return ' ';
}
void PrintWinner(char winner)
{
    if(winner == PLAYER)
    {
        printf("YOU WIN!!\n");
    }
    else if(winner == COMPUTER)
    {
        printf("YOU LOSE...\n");
    }
    else
    {
        printf("It's a draw.\n");
    }
}
