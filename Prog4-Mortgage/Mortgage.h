#pragma once
// header file for Mortgage class
class Mortgage
{
private:
    double payment; //the monthly payment
    double loan; //the dollar amount of the loan
    double rate; //the annual interest rate
    int years; //the number of years of the loan

public:
    //constructors
    Mortgage();
    Mortgage(double, double, int);

    //setting functions
    void setLoan(double);
    void setRate(double);
    void setYears(int);

    //getting functions
    double getMonthlyPayment() const;
    double getPeriodPayment() const;

};
