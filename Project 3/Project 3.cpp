#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

enum enGameLevel { Esay = 1, Hard = 2 };

struct stBoardInfo
{
    short SquareEasyBoard = 16;
    short SquareHardBoard = 25;
    short Array[50];
    bool IsVisible[50] = {false};
    short SameNumber = 0;
  
};

struct stGame
{
    stBoardInfo BoardInfo;
    enGameLevel GameLevel;
    short Around = 1;
    short ChoicePlayer = 0;
    short HowAnswerIsCorrect = 0;
    short HowAnswerIsFail = 0;
    bool Color = false;


};

void FillEasyBoardGame(stGame Game)
{
   
    
    cout << "=========================================================\n";
    cout << "                START PLAYING NOW                   \n";
    cout << "You have [" << Game.BoardInfo.SameNumber << "] same number,What's it ??,Tries number[";
    cout << Game.Around << "/" << Game.BoardInfo.SameNumber << "]\n";
    cout << "=========================================================\n";


    short count = 0 ;


    for (int i = 0; i < 4; i++)
    {

        for (int j = 0; j < 4; j++)
        {
            cout << "+-------";
        }
        cout << "+" << endl;


        for (int j = 0; j < 4; j++)
        {
            
         
            if (Game.BoardInfo.IsVisible[count]==true)
            {
                cout << "| " << left << setw(6) << Game.BoardInfo.Array[count] ;

            }
            else
            {
                cout << "|       ";
            }
            count++;
        }
        cout << "|" << endl;
    }


    for (int j = 0; j < 4; j++)
    {
        cout << "+-------";
    }
    cout << "+" << endl;
    
    cout << "=========================================================\n";

}

void FilledEasyBoardGameByNumbers(short ArrEasyBoardGame[50])
{
   int count = 0;

    for (int i = 0; i < 4; i++)
    {
        
        for (int j = 0; j < 4; j++)
        {
            cout << "+-------";
        }
        cout << "+" << endl;

       
        for (int j = 0; j < 4; j++)
        {
            cout << "| "<<left << setw(6) << ArrEasyBoardGame[count];
            count++;
        }
        cout << "|" << endl;
    }

   
    for (int j = 0; j < 4; j++)
    {
        cout << "+-------";
    }
    cout << "+" << endl;
}

void FillHardBoardGame(stGame Game)
{
    

    cout << "=========================================================\n";
    cout << "                START PLAYING NOW                   \n";
    cout << "You have [" << Game.BoardInfo.SameNumber << "] same number,What's it ?,Tries number[";
    cout << Game.Around << "/" << Game.BoardInfo.SameNumber << "]\n";
    cout << "=========================================================\n";


    short count = 0;


    for (int i = 0; i < 5; i++)
    {

        for (int j = 0; j < 5; j++)
        {
            cout << "+-------";
        }
        cout << "+" << endl;


        for (int j = 0; j < 5; j++)
        {


            if (Game.BoardInfo.IsVisible[count] == true)
            {
                cout << "| " << left << setw(6) << Game.BoardInfo.Array[count];

            }
            else
            {
                cout << "|       ";
            }
            count++;
        }
        cout << "|" << endl;
    }


    for (int j = 0; j < 5; j++)
    {
        cout << "+-------";
    }
    cout << "+" << endl;

    cout << "=========================================================\n";


}

void FilledHardBoardGameByNumbers(short ArrHardBoardGame[50])
{
    int count = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "+-------";
        }
        cout << "+" << endl;

        for (int j = 0; j < 5; j++)
        {
            cout << "| " << left << setw(6) << ArrHardBoardGame[count];
            count++;

        }
        cout << "|" << endl;

    }
    for (int i = 0; i < 5; i++)
    {
        cout << "+-------";
    }
    cout << "+" << endl;

}

void EndTheGame()
{
  
    cout << "===========================================" << endl;
    cout << "  ____             ____                    " << endl;
    cout << " | __ ) _   _  ___| __ ) _   _  ___        " << endl;
    cout << " |  _ \\| | | |/ _ \\  _ \\| | | |/ _ \\   " << endl;
    cout << " | |_) | |_| |  __/ |_) | |_| |  __/       " << endl;
    cout << " |____/ \\__, |\\___|____/ \\__, |\\___|   " << endl;
    cout << "        |___/            |___/             " << endl;
    cout << "===========================================" << endl;

}

int RandomNumber(int From, int To)
{
    //Function generater a random number

    int RandomNum = rand() % (To - From + 1) + From;

    return RandomNum;
}

void SetScreenColor(bool Color)
{
    if (Color==true)
    {
        system("color 2F");

    }
    else
    {
        system("color 4F");
        cout << "\a";
    }
   
}

short ReadUserStart()
{
    short Start = 0;

    do
    {
        cout << "Enter start if want playing game ??\n";
        cout << " [1]Start  \n";
        cin >> Start;

    } while (Start < 1 || Start > 1);

    return Start;
}

enGameLevel ReadGameLevel()
{
    short Level = 0;

    do
    {
        cout << "Enter Which Level do you want ??\n";
        cout << "  [1]Esay   [2]Hard ??";
        cin >> Level;
    } while (Level < 1 || Level > 3);

    return (enGameLevel)Level;
}

