#include <iostream>
using namespace std;

class Node
{
public:
    string Name;
    string nic;
    string Type;
    char Gender;
    int AccNumber;
    int pin;
    float balance;

    Node *left;
    Node *right;
    int height;
    int leftHeight;
    int rightHeight;

    Node *temp = NULL;
    Node *temp1 = NULL;
    Node *temp2 = NULL;
    Node *temp3 = NULL;

    int max(int x, int y)
    {
        if (y > x)
        {
            return y;
        }
        else
        {
            return x;
        }
    }

    Node *min(Node *temp)
    {
        if (temp == NULL)
        {
            return 0;
        }
        if (temp->left == NULL)
        {
            return temp;
        }
        else
        {
            min(temp->left);
        }
    }

    int Height(Node *temp)
    {
        if (temp == NULL)
        {
            return 0;
        }
        leftHeight = Height(temp->left);
        rightHeight = Height(temp->right);

        if (rightHeight > leftHeight)
        {
            return rightHeight + 1;
        }
        else
        {
            return leftHeight + 1;
        }
    }

    Node *leftRotaion(Node *temp2)
    {
        temp1 = temp2->right;
        temp2->right = temp1->left;
        temp1->left = temp2;

        temp2->height = max(Height(temp2->left), Height(temp2->right)) + 1;
        temp1->height = max(Height(temp1->left), Height(temp1->right)) + 1;
        return temp1;
    }

    Node *rightRotaion(Node *temp2)
    {
        temp1 = temp2->left;
        temp2->left = temp1->right;
        temp1->right = temp2;

        temp2->height = max(Height(temp2->left), Height(temp2->right)) + 1;
        temp1->height = max(Height(temp1->left), Height(temp1->right)) + 1;

        return temp1;
    }

    Node *rightLeftRotation(Node *temp3)
    {
        temp3->right = rightRotaion(temp3->right);
        return leftRotaion(temp3);
    }

    Node *leftRightRotation(Node *temp3)
    {
        temp3->left = leftRotaion(temp3->left);
        return rightRotaion(temp3);
    }

    Node *Balance(Node *temp)
    {
        if (temp == NULL)
        {
            cout << "No Rotation Found" << endl;
        }
        if (Height(temp->left) - Height(temp->right) > 1)
        {
            if (Height(temp->left->left) >= Height(temp->left->right))
            {
                temp = rightRotaion(temp);
            }
        }
        else
        {
            temp = leftRightRotation(temp);
        }
        if (Height(temp->right) - Height(temp->left) > 1)
        {
            if (Height(temp->right->right) >= Height(temp->right->left))
            {
                temp = leftRotaion(temp);
            }
            else
            {
                temp = rightLeftRotation(temp);
            }
        }
        temp->height = max(Height(temp->left), Height(temp->right)) + 1;
        return temp;
    }

    Node *insertion(Node *temp, string name, string NIC, char Gen, string type, int AccNum, int PIN, int bal)
    {
        if (temp == NULL)
        {
            temp = new Node();
            temp->left = NULL;
            temp->right = NULL;
            temp->height = 0;
            temp->Name = name;
            temp->nic = NIC;
            temp->Gender = Gen;
            temp->Type = type;
            temp->AccNumber = AccNum;
            temp->pin = PIN;
            temp->balance = bal;
        }

        if (AccNum > temp->AccNumber)
        {
            temp->right = insertion(temp->right, name, NIC, Gen, type, AccNum, PIN, bal);
            if (Height(temp->right) - Height(temp->left) == 2)
            {
                if (AccNum > temp->right->AccNumber)
                {
                    temp = leftRotaion(temp);
                }
                else
                {
                    temp = rightLeftRotation(temp);
                }
            }
        }
        if (AccNum < temp->AccNumber)
        {
            temp->left = insertion(temp->left, name, NIC, Gen, type, AccNum, PIN, bal);
            if (Height(temp->left) - Height(temp->right) == 2)
            {
                if (AccNum < temp->left->AccNumber)
                {
                    temp = rightRotaion(temp);
                }
                else
                {
                    temp = leftRotaion(temp);
                }
            }
        }
        temp->height = max(Height(temp->left), Height(temp->right)) + 1;
        return temp;
    }

