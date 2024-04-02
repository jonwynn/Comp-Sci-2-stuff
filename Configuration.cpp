//Jonathan Wynn
//Lab 7 Out
//configuration method definitions

#include <iostream>
#include "graph1.h"
#include "Windows.h"
#include "Configuration.h"
using namespace std;

Configuration::Configuration()
{
	noChoices = 4;
	noQuestions = 10;
	noFlagNames = 224;
	flagNames = new string[224];

}
Configuration::Configuration(string* value, int noFlagNames)
{
	noChoices = 4;
	noQuestions = 10;
	this->noFlagNames = noFlagNames;
	flagNames = new string[noFlagNames];
	for (int i = 0; i < noFlagNames; i++)
	{
		this->flagNames[i] = value[i];
	}
}
Configuration::~Configuration()
{
	//delete[] flagNames; // could not get program to compile with destructor
}
Configuration::Configuration(const Configuration& config)
{
	int size = config.noFlagNames;
	this->noChoices = config.noChoices;
	this->noQuestions = config.noQuestions;
	this->noFlagNames = config.noFlagNames;
	this->flagNames = new string[size];
	for (int i = 0; i < size; i++)
	{
		this->flagNames[i] = config.flagNames[i];
	}
}
bool Configuration::setNoChoices(int no_choices)
{
	//valid values are between 2 and 6 inclusively. returns false if no_choices is out of range. clips the 
	//value to 2 or 6 if no_choices is out of range.
	if (no_choices < 2)
	{
		this->noChoices = 2;
		return false;
	}
	else if (no_choices > 6)
	{
		this->noChoices = 6;
		return false;
	}
	else
	{
		this->noChoices = no_choices;
		return true;
	}
}
bool Configuration::setNoQuestions(int no_questions)
{
	//valid choices are between 3 and 20. 
	// returns false if no_questions if out of range. clips to 3 or 20
	if (no_questions < 3)
	{
		this->noQuestions = 3;
		return false;
	}
	else if (no_questions > 20)
	{
		this->noQuestions = 20;
		return false;
	}
	else
	{
		this->noQuestions = no_questions;
		return true;
	}

}
void Configuration::setFlagNameAt(string flagName, int position)
{
	this->flagNames[position] = flagName;
}
string Configuration::getFlagNameAt(int index)
{
	return flagNames[index];
}
string* Configuration::getAllFlagNames()
{
	return flagNames;
}
void Configuration::setNoFlagNames(int noFlagNames)
{
	if (noFlagNames < 5)
	{
		this->noFlagNames = 5;
	}
	else if (noFlagNames > 224)
	{
		this->noFlagNames = 224;
	}
	else
	{
		this->noFlagNames = noFlagNames;
	}
}
int Configuration::getNoChoices()
{
	return noChoices;
}
int Configuration::getNoQuestions()
{
	return noQuestions;
}
int Configuration::getNoFlagNames()
{
	return noFlagNames;
}