// BUDGET2.CPP - Budget Program in the "C++ as a better C" version.

using namespace std;

#include <iostream>

// the maximum amount you can have 
const int maxAccounts = 10;

//Checking - this describes Checking accounts
struct Checking
{
    unsigned accountNumber;
    float    balance;
} chkAcnts[maxAccounts];

//Savings - you can probably figure this one out
struct Savings 
{
    unsigned accountNumber;
    float    balance;
    int      noWithdrawals;
} svgAcnts[maxAccounts];

//prototype declarations
void process(Checking &checking); //Note 1
void process(Savings &savings); 

// inline functions
// init(Checking) - initialize a checking account
inline void init(Checking &checking) // Note 2
{
    cout << "Enter account number:";
    cin  >> checking.accountNumber;
    checking.balance = 0.0;
}

// init(Saving) - initialize a saving account
inline void init(Savings &savings) // Note 2
{
    cout << "Enter account number:";
    cin  >> savings.accountNumber;
    savings.balance = 0.0;
    savings.noWithdrawals = 0;
}

// main - accumulate the initial input and output totals
int main()
{
    // loop until someone enters an 'X' or 'x'
    int noChkAccounts = 0; // count the number of accounts
    int noSvgAccounts = 0; // 
    char     accountType;  // S or C

    unsigned keepLooping = 1;
    while (keepLooping)
    {
        cout << "Enter S for Savings, "
                "C for Checking, X for exit\n";
        cin >> accountType;
        switch (accountType)
        {
            case 'c':
            case 'C':
                if (noChkAccounts < maxAccounts)
                {
                    init(chkAcnts[noChkAccounts]);
                    process(chkAcnts[noChkAccounts]);
                    noChkAccounts++;
                }
                else
                {
                    cout << "No more room for checking accounts\n";
                }
                break;

            case 's':
            case 'S':
                if (noSvgAccounts < maxAccounts)
                {
                    init(svgAcnts[noSvgAccounts]);
                    process(svgAcnts[noSvgAccounts]);
                    noSvgAccounts++;
                }
                else
                {
                    cout << "No more room for savings accounts\n";
                }
                break;

            case 'x':
            case 'X':
                keepLooping = 0;
                break;

            default:
                cout << "I didn't get that.\n";
        }
    }

    // now present totals;
    float chkTotal = 0; // total of all checking accounts
    cout << "Checking Accounts:\n";
    for (int i = 0; i < noChkAccounts; i++) // NOTE 3
    {
        cout << "Accounts " << chkAcnts[i].accountNumber
            << " = "        << chkAcnts[i].balance
            << "\n";
        chkTotal += chkAcnts[i].balance;
    }

    float svgTotal = 0; // total of all saving accounts
    cout << "Savings accounts:\n";
    for (int i = 0; i < noSvgAccounts; i++) // NOTE 4
    {
        cout << "Account "            << svgAcnts[i].accountNumber
            << " = "                  << svgAcnts[i].balance
            << " (no. withdrawals = " << svgAcnts[i].noWithdrawals
            << ")\n";
        svgTotal += svgAcnts[i].balance;
    }

    float total = chkTotal + svgTotal;
    cout << "Total for checking accounts = " << chkTotal << "\n";
    cout << "Total for savings accounts  = " << svgTotal << "\n";
    cout << "Total worth                 = " << total << "\n";
    return 0;
}

//process(Checking ) - input the data for a checking account
void process(Checking &checking)
{
    cout << "Enter positive number for deposit,\n"
            "negative for check, 0 to terminate";

    float transaction;
    do
    {
        cout << ": ";
        cin  >> transaction;

        //is it a deposit
        if (transaction > 0)
        {
            checking.balance += transaction;
        }

        //how about withdrawal
        if (transaction < 0)
        {
            //withdrawal
            transaction = -transaction;
            if (checking.balance < transaction) // NOTE 5
            {
                cout << "Insufficient funds: balance "
                     << checking.balance
                     << ", check "
                     << transaction
                     << "\n";
            }
            else
            {
                checking.balance -= transaction;

                //if balance falls too slow, charge service fee
                if (checking.balance < 500.00F)
                {
                    checking.balance -= 0.20F;
                }
            }
        }
    } while (transaction != 0);
}

//process(Savings ) - input the data for a savings account
void process(Savings &savings)
{
    cout << "Enter positive number for deposit,\n"
            "negative for withdrawal, 0 to terminate";

    float transaction;
    do
    {
        cout << ": ";
        cin  >> transaction;

        //is it a deposit
        if (transaction > 0)
        {
            savings.balance += transaction;
        }

        //is this a withdrawal
        if (transaction < 0)
        {
            transaction = -transaction;
            if (savings.balance < transaction) // NOTE 5
            {
                cout << "Insufficient funds: balance "
                     << savings.balance
                     << ", withdrawal "
                     << transaction
                     << "\n";
            }
            else
            {
                if (++savings.noWithdrawals > 1)
                {
                    savings.balance -= 5.00F;
                }
                savings.balance -= transaction;
            }
        }
    } while (transaction != 0);
}

