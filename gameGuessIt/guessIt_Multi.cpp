#include <bits/stdc++.h>
using namespace std;

// multi
int generateRandomNumber_multi(int min = 0 , int max = 100 );
int getPlayerGuess_multi(int playerID);
void PrintAnswer_multi(int player, int guess, int secretNumber);
int getNumberPlayer_multi();
int startGame_multi();

int main ()
{
    startGame_multi();
}
int startGame_multi()
{
    srand(time(NULL));
    int nPlayer = getNumberPlayer_multi();
    int guess[10];
    int secretNumber = generateRandomNumber_multi();
    bool isGameOver = false;
    
    
    // Game loop
    do {
        // So cua nguoi choi
        for (int player = 1; player <= nPlayer ; player++)
        {
            guess[player] = getPlayerGuess_multi(player);
        }
        // In ra man hinh so cua nhung nguoi choi
        for (int player = 1 ; player <= nPlayer; player++)
        {
                PrintAnswer_multi(player ,guess[player] ,secretNumber);
        }

        // check lua chon cua tung nguoi
        for (int player = 1; player <= nPlayer; player++)
        {
                if (guess[player] == secretNumber)
                {
                    // cout << "Congratulation! You Win <3." << endl;
                    isGameOver = true;
                    break;
                }
        }

    } while (!isGameOver);
    return 0;

}

int getNumberPlayer_multi() {
    int numberPlayer;
    cout << "Enter the number of players : " ;
    cin >> numberPlayer;
    return numberPlayer;

}

int getPlayerGuess_multi(int playerID) {
    int guess;
    cout <<"Player "<< playerID << ", Enter your Guess : " ;
    cin >> guess;
    return guess;
}
int generateRandomNumber_multi(int min, int max ) {
    return min + rand() % (max - min ) + 1;
}

void PrintAnswer_multi(int player, int guess, int secretNumber) {
    cout << "Player "<< player <<" :  ";

    if (guess > secretNumber )
    {
        cout << "Your number is too big." << endl;
    } else if (guess < secretNumber )
    {
        cout << "Your number is too small." << endl;
    } else {
        cout << "Congratulation! You Win <3." << endl;
    }
}