short HowNumberRepeetInBoard(short NewNumber,short NumberOfSquare, short ArrBoard[50])
{
    short Count = 0;

    for (int i = 0; i < NumberOfSquare; i++)
    {
        if (NewNumber == ArrBoard[i])
        {
            Count++;
        }

    }
    return Count;
}

void FillArray(short NumberOfSquare ,short ArrBoard[50])
{
   
   
    for (short Square = 0; Square < NumberOfSquare; Square++)
    {
        short NewNumber = 0;

        do
        {
            NewNumber = RandomNumber(1, 20);

        } while (HowNumberRepeetInBoard(NewNumber, Square, ArrBoard)>=2);

        ArrBoard[Square] = NewNumber;

        
    }


}

void HowManyTheSameNumberInBoard(short& SameNumber, short NumberOfSquare, short ArrBoard[50])
{
    short counter = 0;

    for (int Square = 0; Square < NumberOfSquare - 1; Square++)
    {

        for (int j = Square; j < NumberOfSquare; j++)
        {
            if (ArrBoard[counter] == ArrBoard[j + 1])
            {
                SameNumber++;
                
            
            }
        }
        counter++;
    }

}

void PrintBoardAndNumbers(stGame &Game)
{
   
    switch (Game.GameLevel)
    {
    case enGameLevel::Esay:
        FillArray(Game.BoardInfo.SquareEasyBoard,Game.BoardInfo.Array);
        HowManyTheSameNumberInBoard(Game.BoardInfo.SameNumber, Game.BoardInfo.SquareEasyBoard, Game.BoardInfo.Array);
        FilledEasyBoardGameByNumbers(Game.BoardInfo.Array);
        break;
    case enGameLevel::Hard:
        FillArray(Game.BoardInfo.SquareHardBoard, Game.BoardInfo.Array);
        HowManyTheSameNumberInBoard(Game.BoardInfo.SameNumber, Game.BoardInfo.SquareHardBoard, Game.BoardInfo.Array);
        FilledHardBoardGameByNumbers(Game.BoardInfo.Array);
        break;
    }
    

}

short ReadNumberOfPlayer(short &ChoicePlayer)
{
    ChoicePlayer = 0;

    cout << "Enter the same number in Board ?? \n";
    cin >> ChoicePlayer;

    return ChoicePlayer;
}

void CheckAnswerThePlayer(stGame &Game)
{
    int Counter = 0;

    if (Game.GameLevel == enGameLevel::Esay)
    {
        Counter = Game.BoardInfo.SquareEasyBoard;
    }
    else
    {
        Counter = Game.BoardInfo.SquareHardBoard;
    }


    if (HowNumberRepeetInBoard(Game.ChoicePlayer, Counter, Game.BoardInfo.Array) >= 2)
    {
        Game.HowAnswerIsCorrect++;
        Game.Color = true;


        for (int i = 0; i < Counter; i++)
        {
            if (Game.ChoicePlayer == Game.BoardInfo.Array[i])
            {
                Game.BoardInfo.IsVisible[i] = true;

            }

        }
    }
    else
    {
        Game.HowAnswerIsFail++;
        Game.Color = false;
    }


    SetScreenColor(Game.Color);

}

void Clean()
{
    system("cls");
    system("color 0F");
}

string PrintPhrase(stGame &Game)
{
    if (Game.HowAnswerIsCorrect > Game.HowAnswerIsFail)
    {
        Game.Color = true;
        return "Good Job :-)\n";

    }
    else if(Game.HowAnswerIsCorrect < Game.HowAnswerIsFail)
    {
        Game.Color = false;
       return "You Failed :-(\n";

    }
    else if(Game.HowAnswerIsCorrect == Game.HowAnswerIsFail)
    {
        Game.Color = true;
        return "Nice trying :-)\n";
    }
 
}

void PrintFinalResult(stGame &Game)
{

    cout << "+==================================+\n";
    cout << "|        ++++GAME OVER++++         |\n";
    cout << "+==================================+\n";
    cout << " Times Won :" << Game.HowAnswerIsCorrect << endl;
    cout << " Times Lost :" << Game.HowAnswerIsFail << endl << endl;
    cout << "\t" << PrintPhrase(Game) << endl << endl;
    cout << "+==================================+\n";

    SetScreenColor(Game.Color);

}

void StartPlaying()
{

    stGame Game;

    Game.GameLevel = ReadGameLevel();

    ReadUserStart();

    PrintBoardAndNumbers(Game);

    Sleep(10000);

    for (int Playing = 0; Playing < Game.BoardInfo.SameNumber; Playing++)
    {

        Clean();

        if (Game.GameLevel == enGameLevel::Esay)
        {
            FillEasyBoardGame(Game);
        }
        else
        {
            FillHardBoardGame(Game);
        }

        ReadNumberOfPlayer(Game.ChoicePlayer);

        CheckAnswerThePlayer(Game);

        Game.Around++;

        Sleep(3000);

    }

    Clean();

    PrintPhrase(Game);

    PrintFinalResult(Game);


}

void StartGame()
{
    char  PlayAgain = 'Y';

    do
    {
        Clean();
        StartPlaying();

        cout << endl << "Do you want to play again \n";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();
    Clean();
    EndTheGame();

    return 0;
}