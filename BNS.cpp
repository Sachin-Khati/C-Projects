#include <iostream>
#include <string>
#include <map>
using namespace std;
class Bank
{
private:
    map<string, double> account;
    map<string, string> password;

public:
    void CreateAccount(string &name, double intialamount, string &passwordd)
    {
        if (account.find(name) != account.end())
        {
            cout << "Account already Exist " << endl;
        }
        else
        {
            account[name] = intialamount;
            password[name] = passwordd;
            cout << "Account Created Sucessfully" << endl;
        }
    }
    bool authenticate(const string &name)
    {
        string pass;
        cout << "enter your password:";
        cin >> pass;
        if (password[name] == pass)
            return true;
        cout << "Incorrect Password\n";
        return false;
    }
    void Deposit(string &name, double Depositamount)
    {
        if (account.find(name) != account.end())
        {
            if (!authenticate(name))
                return;
            account[name] += Depositamount;
            cout << "Account Deposit Sucessfully" << endl;
        }
        else
        {
            cout << "Account does not Exist " << endl;
        }
    }
    void Withdraw(string &name, double amount)
    {
        if (account.find(name) != account.end())
        {
            if (!authenticate(name))
                return;
            if (account[name] > amount)
            {
                account[name] -= amount;
                cout << "Account Deposit Sucessfully" << endl;
            }
            else
            {
                cout << "Insufficent Balance " << endl;
            }
        }
        else
        {

            cout << "Account does not Exist " << endl;
        }
    }
    void CheckBalance(string &name)
    {
        if (account.find(name) != account.end())
        {
            if (!authenticate(name))
                return;
            cout << "Balance for Account " << name << "is" << account[name] << endl;
        }
        else
        {
            cout << "Account does not Exist " << endl;
        }
    }
};
int main()
{
    Bank bank;
    string name;
    double amount;
    int choice;
    string password;
    do
    {
        cout << "**Select Option **" << endl;
        cout << "1.CREATE ACCOUNT" << endl;
        cout << "2.DEPOSIT" << endl;
        cout << "3.WITHDROWL" << endl;
        cout << "4.CHECK BALANCE" << endl;
        cout << "5.Exit" << endl;
        cout << "enter your Choice :" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter your name :" << endl;
            cin >> name;
            cout << "enter Amount " << endl;
            cin >> amount;
            cout << "set your Password" << endl;
            cin >> password;
            bank.CreateAccount(name, amount, password);
            break;
        case 2:
            cout << "enter your name :" << endl;
            cin >> name;
            cout << "enter Amount " << endl;
            cin >> amount;
            bank.Deposit(name, amount);
            break;
        case 3:
            cout << "enter your name :" << endl;
            cin >> name;
            cout << "enter Amount " << endl;
            cin >> amount;
            bank.Withdraw(name, amount);
            break;
        case 4:
            cout << "enter your name :" << endl;
            cin >> name;
            bank.CheckBalance(name);
            break;
        case 5:
            cout << "Existing the Program Thanku 😊" << endl;
            break;
        default:
            cout << "Invalid Choice ! Please try again ";
        }
    } while (choice != 5);
    return 0;
}