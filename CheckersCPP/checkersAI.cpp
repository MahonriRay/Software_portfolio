#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

using namespace std;
void delay(int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}
class Piece
{
    private:
        int i;
        int j;
        int X;
        int Y;
        int direction;
        int Player;
        int Opponent;
        int temp;
        int rate;

    public:
        bool isKing(int X, int Y, char Player, char Board[8][8])
        {
            if(X==0){
                return true;
            }
            else if(X==7){
                return true;
            }
            return false;
        }
        Piece(){
            temp = 0;
            rate = 0;
        }
        void Display(char Board[8][8])
        {
            system("cls");
            for(int i=0; i<8; i++)
            {
                cout << " +---+---+---+---+---+---+---+---+" << endl;
                cout << i + 1 << " | " << Board[i][0] << " | " << Board[i][1] << " | " << Board[i][2] << " | " << Board[i][3] << " | " << Board[i][4] << " | " << Board[i][5] << " | " << Board[i][6] << " | " << Board[i][7] << " |" << endl;
            }
        cout << "  +---+---+---+---+---+---+---+---+" << endl;
        cout << "    A   B   C   D   E   F   G   H  " << endl;
        }
        void gotoxy(int m, int n)
        {
            COORD c;
            c.X = m;
            c.Y = n;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
        }

};
int main()
{
Intro:
    system("cls");
    Piece game;

    char Board[8][8], A = 'X', B = 'O', position[2];
    for(int i = 0; i < 8; i++)
    {
        for(int j =0; j<8; j++)
            Board[i][j] = ' ';
    }
    cout << "   CHECKERS: THE GAME    " << endl;
    cout << "--------------------------" << endl << endl;
    cout << "Move pieces diagonally to advance, capture other pieces, and promote your pieces to Kings" << endl;
    cout << "Your pieces are X and the computer pieces are O    " << endl;
    delay(5000);
    A = 'X', B = 'O';
    char tICK = A;
    char Tick = B;

    Board[0][0] = 'O', Board[0][2] = 'O', Board[0][4] = 'O', Board[0][6] = 'O', Board[1][1] = 'O', Board[1][3] = 'O', Board[1][5] = 'O', Board[1][7] = 'O', Board[2][0] = 'O', Board[2][2] = 'O', Board[2][4] = 'O', Board[2][6] = 'O';
    Board[5][1] = 'X', Board[5][3] = 'X', Board[5][5] = 'X', Board[5][7] = 'X', Board[6][0] = 'X', Board[6][2] = 'X', Board[6][4] = 'X', Board[6][6] = 'X', Board[7][1] = 'X', Board[7][3] = 'X', Board[7][5] = 'X', Board[7][7] = 'X';
    // return 0;
Start:
    game.Display(Board);
    delay(5000);
}
