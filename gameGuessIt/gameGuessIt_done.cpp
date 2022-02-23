#include <bits/stdc++.h>
using namespace std;

//single
int getRandomNumber_single();
int getPlayerNumner_single();
void printAnswer_single(int guess, int secretNumber,int point);
int numberOfGuessLeft_single();
void startGame_single();

// multi
int generateRandomNumber_multi(int min = 0 , int max = 100 );
int getPlayerGuess_multi(int playerID);
void PrintAnswer_multi(int player, int guess, int secretNumber);
int getNumberPlayer_multi();
int startGame_multi();

// select of player  
int selectOfPlayer();

int main () {
    selectOfPlayer();
}

int selectOfPlayer(){
    cout << "Single or Multi ? " <<endl;
    bool flagTest = false;
    do {
    	cout <<"Enter your answer (S or M ) : ";
    	char answerOfPlayer;
    	cin >> answerOfPlayer;
    	
        if(answerOfPlayer == 's' || answerOfPlayer == 'S')
    	{
        	startGame_single();
        	flagTest = true;
    	} 
    	else if (answerOfPlayer == 'm' || answerOfPlayer == 'M')
    	{
        	startGame_multi();
        	flagTest = true;
    	} else {
        	cout << "Please re-enter ! " << endl;
    	}
    } while (!flagTest);

}

// CODE SINGLE PLAYER
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
	
    while (true)
    {
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
    cout<<"GOOD BYE !" << endl;
    break;
	}
}

// CODE MULTI-PLAYER
int startGame_multi()
{ 	
	bool flagMulti = false; 
	
    while (true)
	{
		do {
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
    	
    	char selectOfPlayerMulti;
        cout << "DO YOU WANT TO PLAY AGAIN? (y/N) : ";
        cin >> selectOfPlayerMulti;
        if ( selectOfPlayerMulti == 'N'|| selectOfPlayerMulti == 'n')
        {
        	flagMulti = true;
            break;
        }
	} while (!flagMulti);
   	 	cout << "GOOD BYE !" <<endl;
   		break;
	}
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
