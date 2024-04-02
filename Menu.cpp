//Jonathan Wynn
//Lab 7 Out
//menu class method definitions

#include <iostream>
#include "graph1.h"
#include "Menu.h"
#include "Configuration.h"
using namespace std;

Menu::Menu()
{
	choices = new string[4];
	selection = 0;
}
Menu::~Menu()
{
	delete[] choices; // could not get program to compile with destructor
}
Menu::Menu(const Menu& menu) //copy constructor
{
	this->selection = menu.selection;
	this->setConfig(menu.config);

	int size = config.getNoChoices();
	this->choices = new string[size];

	for (int i = 0; i < size; i++)
	{
		choices[i] = "filler";
	}
}
void Menu::setConfig(Configuration config) //Sets config datafield
{

	//this->config = Configuration(config);
	this->config.setNoChoices(config.getNoChoices());
	this->config.setNoQuestions(config.getNoQuestions());
	this->config.setNoFlagNames(config.getNoFlagNames());
	int size = config.getNoFlagNames();
	for (int i = 0; i < size; i++)
	{
		this->config.setFlagNameAt(config.getFlagNameAt(i), i);
	}
}
Configuration Menu::getConfig()
{
	return config;
}
void Menu::setSelection(int selection)//Sets selection data field based on user entry from menu 	
{
	this->selection = selection;
}
void Menu::setChoice(int index, string flag_name)
{
	this->choices[index] = flag_name;
}
string Menu::getChoice(int index)
{
	return choices[index];
}
int Menu::getSelection()
{
	return selection;
}

int Menu::displayMenu()
{
	//draws rectangles below flag 
	int userInput;

	for (int i = 0; i < config.getNoChoices(); i++)
	{
		if (config.getNoChoices() == 2)
		{
			gout << setPos(200, 220) << "Choose from the following:" << endg;
			gout << drawRect(200, 235, 300, 20) << setColor(128, 128, 128) << endg;
			gout << drawRect(200, 261, 300, 20) << setColor(128, 128, 128) << endg;
			gout << setPos(200, 251) << "1. " << choices[0] << endg;
			gout << setPos(200, 277) << "2. " << choices[1] << endg;
			gout << setPos(200, 297) << "Enter Choice on Console:" << endg;
		}
		else if (config.getNoChoices() == 3)
		{
			gout << setPos(200, 220) << "Choose from the following:" << endg;
			gout << drawRect(200, 235, 300, 20) << setColor(128, 128, 128) << endg;
			gout << drawRect(200, 261, 300, 20) << setColor(128, 128, 128) << endg;
			gout << drawRect(200, 287, 300, 20) << setColor(128, 128, 128) << endg;
			gout << setPos(200, 251) << "1. " << choices[0] << endg;
			gout << setPos(200, 277) << "2. " << choices[1] << endg;
			gout << setPos(200, 303) << "3. " << choices[2] << endg;
			gout << setPos(200, 323) << "Enter Choice on Console:" << endg;
		}
		else if (config.getNoChoices() == 4)
		{
			gout << setPos(200, 220) << "Choose from the following:" << endg;
			gout << drawRect(200, 235, 300, 20) << setColor(128, 128, 128) << endg;
			gout << drawRect(200, 261, 300, 20) << setColor(128, 128, 128) << endg;
			gout << drawRect(200, 287, 300, 20) << setColor(128, 128, 128) << endg;
			gout << drawRect(200, 313, 300, 20) << setColor(128, 128, 128) << endg;
			gout << setPos(200, 251) << "1. " << choices[0] << endg;
			gout << setPos(200, 277) << "2. " << choices[1] << endg;
			gout << setPos(200, 303) << "3. " << choices[2] << endg;
			gout << setPos(200, 329) << "4. " << choices[3] << endg;
			gout << setPos(200, 355) << "Enter Choice on Console:" << endg;
		}
		else if (config.getNoChoices() == 5)
		{
			gout << setPos(200, 220) << "Choose from the following:" << endg;
			gout << drawRect(200, 235, 300, 20) << setColor(128, 128, 128) << endg;
			gout << drawRect(200, 261, 300, 20) << setColor(128, 128, 128) << endg;
			gout << drawRect(200, 287, 300, 20) << setColor(128, 128, 128) << endg;
			gout << drawRect(200, 313, 300, 20) << setColor(128, 128, 128) << endg;
			gout << drawRect(200, 339, 300, 20) << setColor(128, 128, 128) << endg;
			gout << setPos(200, 251) << "1. " << choices[0] << endg;
			gout << setPos(200, 277) << "2. " << choices[1] << endg;
			gout << setPos(200, 303) << "3. " << choices[2] << endg;
			gout << setPos(200, 329) << "4. " << choices[3] << endg;
			gout << setPos(200, 355) << "5. " << choices[4] << endg;
			gout << setPos(200, 381) << "Enter Choice on Console:" << endg;
		}
		else if (config.getNoChoices() == 6)
		{
			gout << setPos(200, 220) << "Choose from the following: " << endg;
			gout << drawRect(200, 235, 300, 20) << setColor(128, 128, 128) << endg;
			gout << drawRect(200, 261, 300, 20) << setColor(128, 128, 128) << endg;
			gout << drawRect(200, 287, 300, 20) << setColor(128, 128, 128) << endg;
			gout << drawRect(200, 313, 300, 20) << setColor(128, 128, 128) << endg;
			gout << drawRect(200, 339, 300, 20) << setColor(128, 128, 128) << endg;
			gout << drawRect(200, 365, 300, 20) << setColor(128, 128, 128) << endg;
			gout << setPos(200, 251) << "1. " << choices[0] << endg;
			gout << setPos(200, 277) << "2. " << choices[1] << endg;
			gout << setPos(200, 303) << "3. " << choices[2] << endg;
			gout << setPos(200, 329) << "4. " << choices[3] << endg;
			gout << setPos(200, 355) << "5. " << choices[4] << endg;
			gout << setPos(200, 381) << "6. " << choices[5] << endg;
			gout << setPos(200, 406) << "Enter Choice on Console:" << endg;
		}
		//get selection from the user and set it
	}
	cout << "Enter selection: ";
	cin >> userInput;
	setSelection(userInput);
	selection = getSelection();
	return selection;
}

void Menu::displayFlag(string flag_name)
{
	string fileName;
	string bmp = ".bmp";
	fileName = flag_name + bmp;
	displayBMP(fileName, 200, 50);
}