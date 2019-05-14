#include <iostream>
#include <string>
#include <ctime>


using namespace std;
srand(time(NULL));

void PrintIntroduction(int difficulty, string PlayerName) {
	cout << "You are a secret agent " << PlayerName << " breaking into a level " << difficulty;
	cout << " secure server room level. \nEnter the correct code to continue... \n\n";
}

bool PlayGameAtDifficulty(int difficulty, string PlayerName) {
	
	PrintIntroduction(difficulty, PlayerName);

	int FirstNumber = rand() % (difficulty + difficulty);
	int SecondNumber = rand() % (difficulty + difficulty);
	int ThirdNumber = rand() % (difficulty + difficulty);

	int CodeSum = FirstNumber + SecondNumber + ThirdNumber;
	int CodeProduct = FirstNumber * SecondNumber * ThirdNumber;

	cout << "There are 3 numbers in the code \n";
	cout << "The code add-up to: " << CodeSum;
	cout << "\nThe code multiply to give: " << CodeProduct << endl;

	int GuessA, GuessB, GuessC;

	cin >> GuessA;
	cin >> GuessB;
	cin >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
		cout << "\nYou win! \n";
		return true;
	}
	else {
		cout << "\nYou turn on the alarm! You lose! \n";
		return false;
	}
}

int main() {

	int Difficulty = 1;
	int MaxDifficulty = 10;
	string PlayerName;

	cout << "What's is your name?" << endl;
	cin >> PlayerName;

	while (Difficulty <= MaxDifficulty) {
		bool bLevelComplete = PlayGameAtDifficulty(Difficulty, PlayerName);
		cin.clear(); //clears any errors
		cin.ignore(); //discards the buffer
		

		if (bLevelComplete) {
			Difficulty++;
		}
		else {
			cout << "Try again on this same level";
		}
	}
	
	cout << "\n*** Great work agent " << PlayerName <<"! You got all the files! Now get out of there! ***\n";
	
	
	return 0;
}