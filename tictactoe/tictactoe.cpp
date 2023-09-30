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
    std::map<char, int> scores;
    scores['X'] = 10;
    scores['O'] = -10;
    scores['t'] = 0;
    char MMwinner = CheckWinner();
    if (MMwinner != ' ')
    {
        return scores[MMwinner];
    }
    if(isMaxing)
    {
        int bestScore= INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(board[i][j] == ' ')
                {
                    board[i][j] = COMPUTER;
                    int score = MiniMax(board, depth + 1, false);
                    board[i][j] = ' ';
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
void BestMove()
{
    int bestScore = INT_MIN;
    int move [] = {0, 0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = COMPUTER;
                int score = MiniMax(board, 0, false);
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