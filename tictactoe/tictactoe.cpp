#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <iostream>
#include <map>
#include <string>




using namespace std;

char board[3][3];
const char PLAYER = 'O';
const char COMPUTER = 'X';
bool currentPlayerIsHuman = false;
// scores = {
//     X: 10,
//     O: -10,

// }

//Resets the board - used for if the user wants to play again.
void ResetBoard()
{
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}
//Checks how many spaces are available
int CheckFreeSpaces()
{
    int freeSpaces = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }
    return freeSpaces;
}
//Prints the board to the terminal. Formate specifier %c will be X(COMPUTER), O(PLAYER), or ' '
void PrintBoard()
{
    printf("     |     |     \n");
    printf("  %c  |  %c  | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  ", board[1][0], board[1][1], board[1][2]);
    printf("\n_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  ", board[2][0], board[2][1], board[2][2]);
    printf("\n     |     |     \n");
    printf("\n");
}
//Using the "winner" variable which will be found with the CheckWinner() function, this prints out who won.
void PrintWinner(char winner)
{
    if (winner == PLAYER)
    {
        cout << "YOU WIN!!!" << endl;//This won't ever happen
    }
    else if(winner == COMPUTER)
    {
        cout << "YOU LOSE... " << endl;
    }
    else
    {
        cout << "It's a draw... " << endl;
    }
}
//Iterates through the board to check for several win conditions. 
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
//This function returns a random computer move as long as the space is available.
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
        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
    }
    else
    {
        PrintWinner(' ');
    }
}
//Takes input from the user to choose a spot on the board.
void PlayerMove()
{
    int x;
    int y;
    do
    {
        cout << "Enter Row #1-3: " << endl;
        cin >> x;
        cout << "Enter Column #1-3: " << endl;
        cin >> y;
        x--;
        y--;
        
        if(board[x][y] != ' ')
        {
            cout << "Invalid Move" << endl;
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    }while(board[x][y] != ' ');
}
//AI to make it's move
int MiniMax(char board[3][3], int depth, bool isMaxing)
{
    //Scores are used to weigh the decision of each possibility
    std::map<char, int> scores;
    scores['X'] = 10;
    scores['O'] = -10;
    scores['t'] = 0;
    //As long as there isn't a winner, the MiniMax algorith will keep going until it finishes, then it will return the score.
    char MMwinner = CheckWinner();
    if (MMwinner != ' ')
    {
        return scores[MMwinner];
    }
    //Execute this code for the Maximizing side of the algorithm
    if(isMaxing)
    {
        int bestScore= INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(board[i][j] == ' ')//Check to see if spot is available
                {
                    board[i][j] = COMPUTER;
                    int score = MiniMax(board, depth + 1, false);//Will recursively call this function again, but will send it to the else statement 
                    board[i][j] = ' ';//Clears the spot so that the actual board game won't be affected
                    bestScore = max(score, bestScore);
                }
            }
        }
        return bestScore;
    }
    else 
    {
        int bestScore= INT_MAX;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(board[i][j] == ' ')
                {
                    board[i][j] = PLAYER;
                    int score = MiniMax(board, depth + 1, true);
                    board[i][j] = ' ';
                    bestScore = min(score, bestScore);
                }
            }
        }
        return bestScore;
    }
}
//Setting up for the AI to make it's move
void BestMove()
{
    int bestScore = INT_MIN;//setting best score to be a really small number
    int move [] = {0, 0};//The array location the computer will make after all calculations are done
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = COMPUTER;
                int score = MiniMax(board, 0, false);//Starts the MiniMax recursive call
                board[i][j] = ' ';
                if (score > bestScore)
                {
                    bestScore = score;
                    move[0] = i;
                    move[1] = j;
                }
            }
        }
    }

    board[move[0]][move[1]] = COMPUTER;
    // currentPlayerIsHuman = true;
}
int main()
{
    char winner = ' ';
    char response;

    do
    {
        winner = ' ';
        response = ' ';
        ResetBoard();

        while (winner = ' ' && CheckFreeSpaces() != 0)
        {
            PrintBoard();

            // ComputerMove();
            winner = CheckWinner();
            BestMove();
            PrintBoard();
            winner = CheckWinner();
            if (winner != ' ' || CheckFreeSpaces() == 0)
            {
                break;
            }
            PlayerMove();
            winner = CheckWinner();
            if (winner != ' ' || CheckFreeSpaces() == 0)
            {
                break;
            }
        }
        PrintBoard();
        PrintWinner(winner);

        cout << "Would you like to play again?(Y/N) " << endl;
        cin.uppercase >> response; 
    }while(response == 'Y');
    cout << "Thanks for playing!" << endl << endl;
}