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
	void PrintHistogram();
	int SearchItemFrequency(string itemName);
	int GetReportSize();
	void CreateBackup();
private:
	vector<ProduceItem> totalSales;
	int GetLongestName();
};

#endif
