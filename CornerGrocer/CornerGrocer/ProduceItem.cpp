/*
 *	ProduceItem.cpp
 *	Class representing an item that is sold at Corner Grocer
 * 
 *  @author Greg Anderson
 *	@date 04/21/2024
 */

#include "ProduceItem.h"

// Constructor
ProduceItem::ProduceItem(string name)
{
	this->itemName = name;
	this->numPurchased = 1;  // Initialize to 1
}
// itemName getter
string ProduceItem::GetItemName()
{
	return this->itemName;
}
// itemName setter
void ProduceItem::SetItemName(string name)
{
	this->itemName = name;
}
// numPurchased getter
int ProduceItem::GetNumPurchased()
{
	return this->numPurchased;
}
// numPurchased getter
void ProduceItem::SetNumPurchased(int n)
{
	this->numPurchased = n;
}
/*
*  Creates a string of asterisks that correlates to the sales frequency
*  Used to generrate histogram
* 
*  @return string of asterisks that is the length of numPurchased
*/
string ProduceItem::GetHisto()
{
	string symbols = "";
	for (int i = 0; i < this->GetNumPurchased(); i++) {
		symbols += "*";
	}
	return symbols;
}
