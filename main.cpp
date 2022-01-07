// Bank Management System
// Admin Panel
// Staff Panel
// ATM service

#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include "liList.h"
#include "AVL.h"

using namespace std;

class Account
{
public:
    Node *root = NULL;
    Node obj;
    TransactionActivity obj2;
    string fullName;
    int account_num;
    string cnic;
    string accType;
    char gender;
    int pin;
    float bal;
    int load = 0;

    void createAcc()
    {

        // srand(time(NULL));
        // pin = rand() % 10000;

        cout << "Enter Customer's Name" << endl;
        cin.ignore();
        getline(cin, fullName);

        cout << "Enter Gender(M/F)" << endl;
        cin >> gender;

        cout << "Enter Customer's NIC" << endl;
        cin.ignore();
        getline(cin, cnic);

        cout << "Enter Account Type(Current/Saving)" << endl;
        cin >> accType;

        load = obj.findMax(root);
        account_num = load + 1;

        cout << "Customer's Account Number is " << account_num << endl;

        cout << "Enter Customer's Pin" << endl;
        cin >> pin;
        cout << "Customer's Pin is " << pin << endl;

        cout << "Enter Balance" << endl;
        cin >> bal;

        root = obj.insertion(root, fullName, cnic, gender, accType, account_num, pin, bal);
        obj2.UserLogs(account_num);
    }
};

class AdminPanel : protected Account
{
public:
    int ch;
    int ch2;
    int check;
    string newName;
    int account_num1;
    int pin1;
    char gender1;
    string newaccType;
    string newNic;
    int newPin;

    void menu()
    {

        cout << "\t\tWelcome to the Admin Panel of the GIK Bank Management System" << endl;
        cout << endl;
        cout << endl;
        cout << "\tPress 1 to Create Account" << endl;
        cout << "\tPress 2 to Edit Existing Account" << endl;
        cout << "\tPress 3 to Search Existing Accounts" << endl;
        cout << "\tPress 4 to Delete Existing Accounts" << endl;
        cout << "\tPress 5 to Show List of Existing Accounts" << endl;
        cout << "\tPress 6 to Show List of Deleted Accounts" << endl;
        cout << "\tPress 7 to Go Back to Main Menu" << endl;
    }

    void choice()
    {
    jump2:
        system("CLS");
        menu();
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Welcome Admin. Kindly fill the following to Create a New Account. Kindly make sure that all the given information is legit." << endl;
            cout << endl;
            cout << endl;
            createAcc();

            cout << "You have successfully created an Account. Kindly welcome Mr/Mrs " << fullName << endl;

            cout << endl;
            cout << endl;

            cout << "If you want to add another Account. Press 1" << endl;
            cout << "To go back to the Admin Menu. Press 2" << endl;
            cin >> ch2;

            if (ch2 == 1)
            {
                createAcc();
                cout << endl;
                cout << endl;
                cout << "You have successfully created an Account. Kindly welcome Mr/Mrs " << fullName << endl;
                cout << endl;

                goto jump2;
            }

            if (ch2 == 2)
            {
                goto jump2;
            }

            break;

        case 2:
            cout << "Welcome to GIKI Bank Management System's Editing Section. You can edit the existing account details in this section" << endl;

            cout << endl;
            cout << endl;

            cout << "Enter User's Account Number" << endl;
            cin >> account_num1;

            cout << "Enter User's Pin" << endl;
            cin >> pin1;

            check = obj.checkPin(root, account_num1, pin1);

            if (check == 1)
            {
                cout << "User Found" << endl;

                cout << "Enter Name" << endl;
                cin.ignore();
                getline(cin, newName);

                cout << "Enter CNIC" << endl;
                cin.ignore();
                getline(cin, newNic);

                cout << "Enter Gender" << endl;
                cin >> gender1;

                cout << "Enter Account Type" << endl;
                cin >> newaccType;

                cout << "Enter Pin" << endl;
                cin >> newPin;

                obj.Edit(root, newName, newNic, gender1, newaccType, account_num1, newPin);
                cout << endl;
                cout << "Account Information Changed" << endl;

                goto jump2;
            }
            else if (check == -1)
            {
                cout << "Wrong Pin" << endl;
                goto jump2;
            }
            break;
        case 3:
            cout << "Welcome to GIKI Bank Management System's Searching Page" << endl;
            cout << endl;
            cout << endl;

            cout << "Enter the Account Number to search" << endl;
            cin >> account_num1;

            check = obj.search(root, account_num1);
            if (check == 1)
            {
                cout << "User Found" << endl;
                cout << endl;
                cout << endl;
                obj.display(root, account_num1);
                goto jump2;
            }
            else if (check == 2)
            {
                cout << "User Not Found" << endl;
                goto jump2;
            }
            break;
        case 4:
            cout << "Welcome to GIKI Bank Management System Deletion Page. You can delete an user from this console. Kindly Enter the coorect Account Number" << endl;
            cout << endl;

            cout << "Enter Account Number" << endl;
            cin >> account_num1;

            check = obj.search(root, account_num1);

            if (check == 1)
            {
                cout << "User Found" << endl;
                cout << endl;
                // obj.display(root, account_num1);

                cout << endl;
                cout << endl;

                obj.deletion(root, account_num1);
                cout << "User Account deleted" << endl;
                system("PAUSE");
                goto jump2;
            }
            else if (check == 2)
            {
                cout << "User Not Found" << endl;
                goto jump2;
            }
            break;
        case 5:
            cout << "Welcome to GIKI Bank Management. You can view all the existing Accounts from here" << endl;
            cout << endl;
            obj.AdminDisplay(root);
            system("PAUSE");
            goto jump2;
            break;
        case 6:
            cout << "Welcome to GIKI Bank Management.You can view all the deleted Accounts from here" << endl;
            cout << endl;
            cout << "Enter Account Number" << endl;
            cin >> account_num1;

            check = obj2.display1(account_num1);
            obj.display(root, account_num1);

            if (check == 1)
            {
                obj2.display(account_num1);
                goto jump2;
            }
            else
            {
                obj2.display(account_num1);
                goto jump2;
            }
            break;
        case 7:
            system("PAUSE");
            cout << "Press Enter to Go Back to Main Menu" << endl;
            goto jump2;
            break;
        }
    }
};

