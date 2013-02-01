/***************************************
* Programmer: Heather McMillen         *
* Date of last revision: 1/31/2013     *
* Program: Chutes & Ladders - c++      *
***************************************/

#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <iomanip>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

class Player
{
public:
    void SetName();
    string GetName();
    void SpinAndMove(Player&, Player&, int(&Board) [10][10]);
    int GetPosition();
    int SetPosition(int);
    Player();
    void DisplayNewMove(int (&Board) [10][10], Player);
    char GetPiece();
    char SetPiece(int);
private:
    int position;
    string name;
    char playingpiece;
};

Player::Player()
{
    position = 0;
    name = "";
}

void Welcomemsg();
void Goodbye();
void PrintBoard(int (&Board)[10][10]);
int CheckLadders(int &);
int CheckChutes(int &);

char smily = 01;
char smily2 = 02;
char heart = 03;
char dimond = 04;

int main()
{
    SetConsoleTextAttribute(console, 11);
    Welcomemsg();
    cout << endl << endl;
    srand(time(NULL));
    SetConsoleTextAttribute(console, 13);
    int PlayingPiece=0;
    string PlayerName;

    // For testing purposes chose 2 players

    Player Player1;
    Player1.SetName();
    cout << Player1.GetName() << " please choose a playing piece." << endl;
    cout << "1. " << smily << endl;
    cout << "2. " << smily2 << endl;
    cout << "3. " << heart << endl;
    cout << "4. " << dimond << endl;
    cin >> PlayingPiece;
    cout << Player1.SetPiece(PlayingPiece) << endl;
    Player Player2;
    Player2.SetName();
    cout << Player2.GetName() << " please choose a playing piece." << endl;
    cout << "1. " << smily << endl;
    cout << "2. " << smily2 << endl;
    cout << "3. " << heart << endl;
    cout << "4. " << dimond << endl;
    cin >> PlayingPiece;
    cout << Player2.SetPiece(PlayingPiece) << endl;
    system("cls");

    int Board[10][10] = {0};

    PrintBoard(Board);

    while ( Player1.GetPosition() < 100 && Player2.GetPosition() < 100)
    {
        Player1.SpinAndMove(Player1, Player2, Board);
    }

    if ( Player1.GetPosition() >= 100)
    {
        SetConsoleTextAttribute(console, 12);
        cout << "Congradulations! " << Player1.GetName() << " ! You won!" << endl;
    }
    else if ( Player2.GetPosition() >= 100)
    {
        SetConsoleTextAttribute(console, 9);
        cout << "Congradulations! " << Player2.GetName() << " ! You won!" << endl;
    }
    cout << endl << endl;
    Goodbye();


    return 0;
}

void Welcomemsg()
{
    cout << "     Welcome to Chutes And Ladders!" << endl;
    cout << "Players start at 0. The first one to 100 wins." << endl;
    cout << "If a player lands on a ladder, they move up, however if a" << endl;
    cout << "player lands on a chute, they move down." << endl;
    cout << endl << endl;
}

void Goodbye()
{
    cout << "Thanks for playing Chutes And Ladders!" << endl;
}

char Player::GetPiece()
{
    return playingpiece;
}

char Player::SetPiece(int PlayingPiece)
{
    playingpiece = PlayingPiece;
    return playingpiece;
}
void Player::SetName()
{
    string PlayerName ="";
    cout << "What is your name?";
    cin >> PlayerName;
    name = PlayerName;
}

string Player::GetName()
{
    return name;
}

int Player::GetPosition()
{
    return position;
}

int Player::SetPosition(int newpos)
{
    position = newpos;
    return position;
}

int CheckChutes(int &newpos)
{
    switch(newpos)
    {
    case 98:
        newpos = 78;
        cout << "You landed on a chute, the new position is " << newpos << endl;
        break;
    case 95:
        newpos = 76;
        cout << "You landed on a chute, the new position is " << newpos << endl;
        break;
    case 93:
        newpos = 73;
        cout << "You landed on a chute, the new position is " << newpos << endl;
        break;
    case 87:
        newpos = 24;
        cout << "You landed on a chute, the new position is " << newpos << endl;
        break;
    case 56:
        newpos = 53;
        cout << "You landed on a chute, the new position is " << newpos << endl;
        break;
    case 64:
        newpos = 60;
        cout << "You landed on a chute, the new position is " << newpos << endl;
        break;
    case 62:
        newpos = 19;
        cout << "You landed on a chute, the new position is " << newpos << endl;
        break;
    case 47:
        newpos = 26;
        cout << "You landed on a chute, the new position is " << newpos << endl;
        break;
    case 49:
        newpos = 11;
        cout << "You landed on a chute, the new position is " << newpos << endl;
        break;
    case 16:
        newpos = 6;
        cout << "You landed on a chute, the new position is " << newpos << endl;
        break;
    default:
        break;
    }
    return newpos;
}

