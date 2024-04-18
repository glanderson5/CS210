#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "ProduceItem.h"
#include "SalesReport.h"

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

	dailySales.PrintReport();
	cout << endl;
	dailySales.PrintHistogram();
	cout << "Zucchini" << dailySales.SearchItemFrequency("Zucchini") << endl;
	cout << "Cranberries" << dailySales.SearchItemFrequency("Cranberries") << endl;
	cout << "Peas" << dailySales.SearchItemFrequency("Peas") << endl;
	return 0;
}
