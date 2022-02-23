#include <bits/stdc++.h>
using namespace std;

//single
int getRandomNumber_single();
int getPlayerNumner_single();
void printAnswer_single(int guess, int secretNumber,int point);
int numberOfGuessLeft_single();
void startGame_single();

int main () {
    startGame_single();
}

int getRandomNumber_single() {
	srand(time(NULL));
    return rand() % (100) +1; // min + rand() % (max-min ) + 1
}

int getPlayerNumner_single(){
    int guess;
    cout << "Enter your guess: ";
    cin >> guess ;
    return guess;
}

int numberOfGuessLeft_single(){
	int guessLeft = 7;
	return guessLeft;
}

void printAnswer_single(int guess, int secretNumber, int point) {
    if (guess > secretNumber )
    {
        cout << "Your number is too big." << endl;
    } else if (guess < secretNumber )
    {
        cout << "Your number is too small." << endl;
    } else {
        cout << "Congratulation! You Win <3." << endl;
        cout << "Your Score : " << 100 - point  <<endl;
    }
}


void startGame_single(){
	bool flag = false;
    do {
    	
        int secretNumber = getRandomNumber_single();
        int guess, point = 0;
		int guessLeft = numberOfGuessLeft_single();
		bool flagOfguessLeft = false;
		
        do {
            guess = getPlayerNumner_single();
            point++;
            guessLeft--;
            printAnswer_single(guess, secretNumber,point);
            
            if (guessLeft == 0 && guess != secretNumber)
            {
            	cout << "The game is over , You are Lose !" <<endl;
            	cout << "Number of Random is : " << secretNumber <<endl;
            	flagOfguessLeft = true;
            	break;
			} 
            
            else if (guessLeft != 0 && guess != secretNumber) {
                cout << "Number of Guess Left is : " << guessLeft << endl ;
            }
            
        } while ( guess != secretNumber );

        char selectOfPlayer;
        cout << "DO YOU WANT TO PLAY AGAIN? (y/N) : ";
        cin >> selectOfPlayer;
        if ( selectOfPlayer == 'N'|| selectOfPlayer == 'n')
        {
        	flag = true;
            break;
        } 
    } while (!flag);
    cout<<"GOOD BYE !";
}

