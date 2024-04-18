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

	for (int i = 0; i < 10; i++) {
		string itemName;
		getline(inFS, itemName);
		currItem.SetItemName(itemName);
		dailySales.AddItem(currItem);
	}

	dailySales.PrintReport();
	cout << endl;
	dailySales.PrintHistogram();

	return 0;
}
