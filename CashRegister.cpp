/* ---------------------------------------------------------------------------------
    Thank you for your interest in software development at Ansys.

    As a rough gauge of your programming ability, we would like to see
    you deal with a relatively simple example. 

    Below is a C++ class that represents a cash register.  The public
    MakeChange method is intended to mimic the actions of the salesperson
    who has accepted money from the customer and must return the difference.

    Please implement that method.

    We are looking for the ability to define and implement an algorithm.
    Dealing with error conditions is important as is style and readability.

    Most of the details are irrelevant and should be unimportant.  But if you feel
    it improves your code, you may add utility methods as needed.
   --------------------------------------------------------------------------------- */
#include <map>
#include <string>
#include <iostream>



class CashRegister
{
public:
    CashRegister();
    ~CashRegister() {};

    // the customer has paid money,
    // that money is already in the till
    // Now, dispense change
    void MakeChange( double amountPaid, double amountOwed );
    void initialize();

private:

    // the cash register holds zero or more of these
    // bills and coins in the Till.
    // The value of the enum is its worth in cents
    enum denomination
    {
        kPenny = 1,
        kNickel = 5,
        kDime = 10,
        kQuarter = 25,
        kHalf = 50,
        kDollar = 100,
        kFive = 500,
        kTen = 1000,
        kTwenty = 2000,
        kFifty = 5000,
        kHundred = 10000
    };

    // This is the till.  All bills and coins are stored here
    std::map< denomination, int > mTill;

    // This is the LCD display on the cash register
    // std::ostream mDisplay;

private:

    // how much money is in the cash register?
    double TotalInRegister() const;

    // remove coins/bills from the till and give them to the customer
    void Dispense( denomination d, int count );

    // there is a problem!
    void ReportError( char *text ) const;

};

// -------------------------------------------------------
// Function:    CashRegister::CashRegister
// Purpose:     CashRegister Constructor
CashRegister::CashRegister()
{
    // mTill[ d ] = count;
}

// -------------------------------------------------------
// Function:    CashRegister::TotalInRegister
// Purpose:     how much money is in the cash register?

double CashRegister::TotalInRegister() const
{
    int total(0);
    std::map< denomination, int >::const_iterator it = mTill.begin();
    for ( ; it != mTill.end(); it++ )
        total += ((int) it->first) * it->second;
    return total / 100.0;
}

// -------------------------------------------------------
// Function:    CashRegister::Dispense
// Purpose:     remove coins/bills from the till and give them to the customer

void CashRegister::Dispense( denomination d, int count )
{
    mTill[ d ] -= count;
}

// -------------------------------------------------------
// Function:    CashRegister::ReportError
// Purpose:     there is a problem!

void CashRegister::ReportError( char *text ) const
{
    // show the problem on the display 
    // mDisplay << text;
    std::cout << text;
}

// -------------------------------------------------------

// ******************************
//     <insert your code here>
// ******************************

void CashRegister::MakeChange( double amountPaid, double amountOwed )
{

    using namespace std;
    string err = "Customer still needs to pay " + to_string(-amountOwed) + " to finish transaction";
    if (amountOwed < 0) ReportError("hehe");
    else if (amountOwed == 0) ReportError("Transaction done, no more changes");
    else {
        std::cout << "inside MakeChange function" << std::  endl;
        std::map< denomination, int >::const_iterator it = mTill.begin();
        for ( ; it != mTill.end(); it++ )
            cout << it->first << " has amount " << it->second << endl;

        // if (ChangeAvailable()) {

        // }
        // else {
        //     ReportError();
        //     Dispense(AmountPaid);
        // }
        
    }


}

void CashRegister::initialize() {
    mTill[kPenny] = 100;
    mTill[kNickel] = 200;
    mTill[kDime] = 300;
    mTill[kQuarter] = 400;
    mTill[kHalf] = 500;
    mTill[kDollar] = 600;
    mTill[kFive] = 700;
    mTill[kTen] = 800;
    mTill[kTwenty] = 900;
    mTill[kFifty] = 1000;
    mTill[kHundred] = 1100;
}