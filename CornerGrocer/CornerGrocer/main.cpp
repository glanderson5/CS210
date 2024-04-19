#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

using namespace std;

#include "ProduceItem.h"
#include "SalesReport.h"

int DisplayMenu() {
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
	cout << "Enter your selection and press return" << endl;

	bool validChoice = false;
	int choice;
	while (!validChoice) {
		try {
			cin >> choice;
			if (cin.fail()) {
				throw invalid_argument("Not a digit");
			}
			if (choice < 1 || choice > 4) {
				throw out_of_range("Not in range");
			}
			validChoice = true;
		}
		catch (invalid_argument e) {
			cout << e.what() << endl;
		}
		catch (out_of_range e) {
			cout << e.what() << endl;	
		}
		cin.clear();
		cin.ignore(256, '\n');
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

	SalesReport dailySales;
	ProduceItem currItem;

	while (inFS) {
		string itemName;
		getline(inFS, itemName);
		if (itemName != "") {
			currItem.SetItemName(itemName);
			dailySales.AddItem(currItem);
		}
	}

	int userChoice = -1;
	while (userChoice != 4) {
		userChoice = DisplayMenu();
		switch (userChoice) {
		case 1:
		{
			string itemName;
			char yn;
			bool keepSearching = true;
			while (keepSearching) {
				cout << "Enter name of item:" << endl;
				cin >> itemName;
				cout << itemName << " has been purchased " << dailySales.SearchItemFrequency(itemName) << " times today." << endl;
				cout << "Search for another item? (y/n)" << endl;
				cin >> yn;
				if (yn != 'y') {
					keepSearching = false;
				}
			}
			break;
		}
		case 2:
			dailySales.PrintReport();
			break;
		case 3:
			dailySales.PrintHistogram();
			break;
		default:
			cout << "Error";
		}
	}

	return 0;
}
