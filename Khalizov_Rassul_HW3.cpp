// Rassul Khalizov
// Homework 3, Part 1 
// October 20th

#include<iostream>
#include<fstream>
using namespace std;
#include<iomanip>
#include<string> 

int main()
{
    ifstream inData; 
    ofstream outData;
    double initial;
    double money;
    double credit;
    double debit;
    double transactions; 
    string WithdrawlorDeposit;

    inData.open("inData.txt"); //opens the file named inData.txt
    outData.open("outData.txt");  // opens the file named outData.txt

    cout<<"How much money does your bank account have at the start of the day?";
    cin >> initial; 

    cout<<"How many bank transactions have been done today?";
    cin >> transactions;

    credit = 0;
    debit = 0;
    
    while (transactions > 0)
    {
        cout<<"How much money is being transacted?";
        cin >> money; 

        cout << "What type of transaction is this: W or D?";
        cin >> WithdrawlorDeposit;

        if (WithdrawlorDeposit == ("D"))
        {
        initial = initial + money;

        transactions = transactions - 1; 

        credit = credit + money;

        cout << "You have " << initial << " dollars in the bank" << endl;

        }

        if (WithdrawlorDeposit == ("W"))
        {
        initial = initial - money;

        transactions = transactions - 1; 

        debit = debit - money;

        cout << "You have " << initial << " dollars in the bank" << endl;
        }
    }


    cout<<"You have " << initial << " dollars in the bank" << "and a total withdrawl amount of " << -debit << " and a total deposit amount of " << credit << endl;  
   
    return 0;

    /*
    How much money does your bank account have at the start of the day?100
How many bank transactions have been done today?3
How much money is being transacted?10 
What type of transaction is this: W or D?W
You have 90 dollars in the bank
How much money is being transacted?10
What type of transaction is this: W or D?D
You have 100 dollars in the bank
How much money is being transacted?1000
What type of transaction is this: W or D?D
You have 1100 dollars in the bank
You have 1100 dollars in the bankand a total withdrawl amount of 10 and a total deposit amount of 1010
    */
}