    Node *deletion(Node *temp, int x)
    {
        if (temp == NULL)
        {
            return temp;
        }
        else if (x > temp->AccNumber)
        {
            temp->right = deletion(temp->right, x);
        }
        else if (x < temp->AccNumber)
        {
            temp->left = deletion(temp->left, x);
        }
        else if (temp->right && temp->left)
        {
            temp3 = min(temp->right);
            temp->AccNumber = temp3->AccNumber;
            temp->right = deletion(temp->right, temp->AccNumber);
        }
        else
        {
            temp3 = temp;
            if (temp->left == NULL)
            {
                temp = temp->right;
            }
            else if (temp->right == NULL)
            {
                temp = temp->left;
            }
            delete temp3;
        }
        if (temp != NULL)
        {
            temp = Balance(temp);
        }
    }

    int findMax(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int res = root->AccNumber;
        int lres = findMax(root->left);
        int rres = findMax(root->right);
        if (lres > res)
        {
            res = lres;
        }
        if (rres > res)
        {
            res = rres;
        }
        return res;
    }

    bool search(Node *temp, int x)
    {
        do
        {
            if (x < temp->AccNumber)
            {
                temp = temp->left;
            }
            else if (x > temp->AccNumber)
            {
                temp = temp->right;
            }
            else
            {
                return true;
            }
        } while (temp != NULL);

        if (temp == NULL)
        {
            return false;
        }
    }

    void inOrder(Node *temp)
    {
        if (temp->left != NULL)
        {
            inOrder(temp->left);
        }

        cout << temp->Name;
        cout << temp->nic;
        cout << temp->AccNumber;
        cout << temp->Gender;
        cout << temp->Type;
        cout << temp->balance;

        if (temp->right != NULL)
        {
            inOrder(temp->right);
        }
    }

    int display(Node *temp, int x)
    {
        if (temp == NULL)
        {
            return false;
        }
        else if (temp != NULL)
        {
            if (x < temp->AccNumber)
            {
                temp = temp->left;
            }
            else if (x > temp->AccNumber)
            {
                temp = temp->right;
            }
            else
            {
                cout << AccNumber;
                cout << Name;
                cout << nic;
                cout << Gender;
                cout << Type;
                cout << balance;
                // return true;
            }
        }
        
    }

    void AdminDisplay(Node *temp)
    {
        if (temp->left != NULL)
        {
            AdminDisplay(temp->left);
        }

        cout << temp->Name << endl;
        cout << temp->nic << endl;
        cout << temp->AccNumber << endl;
        cout << temp->Gender << endl;
        cout << temp->Type << endl;
        cout << temp->balance << endl;

        if (temp->right != NULL)
        {
            AdminDisplay(temp->right);
        }
    }

    int Edit(Node *temp, string name, string NIC, char Gen, string type, int AccNum, int PIN)
    {
        while (temp != NULL)
        {
            if (AccNum > temp->AccNumber)
            {
                temp = temp->right;
            }
            else if (AccNum < temp->AccNumber)
            {
                temp = temp->left;
            }
            else
            {
                if (temp->AccNumber == AccNum)
                {
                    temp->Name = name;
                    temp->nic = NIC;
                    temp->Gender = Gen;
                    temp->pin = PIN;
                    temp->Type = type;
                }

                return 1;
            }
        }
        return 0;
    }

    int checkPin(Node *temp, int AccNum, int PIN)
    {
        while (temp != NULL)
        {
            if (AccNum > temp->AccNumber)
            {
                temp = temp->right;
            }
            else if (AccNum < temp->AccNumber)
            {
                temp = temp->left;
            }
            else
            {
                if (temp->pin == PIN)
                {
                    return 1;
                }
                else if (temp->pin != PIN)
                {
                    return -1;
                }
            }
        }

        return 0;
    }

    int deposit(Node *temp, int AccNum, int PIN, int bal)
    {
        while (temp != NULL)
        {
            if (AccNum > temp->AccNumber)
            {
                temp = temp->right;
            }
            else if (AccNum < temp->AccNumber)
            {
                temp = temp->left;
            }
            else
            {
                if (temp->pin == PIN)
                {
                    temp->balance = temp->balance + bal;
                }
                else if (temp->pin != PIN)
                {
                    return -1;
                }
                return 1;
            }
        }
        return 0;
    }

    int withdraw(Node *temp, int AccNum, int PIN, int bal)
    {
        while (temp != NULL)
        {
            if (AccNum > temp->AccNumber)
            {
                temp = temp->right;
            }
            else if (AccNum < temp->AccNumber)
            {
                temp = temp->left;
            }
            else
            {
                if (temp->pin == PIN)
                {
                    if ((temp->balance < bal))
                    {
                        return -1;
                    }
                    else
                    {
                        temp->balance = temp->balance - bal;
                    }
                }
                else if (temp->pin != PIN)
                {
                    return -2;
                }
                return 1;
            }
        }
        return 0;
    }
};