int CheckLadders(int &newpos)
{
    switch (newpos)
    {
    case 1:
        newpos = 38;
        cout << "You landed on a ladder, the new position is " << newpos << endl;
        break;
    case 4:
        newpos = 14;
        cout << "You landed on a ladder, the new position is " << newpos << endl;
        break;
    case 9:
        newpos = 31;
        cout << "You landed on a ladder, the new position is " << newpos << endl;
        break;
    case 21:
        newpos = 42;
        cout << "You landed on a ladder, the new position is " << newpos << endl;
        break;
    case 36:
        newpos = 44;
        cout << "You landed on a ladder, the new position is " << newpos << endl;
        break;
    case 51:
        newpos = 67;
        cout << "You landed on a ladder, the new position is " << newpos << endl;
        break;
    case 71:
        newpos = 91;
        cout << "You landed on a ladder, the new position is " << newpos << endl;
        break;
    case 80:
        newpos = 100;
        cout << "You landed on a ladder, the new position is " << newpos << endl;
        break;
    default:
        break;

    }
    return newpos;
}

void Player::SpinAndMove(Player& Player1, Player& Player2, int (&Board) [10][10])
{

    int spinner = 0, newpos = 0;
    cout << endl;
    SetConsoleTextAttribute(console, 12);
    cout << Player1.GetName();
    cout << " you spun a ";
    spinner = 1 + (rand() % 6);
    cout << spinner << endl;
    cout << Player1.GetName();
    cout << " new position after spin: ";
    newpos = Player1.GetPosition() + spinner;
    Player1.SetPosition(newpos);
    cout << Player1.GetPosition() << endl;

    CheckChutes(newpos);
    Player1.SetPosition(newpos);

    CheckLadders(newpos);
    Player1.SetPosition(newpos);
    Player1.DisplayNewMove(Board, Player1);
    cout << "Please press enter to continue...";
    cin.get();
    system("cls");

    SetConsoleTextAttribute(console, 9);
    cout << endl;
    cout << Player2.GetName();
    cout << " you spun a ";
    spinner = 1 + (rand() % 6);
    cout << spinner << endl;
    cout << Player2.GetName();
    cout << " new position after spin: ";
    newpos = Player2.GetPosition() + spinner;
    Player2.SetPosition(newpos);
    cout << Player2.GetPosition() << endl;

    CheckChutes(newpos);
    Player2.SetPosition(newpos);
    CheckLadders(newpos);
    Player2.SetPosition(newpos);

    Player2.DisplayNewMove(Board, Player2);
    cout << "Please press enter to continue...";
    cin.get();
    system("cls");
}

void Player::DisplayNewMove(int (&Board) [10][10], Player Player1)
{
    // search through array and find Player's position..
    for ( int i=0; i < 10; i++)
    {
        for (int j=0; j <10; j++)
        {
            cout << setw(4) << Board[i][j] << " ";

            if ( Player1.GetPosition() == Board[i][j])
            {
                cout  << Player1.GetPiece();
            }
        }
        cout << endl;
        cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
        cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
        cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
        cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    }
}

void PrintBoard(int (&Board)[10][10])
{
    SetConsoleTextAttribute(console, 10);
    int i=0, counter =100;
    for (int j=0; j < 10; j++)
    {
        Board[i][j] = counter;
        counter--;
        cout << setw(4.5) << Board[i][j] << " ";
    }
    cout << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    i = 1;
    counter = counter -9;

    for ( int k=0; k < 10; k++)
    {
        Board[i][k] = counter;
        counter++;
        cout << setw(4) << Board[i][k] << " ";
    }
    cout << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    i = 2;
    counter = counter - 11;

    for ( int k=0; k < 10; k++)
    {
        Board[i][k] = counter;
        counter--;
        cout << setw(4) << Board[i][k] << " ";
    }
    cout << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    i = 3;
    counter = counter - 9;

    for ( int k=0; k < 10; k++)
    {
        Board[i][k] = counter;
        counter++;
        cout << setw(4) << Board[i][k] << " ";
    }
    cout << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    i = 4;
    counter = counter - 11;

    for ( int k=0; k < 10; k++)
    {
        Board[i][k] = counter;
        counter--;
        cout << setw(4) << Board[i][k] << " ";
    }
    cout << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    i = 5;
    counter = counter - 9;

    for ( int k=0; k < 10; k++)
    {
        Board[i][k] = counter;
        counter++;
        cout << setw(4) << Board[i][k] << " ";
    }
    cout << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    i = 6;
    counter = counter -11;

    for ( int k=0; k < 10; k++)
    {
        Board[i][k] = counter;
        counter--;
        cout << setw(4) << Board[i][k] << " ";
    }
    cout << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    i = 7;
    counter = counter - 9;

    for ( int k=0; k < 10; k++)
    {
        Board[i][k] = counter;
        counter++;
        cout << setw(4) << Board[i][k] << " ";
    }
    cout << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    i = 8;
    counter = counter - 11;

    for ( int k=0; k < 10; k++)
    {
        Board[i][k] = counter;
        counter--;
        cout << setw(4) << Board[i][k] << " ";
    }
    cout << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    i = 9;
    counter = counter - 9;

    for ( int k=0; k < 10; k++)
    {
        Board[i][k] = counter;
        counter++;
        cout << setw(4) << Board[i][k] << " ";
    }
    cout << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "|   |" << "|   |"<<  "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << "|   |" << endl;
    cout << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << "-----" << endl;

    cout << "Please press enter to continue...";
    cin.get();
    cin.get();
    system("cls");
}
