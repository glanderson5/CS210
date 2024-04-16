/*
 * main.cpp
 *
 *  Date: 6 April 2024
 *  Author: Greg Anderson
 */
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include "Account.h"
using namespace std;

/*
* Prompts user for banking details. 
* Always passes values to displayReports()
*/
void promptForValues(Account &acct) {
    double initialInvestment;  // Double representing the initial deposits
    double monthlyDeposit;  // Double representing the amount to be depositied each month
    double annualInterest;  // Double representing the annual interest rate
    int numberOfYears;  // Int representing the amount of years the money will be invested

    // Prompt user for initial investment amount
    cout << "Enter Initial Investment Amount: ";
    cin >> initialInvestment;
    acct.setInitialInvestment(initialInvestment);

    // Prompt user for monthly deposit amount
    cout << "Enter Monthly Deposit Amount: ";
    cin >> monthlyDeposit;
    acct.setMonthlyDeposit(monthlyDeposit);

    // Prompt user for annual interest rate
    cout << "Enter Annual Interest Rate (%): ";
    cin >> annualInterest;
    acct.setInterestRate(annualInterest);

    // Prompt user for number of years
    cout << "Enter Number of Years: ";
    cin >> numberOfYears;
    acct.setNumYears(numberOfYears);
}
int main() {
    Account userAccount;
    userAccount.displayAccountInfo();
    bool exit = false;
        while (!exit) {
            promptForValues(userAccount);
            userAccount.displayReports();
            char stop;
            cout << "Enter new values? (y/n)" << endl;
            cin >> stop;
            if (stop == 'n') {
                exit = true;
            }
        }
}