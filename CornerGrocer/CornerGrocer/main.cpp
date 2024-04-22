/*
 *  main.cpp
 *	Driver file for Corner Grocer project
 * 
 *  Date: 21 April 2024
 *  Author: Greg Anderson
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

using namespace std;

#include "ProduceItem.h"
#include "SalesReport.h"

/*
 * Displays the menu and prompts user for selection
 * 
 * @return an int representing the users selection
 */
int DisplayMenu() {
	//Print menu options
	cout << "******************************************" << endl;
	cout << "**   Corner Grocer Daily Sales Report   **" << endl;
	cout << "**--------------------------------------**" << endl;
	cout << "**   Options:                           **" << endl;
	cout << "**--------------------------------------**" << endl;
	cout << "**   1 - Search by item                 **" << endl;
	cout << "**                                      **" << endl;
	cout << "**   2 - View sales report              **" << endl;
	cout << "**                                      **" << endl;
	cout << "**   3 - View sales histogram           **" << endl;
	cout << "**                                      **" << endl;
	cout << "**   4 - Exit program                   **" << endl;
	cout << "******************************************" << endl;
	cout << endl;
	// Prompt user for selection
	cout << "Enter your selection and press return" << endl;

	bool validChoice = false;  // Boolean to track validity of user choice and control loop
	int choice;  // Users selection
	// Loop until the users choice is valid
	while (!validChoice) {
		try {
			cin >> choice;  // Get user input
			if (cin.fail()) {  // If input cannot be stored as int
				throw invalid_argument("Not a digit");
			}
			if (choice < 1 || choice > 4) {  //If input is an int, but not between 1-4
				throw out_of_range("Not in range");
			}
			validChoice = true; // Choice is valid if above conditions are met
		}
		catch (invalid_argument e) {
			cout << e.what() << endl;  // Print error message
		}
		catch (out_of_range e) {
			cout << e.what() << endl;  // Print error message
		}
		cin.clear();  // Clear error flag in case input is not valid
		cin.ignore(256, '\n');  // Ignore invalid input
	}
	return choice;
}
int main() {
	ifstream inFS;  // Create input filestream to read text file
	inFS.open("InputFile.txt");  // Attempt to open file
	if (!inFS.is_open()) {
		cout << "Could not open file" << endl;
		return 1; // Indicates error opening file
	}

	SalesReport dailySales;  // Create SalesReport to store input
	ProduceItem currItem;  // The item to be added to the sales report

	while (inFS) {  // Loop while there is still lines of input
		string itemName;  // the name of the item to add
		getline(inFS, itemName);  // Set item name to the line of input
		if (itemName != "") {  // If the name is not blank 
			currItem.SetItemName(itemName);  // Set name of currItem to the input text
			dailySales.AddItem(currItem);  // Add item to the sales report
		}
	}

	dailySales.CreateBackup();  // Backup data in "frequency.dat"

	int userChoice = -1;  // Int to store the users menu selection
	while (userChoice != 4) {  // Loop until user selects exit option
		userChoice = DisplayMenu();  // Display the menu at the start of each loop
		switch (userChoice) {
		// 1: Search by item name
		case 1:
		{
			string itemName;  // The name to search for
			char yn;  // Character to check if the user wants to keep searching
			bool keepSearching = true;  // Loop control boolean
			while (keepSearching) {  // Loop until user chooses to exit
				// Prompt for input and pass to search function
				cout << "Enter name of item:" << endl;
				cin >> itemName;
				cout << itemName << " has been purchased " << dailySales.SearchItemFrequency(itemName) << " times today." << endl;
				cout << "Search for another item? (y/n)" << endl;  // Check if user wants to search again
				cin >> yn;
				if (yn != 'y') {  // If user does not want to keep searching... 
					keepSearching = false;  // ...exit loop
				}
			}
			break;
		}
		case 2:
		// 2: Print sales report with numbers
			dailySales.PrintReport();
			break;
		case 3:
		// 3: Print sales report with symbols
			dailySales.PrintHistogram();
			break;
		case 4:
		// 4: Exit program
			cout << "Goodbye!" << endl;
			break;
		default:
			cout << "Error";  // Shouldn't ever execute
		}
	}
	return 0;
}