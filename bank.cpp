// including the required header files
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <Windows.h>

using namespace std;

// creating class for banking system
class bank
{
public:
    void menu();
    void bank_management();
    void atm_management();
};

void bank::menu()
{
p:
    system("cls");
    int choice;
    char ch;
    string pin, password, email;
    cout << "\n\n\t\t\tControl Panel";
    cout << "\n\n 1. Bank Management";
    cout << "\n 2. ATM Management";
    cout << "\n 3. Exit";
    cout << "\n\n Enter Your Choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\n\n\t\t\tLogin Account";
        cout << "\n\n E-mail : ";
        cin >> email;
        cout << "\n\n\t\t Pin Code : ";
        // loop for taking 5 characters
        for (int i = 1; i <= 5; i++)
        {
            ch = getch();
            pin += ch;
            cout << "*";
        }
        cout << "\n\n Password : ";
        // loop for taking 5 characters
        for (int i = 1; i <= 5; i++)
        {
            ch = getch();
            password += ch;
            cout << "*";
        }
        // checking the emial whether is it right or wrong
        if (email == "haris@gmail.com" && pin == "12345" && password == "haris")
        {
            bank_management();
        }
        else
        {
            cout << "\n\n Your E-mail, Pin & Password is wrong...";
        }
        break;
    case 2:
        atm_management();
        break;
    case 3:
        exit(0);
    default:
        cout << "\n\n Invalid Value....Please Try Again";
        break;
    }
    getch();
    goto p;
}

// function for bank_management
void bank::bank_management()
{
}

// function for atm_management
void bank::atm_management()
{
}

// main function
int main()
{
    bank obj;   // creating the object of bank class
    obj.menu(); // calling the menu function
}
