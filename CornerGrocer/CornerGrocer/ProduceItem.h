#pragma once
#ifndef PRODUCEITEM.h
#define PRODUCEITEM

#include <string>

using namespace std;

class ProduceItem
{
public:
	ProduceItem(string name = "NONAME");
	string GetItemName();
	void SetItemName(string name);
	int GetNumPurchased();
	void SetNumPurchased(int n);

private:
	string itemName;
	int numPurchased;
};

#endif