class ATM : protected AdminPanel
{
public:
    int ch3;
    int amount;
    int result;
    void atmMenu()
    {
        cout << "\tWelcome to GIKI Bank Management System's ATM" << endl;

        cout << endl;
        cout << endl;

        cout << "\t Press 1 to Deposit Cash" << endl;
        cout << "\t Pres 2 to Exit ATM" << endl;
        cin >> ch3;

        switch (ch3)
        {
        case 1:
            cout << "Enter Account Number" << endl;
            cin >> account_num1;

            cout << "Enter Pin" << endl;
            cin >> pin1;

            cout << "Your Account Information" << endl;
            obj.display(root, account_num1);
            cout << endl;
            cout << endl;
            cout << "Enter the Amount to Withdraw" << endl;
            cin >> amount;

            result = obj.withdraw(root, account_num1, pin1, amount);

            if (result == 1)
            {
                cout << "Cash Withdrawn" << endl;

                obj.display(root, account_num1);
            }
            else if (result == -1)
            {
                cout << "You Dont Have Enough Balance" << endl;
            }
            else if (result == -2)
            {
                cout << "You entered the wrong PIN" << endl;
                exit(0);
            }

        case 2:
            exit(0);
        }
    }
};

class Interface : protected ATM
{
public:
    int ch5;
    string password = "112233";
    string pw;
    void frontPage()
    {
        cout << "\t\tWelcome to GIKI Bank Management System" << endl;
        cout << "\t Created By: Abdul Rehman" << endl;
        cout << "\tRegistration Number: 2020015" << endl;
        system("PAUSE");
        system("CLS");
    }

    void choice()
    {
        cout << "Press 1 To Enter Admin Panel " << endl;
        cout << "Press 2 for ATM" << endl;
        cin >> ch5;
        system("PAUSE");
        system("CLS");

        switch (ch5)
        {
        case 1:
            cout << "Enter Password" << endl;
            cin >> pw;

            if (pw != password)
            {
                cout << "Wrong Password" << endl;
                exit(0);
            }
            break;
        case 2:
            atmMenu();
        }
    }
};

int main()
{
    Interface intro;
    AdminPanel obj;

    intro.frontPage();
    intro.choice();
    system("CLS");

    obj.menu();
    system("CLS");
    obj.choice();

    return 0;
}