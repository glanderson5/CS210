#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#include "ProduceItem.h"


int main() {

	ifstream inFS;  // Create input filestream to read text file
	inFS.open("InputFile.txt");  // Attempt to open file
	if (!inFS.is_open()) {
		cout << "Could not open file" << endl;
		return 1; // 1 indicates error
	}

	vector<string> purchases;
	for (int i = 0; i < 10; i++) {
		string item;
		getline(inFS, item);
		purchases.push_back(item);
	}

	for (int i = 0; i < 10; i++) {
		cout << purchases[i] << endl;
	}
	return 0;
}