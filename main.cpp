//Jonathan Wynn
//Lab 7 Out

#include <iostream>
#include "graph1.h"
#include "Configuration.h"
#include "Menu.h"
#include "Game.h"
#include "Windows.h"
using namespace std;

int main()
{
	string names[] = { "Afghanistan", "Albania", "Algeria", "American_Samoa", "Andorra", "Angola", "Anguilla",
	"Antigua_and_Barbuda", "Argentina","Armenia", "Aruba","Australia", "Austria","Azerbaijan",
	"Bahamas", "Bahrain", "Bangladesh", "Barbados", "Belarus", "Belgium", "Belize", "Benin",
	"Bermuda", "Bhutan", "Bolivia", "Bosnia", "Botswana", "Brazil", "British_Virgin_Islands",
	"Brunei", "Bulgaria", "Burkina_Faso", "Burundi", "Cambodia", "Cameroon", "Canada", "Cape_Verde","Cayman_Islands", "Central_African_Republic", "Chad", "Chile", "China","Christmas_Island",
	"Colombia","Comoros","Cook_Islands","Costa_Rica","Croatia","Cuba","Cyprus","Cyprus_Northern",
	"Czech_Republic","Cte_dIvoire","Democratic_Republic_of_the_Congo","Denmark","Djibouti","Dominica",
	"Dominican_Republic","Ecuador","Egypt","El_Salvador","Equatorial_Guinea","Eritrea","Estonia",
	"Ethiopia","Falkland_Islands","Faroe_Islands","Fiji","Finland","France","French_Polynesia",
	"Gabon","Gambia","Georgia","Germany","Ghana","Gibraltar","Greece","Greenland","Grenada",
	"Guam","Guatemala","Guinea","Guinea_Bissau","Guyana","Haiti","Honduras","Hong_Kong","Hungary",
	"Iceland", "India","Indonesia","Iran","Iraq", "Ireland","Israel","Italy","Jamaica","Japan",
	"Jordan", "Kazakhstan","Kenya","Kiribati","Kuwait","Kyrgyzstan","Laos","Latvia","Lebanon",
	"Lesotho","Liberia","Libya","Liechtenstein","Lithuania","Luxembourg","Macao","Macedonia",
	"Madagascar","Malawi","Malaysia","Maldives","Mali","Malta","Marshall_Islands","Martinique",
	"Mauritania","Mauritius","Mexico","Micronesia","Moldova","Monaco","Mongolia","Montserrat",
	"Morocco","Mozambique","Myanmar","Namibia","Nauru","Nepal","Netherlands","Netherlands_Antilles",
	"New_Zealand", "Nicaragua","Niger","Nigeria","Niue","Norfolk_Island","North_Korea","Norway",
	"Oman","Pakistan","Palau","Panama","Papua_New_Guinea","Paraguay","Peru","Philippines",
	"Pitcairn_Islands","Poland","Portugal","Puerto_Rico","Qatar","Republic_of_the_Congo","Romania",
	"Russian_Federation","Rwanda","Saint_Kitts_and_Nevis","Saint_Lucia","Saint_Pierre","Saint_Vicent_and_the_Grenadines",
	"Samoa","San_Marino","Sao_Tom‚_and_Prncipe","Saudi_Arabia","Senegal","Serbia_and_Montenegro",
	"Seychelles", "Sierra_Leone", "Singapore","Slovakia","Slovenia","Soloman_Islands","Somalia",
	"South_Africa","South_Georgia","South_Korea","Soviet_Union","Spain","Sri_Lanka","Sudan","Suriname",
	"Swaziland","Sweden","Switzerland","Syria", "Taiwan","Tajikistan","Tanzania","Thailand",
	"Tibet", "Timor-Leste", "Togo","Tonga","Trinidad_and_Tobago","Tunisia", "Turkey","Turkmenistan",
	"Turks_and_Caicos_Islands", "Tuvalu","UAE","Uganda","Ukraine","United_Kingdom","United_States_of_America",
	"Uruguay","US_Virgin_Islands","Uzbekistan","Vanuatu","Vatican_City","Venezuela","Vietnam",
	"Wallis_and_Futuna","Yemen","Zambia","Zimbabwe" };

	char repeat;
	do
	{
		//instantiate the configuration object using constructor
		Configuration config(names, 224);

		//variables
		int numQuestions = 0;
		int numChoices = 0;
		int playerScore = 0;
		

		displayGraphics();

		//setting number of questions using config object
		cout << "Enter # of questions for the quiz: ";
		cin >> numQuestions;
		config.setNoQuestions(numQuestions);
		while (config.setNoQuestions(numQuestions) != true)
		{
			cout << "Invalid entry. Please enter # of questions for the quiz"
				<< " between 3 and 20 inclusively:";
			cin >> numQuestions;
			config.setNoQuestions(numQuestions);
		} 
		numQuestions = config.getNoQuestions();

		//setting number of choices in config object
		cout << "\nEnter the number of choices per question: ";
		cin >> numChoices;
		config.setNoChoices(numChoices);
		while (config.setNoChoices(numChoices) != true)
		{
			cout << "Invalid entry. Please enter # of choices per question"
				<< " between 2 and 6 inclusively:";
			cin >> numChoices;
			config.setNoChoices(numChoices);
		} 
		numChoices = config.getNoChoices();

		//instantiate the menu object
		Menu menu;
		//set configuration object within the menu using the setConfig method
		menu.setConfig(config);
		//instantiate the game object
		Game game;
		//sets the menu object within the game object
		game.setMenu(menu);
		//invokes the play method, returns the correctly answered from the play method and store it in playerScore
		playerScore = game.play();

		Sleep(2000);
		clearGraphics();
		//clears screen, then displaying final statistics
		double finalScore = ((static_cast<double>(playerScore) / static_cast<double>(numQuestions)) * 100.00);
		gout << setPos(200, 220) << "Quiz Over" << endg;
		gout << setPos(200, 246) << "Your percentage: " << finalScore << endg;

		//repeat program
		cout << "Would you like to play again? (y/n)";
		cin >> repeat;
		clearGraphics();
		system("cls");
	} while (repeat == 'y' || repeat == 'Y');
}
