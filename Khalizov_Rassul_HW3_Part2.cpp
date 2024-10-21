// Rassul Khalizov
// Homework 3, Part 2
// October 20th 

#include<iostream>
#include<fstream>
using namespace std;
#include<iomanip>
#include<string> 

int main()
{
    // labels data type
    ifstream inData; 
    ofstream outData;
    double initial;
    double money;
    double credit;
    double debit;
    double totalwithdrawls, totaldeposits; 
    string WithdrawlorDeposit;

    inData.open("inData.txt"); //opens the file named inData.txt
    outData.open("outData.txt");  // opens the file named outData.txt

    cout << fixed << showpoint; // keeps the decimal values constant 

    // credit, debit, totalwithdrawls, totaldeposits start at 0
    credit = 0;
    debit = 0;
    totalwithdrawls = 0;
    totaldeposits = 0; 

    // Makes it so that the first line in the inData.txt prints out that value in the outData.txt
    inData >> initial;  
    outData << "STARTING BALANCE: $ " << fixed << setprecision(2) << initial << endl;
    
    outData << "TYPE......AMOUNT....................BALANCE" << endl;

    while (!inData.eof())
    {
        // The input from inData.txt is used and gets runned through the if statements 
        inData >> WithdrawlorDeposit >> money; 

        if (WithdrawlorDeposit == ("D"))
        {
        /* if the string Withdrawl or Deposit is D or deposit, the if statement gets the bank balance after the transaction,
        the total credit amount, the total deposits, and finally prints those values out
        */
        initial = initial + money;

        credit = credit + money;

        totaldeposits = totaldeposits + 1; 

        outData << "D" << setw(10) << setfill('.') << money << setw(30) << setfill('.') << initial << endl;

        }

        if (WithdrawlorDeposit == ("W"))
        {
        /* if the string Withdrawl or Deposit is W or withdrawl, the if statement gets the bank balance after the transaction,
        the total debit amount, the total withdrawls, and finally prints those values out
        */
        initial = initial - money;

        debit = debit - money;

        totalwithdrawls = totalwithdrawls + 1; 

        outData << "W" << setw(10) << setfill('.') <<  money << setw(30) << setfill('.') << initial << endl;
        }
    }
    // Prints out the final values of all the variables in a neat format

    outData << "ENDING BALANCE: $" << setprecision(2) << initial << endl; 
    outData << "TOTAL WITHDRAWALS: $" << setprecision(2) << -debit << endl; 
    outData << "TOTAL DEPOSITS: $" << setprecision(2) << credit << endl; 
    outData << "number of deposits: " << totaldeposits << endl; 
    outData << "number of withdrawls: " << totalwithdrawls << endl; 
   
    return 0;
}
