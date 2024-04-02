//Jonathan Wynn
//Lab 7 Out
//game class method definitions

#include <iostream>
#include "graph1.h"
#include "Configuration.h"
#include "Menu.h"
#include "Game.h"
#include "Windows.h"
using namespace std;

Game::Game()
{
	no_correct = 0;
}
int Game::play()
{
	int playerScore = 0;
	int userAnswer;
	string randomFlag;
	bool duplicate = false;
	int* randIndex;
	randIndex = new int[this->menu.getConfig().getNoChoices()];
	srand(time(0));
	for (int k = 0; k < this->menu.getConfig().getNoQuestions(); k++)
	{
		for (int i = 0; i < this->menu.getConfig().getNoChoices(); i++)
		{
			randIndex[i] = rand() % 224;
			do
			{
				duplicate = false;
				for (int j = 0; j < i; j++)
				{
					if (randIndex[i] == randIndex[j])
					{
						randIndex[i] = rand() % 224;
						duplicate = true;
						break;
					}
				}
			} while (duplicate);
			int randNumber = randIndex[i];

			string flag = menu.getConfig().getFlagNameAt(randNumber);

			menu.setChoice(i, flag); //sets choice to the random flag

		}
		
		gout << setPos(200, 30) << "Questions #" << (k + 1) << endg;
		
		int flagPosition = (rand() % (menu.getConfig().getNoChoices())); //picks a random flag index from the choices that were set
		
		randomFlag = menu.getChoice(flagPosition); //gets the string value from the random flag
		
		menu.displayFlag(randomFlag); // displays the random flag
		gout << setPos(200, 220) << "Choose from the following: " << endg;
		userAnswer = menu.displayMenu(); //user picks their selection and displayMenu returns the integer along with displaying graphics
		
		if (flagPosition == (userAnswer - 1))
		{
			if (menu.getConfig().getNoChoices() == 2)
			{
				gout << setPos(200, 297) << "CORRECT!!!" << endg;
			}
			if (menu.getConfig().getNoChoices() == 3)
			{
				gout << setPos(200, 323) << "CORRECT!!!" << endg;
			}
			if (menu.getConfig().getNoChoices() == 4)
			{
				gout << setPos(200, 355) << "CORRECT!!!" << endg;
			}
			if (menu.getConfig().getNoChoices() == 5)
			{
				gout << setPos(200, 381) << "CORRECT!!!" << endg;
			}
			if (menu.getConfig().getNoChoices() == 6)
			{
				gout << setPos(200, 406) << "CORRECT!!!" << endg;
			}
			playerScore++;
			Sleep(5000);
		}
		else if (flagPosition != (userAnswer - 1))
		{
			if (menu.getConfig().getNoChoices() == 2)
			{
				gout << setPos(200, 297) << "INCORRECT!!! - The correct answer is " << this->menu.getChoice(flagPosition) << endg;
			}
			if (menu.getConfig().getNoChoices() == 3)
			{
				gout << setPos(200, 323) << "INCORRECT!!! - The correct answer is " << this->menu.getChoice(flagPosition) << endg;
			}
			if (menu.getConfig().getNoChoices() == 4)
			{
				gout << setPos(200, 355) << "INCORRECT!!! - The correct answer is " << this->menu.getChoice(flagPosition) << endg;
			}
			if (menu.getConfig().getNoChoices() == 5)
			{
				gout << setPos(200, 381) << "INCORRECT!!! - The correct answer is " << this->menu.getChoice(flagPosition) << endg;
			}
			if (menu.getConfig().getNoChoices() == 6)
			{
				gout << setPos(200, 406) << "INCORRECT!!! - The correct answer is " << this->menu.getChoice(flagPosition) << endg;
			}

			Sleep(5000);
		}
	}
	return playerScore;
}
void Game::setMenu(Menu menu)
{
	this->menu.setConfig(menu.getConfig());
	this->menu.setSelection(menu.getSelection());
}
Menu Game::getMenu()
{
	return this->menu;
}
int Game::getNoCorrect()
{
	return this->no_correct;
}
