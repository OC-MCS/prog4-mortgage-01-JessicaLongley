// implementation file for Mortgage class
#include "Mortgage.h"
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

//CONSTRUCTORS
//this function initializes an empty loan with a defalt rate of .045
//Parameters: none
//returns: none
Mortgage::Mortgage()
{
    loan = 0;
    rate = 0;
    years = 1; //years is initialized to 1 to prevent undefined calculations
}

//this function initializes an empty loan with user amounts for the loan, rate, and year
//Parameters: none
//returns: none
Mortgage::Mortgage(double loanAmount, double rateAmount, int yearAmount)
{
    loan = loanAmount;
    rate = rateAmount / 100; //the user is likely to enter their rate amount as a perecnt not a decimal value
    years = yearAmount;
}

//this function this function allows the user to set their loan to any positive amount 
//Parameters: the amount they want to set the loan to
//returns: none
void Mortgage::setLoan(double amount)
{
        loan = amount;
}

//this function this function allows the user to set their rate to any positive amount 
//Parameters: the amount they want to set their rate to
//returns: none
void Mortgage::setRate(double amount)
{
        rate = amount;
}

//this function this function allows the user to set their years to any positive amount 
//Parameters: the amount they want to set their years to
//returns: none
void Mortgage::setYears(int time)
{
        years = time;
}

//this function calculates the monthly payment of the loan
//Parameters: none (local variables are used)
//returns: double of monthly payment amount
double Mortgage::getMonthlyPayment() const
{
    double term = pow((static_cast<double>(1) + (rate / 12)), (12 * years));
    double payment = (loan * (rate / 12) * term) / (term - 1);
    return payment;
}

//this function calculates the total payment at the end of the loan period
//Parameters: none (local variables are used)
//returns: double of total payment at the end of the loan period
double Mortgage::getPeriodPayment() const
{
    return getMonthlyPayment() * 12 * years;;
}