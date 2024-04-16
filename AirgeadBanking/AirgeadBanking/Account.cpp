#include "Account.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

string Account::nCharStr(size_t n, char c) const {
    string charString = "";
    for (int i = 0; i < n; ++i) {
        charString += c;
    }
    return charString;
}
void Account::displayAccountInfo() const
{
    const char* menuItems[] = { "Initial Investment Amount: ", "Monthly Deposit: ", "Annual Interest: ", "Number of Years: " };  // Array of menu options

    // Display acct info using printMenu as helper
    cout << "*" << nCharStr(40, '-') << "*" << endl;
    cout << "************   Account Info   ************" << endl;
    printMenu(menuItems, 4, 42);
    cout << endl;
    cout << "Press enter to continue. . ." << endl;
    cin.get(); // Wait for any user input
}
void Account::displayReports() const
{
 // Prints a formatted header for the report with no deposits.
        cout << endl;
        cout << nCharStr(51, '*') << endl;
        cout << "***" << nCharStr(5, ' ') << "Balance and Interest (No Deposits)" << nCharStr(6, ' ') << "***" << endl;
        cout << nCharStr(51, '*') << endl;
        cout << "|   " << "Year" << nCharStr(13, ' ') << "Balance" << nCharStr(13, ' ') << "Interest" << " |" << endl;
        cout << "*" << nCharStr(49, '-') << "*" << endl;
        // Print table values
        calculateBalanceWithoutMonthlyDeposit(initialInvestment, interestRate, numYears);
        cout << "*" << nCharStr(49, '-') << "*" << endl;
        cout << endl; // Last line to close table
        // Prints a formatted header for the monthly deposits report
        cout << nCharStr(51, '*') << endl;
        cout << "***" << nCharStr(5, ' ') << "Balance and Interest (With Deposits)" << nCharStr(4, ' ') << "***" << endl;
        cout << nCharStr(51, '*') << endl;
        cout << "|   " << "Year" << nCharStr(13, ' ') << "Balance" << nCharStr(13, ' ') << "Interest" << " |" << endl;
        cout << "*" << nCharStr(49, '-') << "*" << endl;
        // Print table values
        calculateBalanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, interestRate, numYears);
        cout << "*" << nCharStr(49, '-') << "*" << endl;
        cout << endl;  // Finish table;
}
double Account::roundTwoDigits(double value) const
{
    value = round(value * 100.0) / 100.0;
    return value;
}
void Account::printDetails(int year, double balance, double interest) const
{
    int lengthYear = to_string(year).length();
    int lengthBalance = to_string(balance).length();
    int lengthInterest = to_string(interest).length();
    cout << "|" << nCharStr(5 - lengthYear, ' ') << year << nCharStr(25 - lengthBalance, ' ')
        << setprecision(2) << fixed << balance << nCharStr(25 - lengthInterest, ' ')
        << setprecision(2) << fixed << interest << "  |" << endl;
}
void Account::calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) const
{
    double balance = initialInvestment;  // initial balance is original investment
    
    // Loop for numberOfYears years
    for (int year = 1; year <= numberOfYears; ++year) {
        // Calculate the balance at the end of the year using the compound interest formula
        double finalBalance = balance * pow(1 + (interestRate / 100), year);
        // Calculate the balance at the beginning of the year
        double beginningBalance = balance * pow(1 + (interestRate / 100), year - 1);
        // Calculate the interest earned for the current year
        double yearlyInterestEarned = finalBalance - beginningBalance;
        // Print details for the current year
        printDetails(year, roundTwoDigits(finalBalance), roundTwoDigits(yearlyInterestEarned));
    }
}
void Account::calculateBalanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) const
{
    double balance = initialInvestment;  // Set initial balance to the initial investment

    // Loop for numberOfYears years
    for (int year = 1; year <= numberOfYears; ++year) {
        double yearlyInterestEarned = 0.0;  // Track yearly interest
        // Loop through each month of the year
        for (int month = 1; month <= 12; ++month) {
            // Add monthly deposit to the balance
            balance += monthlyDeposit;
            // Calculate interest earned for the current month
            double interestEarnedThisMonth = balance * (interestRate / 100 / 12);
            // Add interest to the balance
            roundTwoDigits(interestEarnedThisMonth);
            balance += interestEarnedThisMonth;
            // Update total interest earned
            yearlyInterestEarned += interestEarnedThisMonth;
        }
        // Print details at the end of each iteration of year loop
        printDetails(year, roundTwoDigits(balance), roundTwoDigits(yearlyInterestEarned));
    }
}
void Account::printMenu(const char* strings[], unsigned int numStrings, unsigned int width) const
{
    // first print width *'s followed by an endl
    cout << "*" << nCharStr(width - 2, '-') << "*" << endl;
    cout << "|" << nCharStr(40, ' ') << "|" << endl; // skip a line
    // for each string s in the array:
    for (unsigned int i = 0; i < numStrings; ++i) {

        string spacesBefore = nCharStr(width - 3 - strlen(strings[i]), ' '); // Calculate spaces before each item
        // cout a star, a space, the menu text, and enough spaces to get to a length of width - 1
        // Close the line with a star and an endl.
        cout << "| " << strings[i] << spacesBefore << "|" << endl;
        cout << "|" << nCharStr(40, ' ') << "|" << endl; // skip a line
    }
    // outside the loop print another width *s followed by an endl
    cout << "*" << nCharStr(width - 2, '-') << "*" << endl;
}
