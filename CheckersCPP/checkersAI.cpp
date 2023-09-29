#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
//yayuhhhhh

using namespace std;
void delay(int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}
//Class for the pieces - will include variable to know where it's at on the board as well as check King status and display the game
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
        void cantMove()
        {
            cout << "Piece Can't Move. Try Again";
            delay(600);
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
    int i, j, X, Y, direction, Player, Opponent, temp, rate;

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
start:
    game.Display(Board);
    cout << "It's (" << A << ") Turn..";
    delay(1000);
    cout << endl
        << "Enter Piece Position: (A1, G6, B4, etc..) ";
    scanf("%s", position); //position will be the piece that the player wants to move
    cout << endl;
    //if statements to check if board horizontal location exists
    if (position[0] == 'z' && position[1] == 'z')
        goto end;
    if (position[0] == 'A')
        X = 0;
    else if (position [0] == 'B')
        X = 1;
    else if (position [0] == 'C')
        X = 2;
    else if (position [0] == 'D')
        X = 3;
    else if (position [0] == 'E')
        X = 4;      
    else if (position [0] == 'F')
        X = 5;
    else if (position [0] == 'G')
        X = 6;
    else if (position [0] == 'H')
        X = 1;
    else{
        cout << "Enter Piece Position Again Please";
        delay(600);
        goto start;
    }   
    //if statements to check if board vertical location exists 
    if (position[1] == '1')
        Y = 0;
    else if (position [1] == '2')
        Y = 1;  
    else if (position [1] == '3')
        Y = 2;  
    else if (position [1] == '4')
        Y = 3;  
    else if (position [1] == '5')
        Y = 4;  
    else if (position [1] == '6')
        Y = 5;  
    else if (position [1] == '7')
        Y = 6; 
    else if (position [1] == '8')
        Y = 7;   
    else{
        cout << "Enter Piece Position Again Please";
        delay(600);
        goto start;
    }   
    //check and see if the location matches A's location
    if (Board[Y][X] != A){
        cout << "Enter Piece Position Again Please";
        goto start;
    }
    if (game.isKing(X, Y, A, Board) == true){
        cout << "Which direction do you want to move your piece? " << endl;
        cout << "1 (Upper-Left), 2 (Upper-Righhht) " << endl;
        cout << "3 (Lower-Left), 4 (Lower-Right) " << endl;
        cin >> direction;
        A = tICK;
        B = Tick;
        if(direction == 1)
        {
            //checks to see if piece is in top left of the board
            if (X == 0 || Y == 0){
                game.cantMove();
                goto start;
            }
            if (Board[Y - 1][X - 1] == A)//checks to see if the piece adjacent is belongs to the same player
            {
                game.cantMove();
                goto start;
            }
            if (Board[Y - 1][X - 1] == ' ')
            {
                Board[Y][X] = ' ';//clears the position the piece was just at
                Board[--Y][--X] = A;
                goto done1;
            }
        }
    }
    else
    {
        cout << "Which direction do you want to move your piece? " << endl;
        cout << "1 (Upper-Left), 2 (Upper-Right)" << endl;
        cin >> direction;
        if (direction == 1)
        {
            if (X==0 || Y==0)
            {
                game.cantMove();
                goto start;
            }
            if (Board[Y-1][X-1] == A)
            {
                game.cantMove();
                goto start;
            }
            if (Board[Y-1][X-1] == ' ')
            {
                Board[Y][X] = ' ';
                Board[--Y][--X] = A;
                goto done1;
            }
        }
    }
done1:
    game.Display(Board);
    delay(600);
    Player = 0;
    Opponent = 0;
    A = tICK;
    B = Tick;
    for (i = 0; i<8; i++)
    {
        for (j = 0; j<8; j++)
        {
            if(Board[i][j] == A)
                Player++;
        }
    }
    for (i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            if(Board[i][j] == B)
                Opponent++;
    }
    if (Player == 0 || Opponent == 0)
        goto end;
    cout << endl
         << "Opponent's (" << B << ") Turn..";
end:
    system("cls");
    if (Player > Opponent)
    {
        delay(2000);
        game.gotoxy(30, 10);
        cout << "You Win!";
    }
    if (Player < Opponent)
    {
        delay(2000);
        game.gotoxy(30, 10);
        cout << "You Lose..):";
    }
    if (Player == Opponent)
    {
        delay(2000);
        game.gotoxy(30, 10);
        cout << "It's a Draw!";
    }
    system("pause");
}
