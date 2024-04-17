#include "SalesReport.h"
#include <iostream>

void SalesReport::AddItem(ProduceItem& item)
{
	for (int i = 0; i < this->totalSales.size(); i++) {
		if (this->totalSales.at(i).GetItemName() == item.GetItemName()) {
			this->totalSales.at(i).SetNumPurchased(item.GetNumPurchased() + 1);
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
