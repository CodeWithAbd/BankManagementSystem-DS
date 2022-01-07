#include <iostream>
using namespace std;

//Linked List is used to mantain logs of User Transactions

class Transactions
{
public:
    string data;
    Transactions *ptr;
};

class TransactionActivity
{
public:
    int AccountNumber;
    TransactionActivity *Next;

    Transactions *ptr;

    TransactionActivity *head = NULL;

    void UserLogs(int accountNumber)
    {
        TransactionActivity *newNode = new TransactionActivity;
        TransactionActivity *temp = NULL;
        TransactionActivity *temp2 = NULL;

        if (head != NULL)
        {
            for (temp2 = head; temp2->Next = NULL; temp2 = temp2->Next)
            {
            }
            temp = new TransactionActivity;
            temp->AccountNumber = accountNumber;
            temp2->Next = temp;
            temp->Next = NULL;
            temp->ptr = NULL;
        }
        else
        {
            newNode->AccountNumber = accountNumber;
            newNode->Next = NULL;
            newNode->ptr = NULL;
            head = newNode;
        }
    }

    void logInsertion(int number, string num)
    {
        Transactions *temp = new Transactions;
        Transactions *newNode = new Transactions;
        TransactionActivity *temp2 = new TransactionActivity;
        newNode->data = num;
        newNode->ptr = NULL;

        for (temp2 = head; temp2 != NULL; temp2 = temp2->Next)
        {
            if (temp2->AccountNumber == number)
            {
                if (temp2->ptr == NULL)
                {
                    temp2->ptr == newNode;
                    newNode->ptr = NULL;
                }
                else
                {
                    temp = temp2->ptr;
                    temp2->ptr = newNode;
                    newNode->ptr = temp;
                }
            }
        }
    }

    int display(int Accnum)
    {
        TransactionActivity *temp = new TransactionActivity;
        Transactions *temp2 = new Transactions;

        if (head != NULL)
        {
            for (temp = head; temp != NULL; temp = temp->Next)
            {
                if (temp->AccountNumber == Accnum)
                {
                    for (temp2 = temp->ptr; temp2 != NULL; temp2 = temp2->ptr)
                    {
                        cout << temp2->data << endl;
                    }
                }
                break;
                return 1;
            }
        }
        else
        {
            return 0;
        }
    }

    int display1(int Accnum)
    {
        TransactionActivity *temp = new TransactionActivity;
        Transactions *temp2 = new Transactions;

        if (head != NULL)
        {
            for (temp = head; temp != NULL; temp = temp->Next)
            {
                if (temp->AccountNumber == Accnum)
                {
                    for (temp2 = temp->ptr; temp2 != NULL; temp2 = temp2->ptr)
                    {
                        temp2->data;
                    }
                }
                return 1;
            }
        }
        else
        {
            return 0;
        }
    }
};