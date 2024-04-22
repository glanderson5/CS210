/*
 *  SalesReport.cpp
 *	Class that stores and analyzes sales data
 *	
 *  Date: 20 April 2024
 *  Author: Greg Anderson
 */

#include "SalesReport.h"
#include <iostream>
#include <fstream>
#include <iomanip>

/*
 *	Adds a ProduceItem to the totalSales vector
 * 
 *  @param item, the item to add
 */
void SalesReport::AddItem(ProduceItem& item)
{
	// Iterate through totalSales and check if item already exists
	for (int i = 0; i < this->totalSales.size(); i++) {
		if (this->totalSales.at(i).GetItemName() == item.GetItemName()) {  // IF item already exists
			this->totalSales.at(i).SetNumPurchased(this->totalSales.at(i).GetNumPurchased() + 1);  // Increment numPurchased
			return;
		}
	}
	// If no match found, add new item to end of totalSales
	this->totalSales.push_back(item);
}
// Print sales data using numbers to represent sales frequency
void SalesReport::PrintReport()
{
		
	// Loop through totalSales, print each item/frequency
	for (int i = 0; i < this->totalSales.size(); i++) {
		ProduceItem currItem = this->totalSales.at(i);
		cout << currItem.GetItemName() << " " << currItem.GetNumPurchased() << endl;
	}
}
//Print sales data using symbols to represent sales frequency
void SalesReport::PrintHistogram()
{
	// Loop through total sales
	for (int i = 0; i < this->totalSales.size(); i++) {
		ProduceItem currItem = this->totalSales.at(i);
		// Format text so each symbol starts on the same space within the line
		// Use GetHisto to get string of symbols
		cout << right << setw(this->GetLongestName()) << currItem.GetItemName() << " " << currItem.GetHisto() << endl;
	}
}
/*
 *	Search for item within totalSales, return sales frequency
 * 
 * @param itemName, the name of the item to search for
 * @return int representing the sales frequency
 */
int SalesReport::SearchItemFrequency(string itemName)
{
	// Loop through totalSales
	for (int i = 0; i < this->totalSales.size(); i++) {
		// Check if name matches search parameter
		if (this->totalSales.at(i).GetItemName() == itemName) {
			// Return sales frequency if there's a match
			return this->totalSales.at(i).GetNumPurchased();
		}
	}
	return 0; // Return 0 if no match found
}
// Create backup file. Called automatically at start of program
void SalesReport::CreateBackup()
{	
	// Create backup file and file stream
	ofstream backupFile("frequency.dat");
	if (!backupFile.is_open()) {  // Make sure file opened correctly
		// Print error message and return if not
		cout << "Unable to open backup file" << endl; 
		return;
	}

	// Loop through totalSales
	for (int i = 0; i < this->totalSales.size(); i++) {
		// Write sales data to backup file
		backupFile << this->totalSales.at(i).GetItemName() << " " << this->totalSales.at(i).GetNumPurchased() << endl;
	}

	backupFile.close(); // Close file when done
}
/*
 *	Get the length of the name of the item with the longest name.
 *	Used to format histogram
 * 
 *	@return length of the longest name
 */
int SalesReport::GetLongestName()
{
	int longest = 0;  // Track the length of the longest name so far
	// Loop through totalSales
	for (int i = 0; i < this->totalSales.size(); i++) {
		// If current item has longer name
		if (this->totalSales.at(i).GetItemName().size() > longest) {
			// Set longest to new longest length
			longest = this->totalSales.at(i).GetItemName().size();
		}
	}
	return longest;  // Return length of longest name
}