

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<sstream>

using namespace std;

int main()
{
	while (true) {
		enum fields { WORD, HINT, NUM_FIELDS };
		const int NUM_WORDS = 5;
		const string WORDS[NUM_WORDS] =
		{
			{ "wall" },
			{ "glasses" },
			{ "labored" },
			{ "persistent" },
			{ "jumble" }
		};
		const string HINTS[NUM_WORDS]{
			{ "Do you feel you're banging your head against something?" },
			{ "These might help you see the answer." },
			{ "Going slowly, is it?" },
			{ "Keep at it." },
			{ "It's what the game is all about." }
		};

		srand(static_cast<unsigned int>(time(0)));
		int choice = (rand() % NUM_WORDS);
		string theWord = WORDS[choice];  // word to guess
		string theHint = HINTS[choice];  // hint for word
		string jumble = theWord;  // jumbled version of word
		int length = jumble.size();
		int selection;
		string guess;

		cout << "\n\t\tChapter 3 Projects: \n" << endl;
		cout << "Please choose:\n" << endl;
		cout << "1: [Project 3.1] Parallel Word Scramble" << endl;
		cout << "2: [Project 3.2] Multi-Dem Word Scramble" << endl;
		cout << "3: [Project 3.3] Card Array" << endl;
		cout << "4: [Project 3.4] Adaptive Score Board" << endl;
		cout << "5: [Project 3.5] Binary Code Cracker" << endl;
		cout << "6: Quit" << endl;
		cout << "\nSelection: ";
		cin >> selection;
		system("CLS");
		switch (selection) {
		case 1: {
			for (int i = 0; i < length; ++i)
			{
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;
			}

			cout << "\t\t\tWelcome to Word Jumble!\n\n";
			cout << "Unscramble the letters to make a word.\n";
			cout << "Enter 'hint' for a hint.\n";
			cout << "Enter 'quit' to quit the game.\n\n";
			cout << "The jumble is: " << jumble;


			cout << "\n\nYour guess: ";
			cin >> guess;

			while ((guess != theWord) && (guess != "quit"))
			{
				if (guess == "hint")
				{
					cout << theHint;
				}
				else
				{
					cout << "Sorry, that's not it.";
				}

				cout << "\n\nYour guess: ";
				cin >> guess;
			}

			if (guess == theWord)
			{
				cout << "\nThat's it!  You guessed it!\n";
			}

			cout << "\nThanks for playing.\n";
			system("pause");
			system("CLS");
			break;
		}break;
		case 2: {
			const string WORDS[NUM_WORDS][NUM_FIELDS] =
			{
				{ "wall", "Do you feel you're banging your head against something?" },
				{ "glasses", "These might help you see the answer." },
				{ "labored", "Going slowly, is it?" },
				{ "persistent", "Keep at it." },
				{ "jumble", "It's what the game is all about." }
			};

			srand(static_cast<unsigned int>(time(0)));
			int choice = (rand() % NUM_WORDS);
			string theWord = WORDS[choice][WORD];  // word to guess
			string theHint = WORDS[choice][HINT];  // hint for word

			string jumble = theWord;  // jumbled version of word
			int length = jumble.size();
			for (int i = 0; i < length; ++i)
			{
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;
			}

			cout << "\t\t\tWelcome to Word Jumble!\n\n";
			cout << "Unscramble the letters to make a word.\n";
			cout << "Enter 'hint' for a hint.\n";
			cout << "Enter 'quit' to quit the game.\n\n";
			cout << "The jumble is: " << jumble;

			string guess;
			cout << "\n\nYour guess: ";
			cin >> guess;

			while ((guess != theWord) && (guess != "quit"))
			{
				if (guess == "hint")
				{
					cout << theHint;
				}
				else
				{
					cout << "Sorry, that's not it.";
				}

				cout << "\n\nYour guess: ";
				cin >> guess;
			}

			if (guess == theWord)
			{
				cout << "\nThat's it!  You guessed it!\n";
			}

			cout << "\nThanks for playing.\n";
			system("pause");
			system("CLS");
			break; }break;
		case 3: {
			const char BASE[2][13]{
				{ 'c', 'h','s', 'd' },
				{ '2', '3', '4', '5', '6','7','8', '9', '10', 'J', 'Q', 'K', 'A' } };
			int cap = 4;
			int magTen = 9;
			for (int i = 0; i < sizeof(BASE[1]); i++)
			{
				for (int j = 0; j < cap; j++)
				{
					if (i == magTen - 1)
					{
						cout << "10" << BASE[0][j] << " ";
						if (j == cap - 1)
						{
							cout << endl;
						}
					}
					else
					{
						cout << BASE[1][i] << BASE[0][j] << " ";
						if (j == cap - 1)
						{
							cout << endl;
						}
					}

				}
			}
		}break;
		case 4: {
			typedef unsigned short int val;
			string Players[5][2];
			for (int i = 0; i <= 4; i++) {
				Players[i][0] = "Mike";
				Players[i][1] = "1000";
			}
			while (true) {
				bool changed = false;
				string newName;
				string newScore;
				for (int j = 0; j < 1; j++)
				{
					cout << "\nType 'quit' if you wish to exit" << endl;
					cout << "\nPlayer Name: ";
					cin >> newName;
					
					if (newName == "quit" || newName == "Quit") {
						break;
					}
					cout << "Player Score: ";
					cin >> newScore;
					
					if (j == 0) {
						system("CLS");
					}
					val newVal = atoi(newScore.c_str());

					//cout << newVal << endl;
					

					string overScore = static_cast<ostringstream*>(&(ostringstream() << newVal))->str();
					string scoreSwap[2][2];
					if (newVal >= 65000)
					{
						newVal = newVal % 65000;
						//cout << newVal << endl;
						

						newScore = overScore;
					}
					//cout << overScore << endl;
					for (int i = 0; i <= 4; i++) {
						val value = atof(Players[i][1].c_str());
						val bottomValue = atof(Players[4][1].c_str());


						if (newVal >= value && changed == false)
						{
							scoreSwap[0][1] = Players[i][1];
							scoreSwap[0][0] = Players[i][0];
							Players[i][0] = newName;
							Players[i][1] = overScore;
							changed = true;
						}
						else if (newVal >= value && changed == true)
						{
							scoreSwap[1][0] = Players[i][0];
							scoreSwap[1][1] = Players[i][1];
							Players[i][0] = scoreSwap[0][0];
							Players[i][1] = scoreSwap[0][1];
							scoreSwap[0][0] = scoreSwap[1][0];
							scoreSwap[0][1] = scoreSwap[1][1];
						}
						else if (i == 4)
						{
							changed = false;
						}
						cout << "Player Name: " << Players[i][0] << "\t\tScore: " << Players[i][1] << endl;
						if (i == 4 && newVal <= bottomValue)
						{
							cout << "Sorry! You did not make the board " << newName << "!" << endl;
						}
					}
				}
				if (newName == "quit" || newName == "Quit") {
					break;
					system("CLS");
				}
			}
		}break;
		case 5: {

			int tries = 0;
			int g1, g2, g3, g4;
			int numRight = 0;
			int code[4];
			int max = 4;
			string agentName = "";
			while (agentName == "") {
				cout << "\n\t\tCIA SUPER ULTRA COOL INFORMATION TECHNOBASE" << endl;
				cout << "\t\t\t\tS.U.C.I.T" << endl;
				cout << "\n\nUsername: ";
				cin >> agentName;
				cout << "\nPassword:*********" << endl;
			}
			for (int i = 0; i< max; i++)
			{
				int randomNumber;
				randomNumber = 1 + rand() % 2;
				if (randomNumber == 1) {
					code[i] = 1;
				}
				else {
					code[i] = 0;
				}
			}
			cout << "\nLogin successful. Welcome, " << agentName << "." << endl;
			system("pause");
			system("CLS");
			cout << "\nYou have been tasked with a top-secret mission:" << endl;
			cout << "\n\nThe enemy has encrypted data that we MUST access." << endl;
			cout << "Millions of lives are at stake..." << endl;
			cout << "\nYou are the best hacker we have, " << agentName << ".\n" << endl;
			
			while (true)
			{
				if (tries >= 5) {
					system("CLS");
					cout << "\nBLAST! We were locked out. \nWe have failed this mission, and millions will pay the price.." << endl;
					cin.get();
					break;
				}
				cout << "\nThe number we need is a four digit binary number.\nPlease use your incredible skill to determine the code." << endl;
				cout << "First number (0 or 1): ";
				cin >> g1;
				if (g1 == code[0]) {
					numRight++;
				}
				cout << "Second number (0 or 1): ";
				cin >> g2;
				if (g2 == code[1]) {
					numRight++;
				}
				cout << "Third number (0 or 1): ";
				cin >> g3;
				if (g3 == code[2]) {
					numRight++;
				}
				cout << "Fourth number (0 or 1): ";
				cin >> g4;
				if (g4 == code[3]) {
					numRight++;
				}
				if (numRight == 4) {
					cout << "\nYou got it!!\n" << g1 << g2 << g3 << g4 << " was the right code!!" << endl;
					cout << "You saved the world!!" << endl;
					system("pause");
					break;
				}
				else {
					system("CLS");
					cout << "\nCurrent code guess: " << g1 << g2 << g3 << g4 << endl;
					cout << "\nThat code didn't work! But " << numRight << " of the numbers were right!" << endl;
					numRight = 0;
					tries++;
				}
			}
			
		}
		case 6: {return 0;}break;
		}
		system("pause");
	}
}
