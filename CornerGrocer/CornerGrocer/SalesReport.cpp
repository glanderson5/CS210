#include "SalesReport.h"
#include <iostream>
#include <iomanip>

void SalesReport::AddItem(ProduceItem& item)
{
	for (int i = 0; i < this->totalSales.size(); i++) {
		if (this->totalSales.at(i).GetItemName() == item.GetItemName()) {
			this->totalSales.at(i).SetNumPurchased(this->totalSales.at(i).GetNumPurchased() + 1);
			return;
		}
	}
	this->totalSales.push_back(item);
}

void SalesReport::PrintReport()
{
	for (int i = 0; i < this->totalSales.size(); i++) {
		ProduceItem currItem = this->totalSales.at(i);
		cout << currItem.GetItemName() << " " << currItem.GetNumPurchased() << endl;
	}
}

void SalesReport::PrintHistogram()
{
	for (int i = 0; i < this->totalSales.size(); i++) {
		ProduceItem currItem = this->totalSales.at(i);
		cout << right << setw(this->GetLongestName()) << currItem.GetItemName() << " " << currItem.GetHisto() << endl;
	}
}

int SalesReport::SearchItemFrequency(string itemName)
{
	for (int i = 0; i < this->totalSales.size(); i++) {
		if (this->totalSales.at(i).GetItemName() == itemName) {
			return this->totalSales.at(i).GetNumPurchased();
		}
	}
	return 0; // Return 0 if no match found
}

int SalesReport::GetReportSize()
{
	return this->totalSales.size();
}

int SalesReport::GetLongestName()
{
	int longest = 0;
	for (int i = 0; i < this->totalSales.size(); i++) {
		if (this->totalSales.at(i).GetItemName().size() > longest) {
			longest = this->totalSales.at(i).GetItemName().size();
		}
	}
	return longest;
}
