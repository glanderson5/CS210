#pragma once
#ifndef SALESREPORT.h
#define SALESREPORT

#include <string>
#include <vector>

using namespace std;

#include "ProduceItem.h"

class SalesReport
{
public:
	void AddItem(ProduceItem& item);
	void PrintReport();
private:
	vector<ProduceItem> totalSales;
};

#endif
