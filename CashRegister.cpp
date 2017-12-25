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
    void ReportError( const char *text ) const;

    // Depth first search for available change combination.
    bool ChangeAvailable( int amountOwed, const denomination unit[],
                          int solution[], const int UNIT_SIZE, int cur);
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

void CashRegister::ReportError( const char *text ) const
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
    std::string err_msg;    // Error Message

    // Customer owe money to the register.
    if (amountOwed < 0.0) {
        err_msg = "You still need to pay $" + 
                  std::to_string(-amountOwed) + ".\n";
        ReportError(err_msg.c_str());
    }
    // Transaction is clear.
    else if (amountOwed == 0.0) {
        err_msg = "Transaction is complete, no more changes.\n";
        ReportError(err_msg.c_str());
    }
    // Dispense changes.
    else {
        // Convert dollar to penny, ignore amount less than penny.
        int amountOwedInt = amountOwed * 100;

        // Solution array.
        const int UNIT_SIZE(11);
        int solution[UNIT_SIZE] = {0};
        denomination unit[UNIT_SIZE] = 
            {kPenny, kNickel, kDime, kQuarter, kHalf, 
             kDollar, kFive, kTen, kTwenty, kFifty, kHundred};
        
        // If able to make changes, dispense the amount accordingly. 
        if (ChangeAvailable(amountOwedInt, unit, 
            solution, UNIT_SIZE, UNIT_SIZE-1)) 
        {
            for (int i = 0; i < UNIT_SIZE; i++) {
                Dispense(unit[i], solution[i]);
            }
        }
        // If not able to make changes, refund the paid amount.
        else {
            err_msg = "Not enough changes in the till, you get refund.\n";
            ReportError(err_msg.c_str());
            MakeChange(0, amountPaid);
        }
    }
}

bool CashRegister::ChangeAvailable
(int amountOwed, const denomination unit[], 
 int solution[], const int UNIT_SIZE, int cur)
{
    // Current denomination.
    const denomination denom = unit[cur];

    // The amount is already clear, return.
    if (amountOwed == 0) {
        return true;
    }

    // Boundary condition.
    else if (cur == 0) {
        // Penny can clear all the due amount.
        if (mTill[denom] >= amountOwed) {
            solution[cur] = amountOwed;
            return true;
        }
        // Penny not enough. 
        else {
            return false;
        }
    }

    // Due amount can be cleared by current bill.
    if (amountOwed % denom == 0 && 
        mTill[denom] >= amountOwed / denom) 
    {
        solution[cur] = amountOwed / denom;
        return true;
    }

    // Due amount needs to be cleared with smaller bill.
    else {
        int maxNum = std::min(mTill[denom], amountOwed / denom);

        for (int i = maxNum; i >= 0; i--) {
            if (ChangeAvailable(amountOwed - denom * i, 
                unit, solution, UNIT_SIZE, cur - 1)) 
            {
                solution[cur] = i;
                return true;
            }
        }
    }

    return false;
}

void CashRegister::initialize() {
    mTill[kPenny] = 4;
    mTill[kNickel] = 0;
    mTill[kDime] = 3;
    mTill[kQuarter] = 1;
    mTill[kHalf] = 500;
    mTill[kDollar] = 600;
    mTill[kFive] = 700;
    mTill[kTen] = 800;
    mTill[kTwenty] = 900;
    mTill[kFifty] = 1000;
    mTill[kHundred] = 1100;
}