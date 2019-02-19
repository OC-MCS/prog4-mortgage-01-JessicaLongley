//=============================
//Jessica Longley
//20 FEB 2019
//Programming Assignment #4
//Description: Mortgage Payment
//=============================
#include <iostream>
#include <iomanip>
#include "Mortgage.h"
#include <string>
using namespace std;

//prototypes
double validateLoanRate(string input);
int validateYear(string input);
bool parseDouble(string input, double& fill);
bool parseInt(string input, int& fill);

int main()
{
    //demonstrate initializing the object member types one by one
    Mortgage m1;
    m1.setLoan(90);
    m1.setRate(.012);
    m1.setYears(4);

    cout << "The monthly payment of loan is: " << fixed << setprecision(2) << m1.getMonthlyPayment() << endl;
    cout << "The period payment of loan is: " << m1.getPeriodPayment() << endl << endl;

    //demonstrate initializing the object member types all at once
    Mortgage m2(1000, .014, 5);
    cout << "The monthly payment of loan is: $" << m2.getMonthlyPayment() << endl;
    cout << "The period payment of loan is: $" << m2.getPeriodPayment() << endl << endl;

    //demonstrate initializing the object member types using standard input
    double loan, rate;
    int years;
    string input;
    cout << "Enter loan amount: " << endl;
    getline(cin, input);
    loan = validateLoanRate(input);
    cout << "Enter rate (percentage, not decimal): "<< endl;
    getline(cin, input);
    rate = validateLoanRate(input);
    cout << "Enter years: " << endl;
    getline(cin, input);
    years = validateYear(input);
    Mortgage m3(loan, rate, years);

    cout << endl << "The monthly payment of loan is: $" << m3.getMonthlyPayment() << endl;
    cout << "The period payment of loan is: $" << m3.getPeriodPayment() << endl << endl;
    return 0;
}

//this fucntion checks any double to make sure that it is a positive value
//Parameters: the number being checked
//returns: bool( true if positive)
double validateLoanRate(string input)
{
    double num; 

    while (!parseDouble(input, num))
    {
        cout << " Invalid input. Please enter a number: ";
        getline(cin, input);

        cout << endl;
    }
    while (num < 0)
    {
        cout << " Invalid input. Please enter a positive number: ";
        getline(cin, input);
        parseDouble(input, num);
    }

    return num;
}

//this private fucntion checks any int(the years) to make sure that it is a positive value
//Parameters: the number being checked
//returns: bool( true if positive)
int validateYear(string input)
{
    int num;
    while (!parseInt(input, num))
    {
        cout << " Invalid input. Please enter a number: ";
        getline(cin, input);

        cout << endl;
    }
    while (num < 0)
    {
        cout << " Invalid input. Please enter a positive number: ";
        getline(cin, input);
        parseInt(input, num);
    }
    return num;
}

//function parseFloat validates double imput is a float
//parameters: string input is the amount entered as a string, 
//            double passed by reference is the number being filled with the correct double value
//returns: bool, true or false is the input is valid or not
bool parseDouble(string input, double& fill)
{
    double num;
    bool success = true;
    try
    {
        num = stod(input);   // changes string to double
        fill = num;          // fills pass by refference float with the input
    }
    catch (const std::exception&)
    {
        success = false;
    }
    return success;
}
//function parseInt validates float imput is a float
//parameters: string input is the amount entered as a string, 
//            int passed by reference is the number being filled with the correct int value
//returns: bool, true or false is the input is valid or not
bool parseInt(string input, int& fill)
{
    int num;
    bool success = true;
    try
    {
        num = stoi(input);   // changes string to int
        fill = num;          // fills pass by refference int with the input
    }
    catch (const std::exception&)
    {
        success = false;
    }
    return success;
}