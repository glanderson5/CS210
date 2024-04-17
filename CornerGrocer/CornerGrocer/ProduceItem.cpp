#include "ProduceItem.h"

ProduceItem::ProduceItem(string name)
{
	this->itemName = name;
	this->numPurchased = 0;
}

string ProduceItem::GetItemName()
{
	return this->itemName;
}

void ProduceItem::SetItemName(string name)
{
	this->itemName = name;
}

int ProduceItem::GetNumPurchased()
{
	return this->numPurchased;
}

void ProduceItem::SetNumPurchased(int n)
{
	this->numPurchased = n;
}
