#ifndef ACCOUNT_H
#define ACCOUNT_H
#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Account
{
public:
    // Constructor
    Account(double initialInvestment = 0.0, double monthlyDeposit = 0.0, double interestRate = 0.0, int numYears = 0)
        : initialInvestment(initialInvestment), monthlyDeposit(monthlyDeposit), interestRate(interestRate), numYears(numYears) {}

    // Getter methods
    double getInitialInvestment() const {
        return this->initialInvestment;
    }
    double getMonthlyDeposit() const {
        return this->monthlyDeposit;
    }
    double getInterestRate() const {
        return this->interestRate;
    }
    int getNumYears() const {
        return this->numYears;
    }

    // Setter methods
    void setInitialInvestment(double initialDeposit) {
        this->initialInvestment = initialDeposit;
    }
    void setMonthlyDeposit(double monthlyDeposit) {
        this->monthlyDeposit = monthlyDeposit;
    }
    void setInterestRate(double interestRate) {
        this->interestRate = interestRate;
    }
    void setNumYears(int numYears) {
        this->numYears = numYears;
    }

    string nCharStr(size_t n, char c) const;

    void displayAccountInfo() const;
    void displayReports() const;

private:
    double initialInvestment;
    double monthlyDeposit;
    double interestRate;
    int numYears;
    double roundTwoDigits(double value) const;
    void printDetails(int year, double balance, double interest) const;
    void calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) const;
    void calculateBalanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) const;
    void printMenu(const char* strings[], unsigned int numStrings, unsigned int width) const;
};
#endif