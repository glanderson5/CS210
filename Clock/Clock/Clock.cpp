/**
* Clock.cpp
* Program that takes user input for the current time, prompts user
* to increment hours, minutes, seconds, or exit. Displays time in
* 12hr and 24hr formats.
* 
* @author Greg Anderson
* 24 March 2024
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
/**
 * Adds one hour
 * 
 * @param currHour, the hour value to be incremented
 */
void addOneHour(int& currHour) {
	currHour = (currHour + 1) % 24;
}
/**
 * Adds one minute
 * 
 * @param currHour, needs to be incremented if minute exceeds 59
 * @param currMin, the minute value to be incremented
 */
void addOneMinute(int& currHour, int& currMin) {
	int nextMin = currMin + 1;
	if (nextMin >= 60) {
		nextMin = nextMin % 60;
		addOneHour(currHour);
	}
	currMin = nextMin;
}
/**
 * Adds one second
 * 
 * @param currHour, needs to be passed to addOneMinute if second exceeds 59
 * @param currMin, needs to be incremented if second exceeds 59
 * @param currSec, the second value to be incremented
 */
void addOneSecond(int& currHour, int& currMin, int& currSec) {
	int nextSec = currSec + 1;
	if (nextSec >= 60) {
		nextSec = nextSec % 60;
		addOneMinute(currHour,currMin);
	}
	currSec = nextSec;
}
/**
 * Formats a number as 2 digits, with a leading 0 if needed
 *
 * @param n number to format, assumed between 0 and 59, inclusive
 * @return two digit string representation of number
 */
string twoDigitString(unsigned int n) {
	return (n < 10) ? ("0" + to_string(n)) : to_string(n); // Add a zero to the start of the string if one digit, otherwise cast to string, return
}
/**
 * Returns a string of length n, each character a c.
 *
 * @param n string length, >=0
 * @param c, the character to be repeated
 * @return string of n c's
 */
string nCharString(size_t n, char c) {
	string charString = "";
	for (int i = 0; i < n; ++i) {
		charString += c;
	}
	return charString;
}
/**
 * Formats the time in 24h format
 *
 * @param h, hours 0 to 23
 * @param m, minutes 0 to 59
 * @param s, seconds 0 to 59
 *
 * @return hh:mm:ss
 */
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
	// Convert h,m,s to 2 digit strings
	string hour = twoDigitString(h);
	string min = twoDigitString(m);
	string sec = twoDigitString(s);

	return hour + ":" + min + ":" + sec; // Format and return 
}
/**
 * Formats the time in 12hrformat
 *
 * @param h, hours 0 to 23
 * @param m, minutes 0 to 59
 * @param s, seconds 0 to 59
 *
 * @return hh:mm:ss + AM/PM
 */
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
	string meridiem = " A M";  // String representing "ante-meridiem" or "post-meridiem" (AM/PM). default to AM

	if (h == 0) {  // Switch 0 to 12 if h is 0 
		h = 12;
	}
	else if (h == 12) {  // Change meridiem if noon
		meridiem = " P M";
	}
	else if (h > 12) {  // Convert hours greater than 12 to 12hr time
		h = h % 12;
		meridiem = " P M";  // Change meridiem if past noon
	}
	// Convert h,m,s to two digit string
	string hour = twoDigitString(h);
	string min = twoDigitString(m);
	string sec = twoDigitString(s);

	return hour + ":" + min + ":" + sec + meridiem;  // Format and return
}
/**
* Prints the menu that displays options for user input
* 
* @param *strings[], an array of strings to be used as the menu options
* @param numString, the number of strings in the array
* @param width, the desired width of the menu
*/
void printMenu(const char * strings[], unsigned int numStrings, unsigned char width) {
	// first print width *'s followed by an endl
	cout << nCharString(width, '*') << endl;

	// Next, for each string s in the array:
	for (unsigned int i = 0; i < numStrings; ++i) {
		string itemNumber = to_string(i + 1); // Convert each int to a string
		string spacesBefore = nCharString(width - 7 - itemNumber.length() - strlen(strings[i]), ' '); // Calculate spaces before each item
		// cout a star, a space, the item Number a space a hyphen another space, and enough spaces to get to a length of width - 1
		// Close the line with a star and an endl.
		cout << "* " << itemNumber << " - " << strings[i] << spacesBefore << " *" << endl;  

		// Skip a line after each line except the last line
		if (i != numStrings - 1)  // Check if it's the last line
			cout << endl;
	}
	// outside the loop print another width *s followed by an endl
	cout << nCharString(width, '*') << endl;
}
/**
 * Gets menu choice 1 through maxChoice, inclusive
 *
 * @param maxChoice, maximum choice index, a number between 2 and 9, inclusive
 * @return the first legal choice input, could be 1 through maxChoice, inclusive
 */
unsigned int getMenuChoice(unsigned int maxChoice) {
	unsigned int userInput;  // Int representing the users choice
	bool validChoice = false;  // Loop control boolean 
	while (!validChoice) {
		cin >> userInput;  // Get user input
		if (userInput >= 1 && userInput <= maxChoice) {  // Check for input validity
			validChoice = true;  // End loop if valid choice
		}
	}
	return userInput;
}
/**
* Display the clocks
*
* @param h, hours 0 to 23
* @param m, minutes 0 to 59
* @param s, seconds 0 to 59
*/
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
	// cout 27 stars + 3 spaces + 27 stars + endl
	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
	// cout 1 star + 6 spaces + 12-HOUR CLOCK + 6 spaces + 1 star + 3 spaces
	cout << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*" << nCharString(3, ' ');
	// cout 1 star + 6 spaces + 24-HOUR CLOCK + 6 spaces + 1 star + endl
	cout << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl;
	// cout an endl for a blank line
	cout << endl;
	// cout 1 star + 6 spaces + formatTime12(h, m, s) + 7 spaces + 1 star + 3 spaces
	cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << "*" << nCharString(3, ' ');
	// cout 1 star + 8 spaces + formatTime24(h, m, s) + 9 spaces + 1 star + endl
	cout << "*" << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << "*" << endl;
	// cout 27 stars + 3 spaces + 27 stars + endl
	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}

int main() {
	int currHour;  // Int representing the current hour
	int currMin;  // Int representing the current minute
	int currSec;  // Int representing the current second
	bool exit = false;  // Loop control boolean
	const char* menuItems[] = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" };  // Array of menu options

	// Prompt user for the current time, store results in above variables
	cout << "What is the current hour?" << endl;
	cin >> currHour;
	cout << "What is the current minute?" << endl;
	cin >> currMin;
	cout << "What is the current second?" << endl;
	cin >> currSec;

	while (!exit) {  // Keep looping until user chooses to exit
		printMenu(menuItems, 4, 26);  // Print the menu at the start of each loop

		switch (getMenuChoice(4)) {  // Get menu choice
			case 1:  // Add an hour if 1 is selected
				addOneHour(currHour);  // Add hour
				displayClocks(currHour, currMin, currSec); // Display clocks
				break;
			case 2:  // Add a minute if 2 is selected
				addOneMinute(currHour, currMin);  // Add minute
				displayClocks(currHour, currMin, currSec);  // Display clocks
				break;
			case 3:  // Add a second if 3 is selected
				addOneSecond(currHour, currMin, currSec);  // Add second
				displayClocks(currHour, currMin, currSec);  // Display clocks
				break;
			case 4:  // Exit loop if 4 is selected
				exit = true;
				break;
			default:  // Display error if invalid selection (this should never happen)
				cout << "Invalid selection." << endl;	
		}
	}
}

