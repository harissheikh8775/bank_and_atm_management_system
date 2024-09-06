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
        system("cls");
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
p:
    system("cls");
    int choice;
    cout << "\n\n\t\t\tBank Management System";
    cout << "\n\n 1. User Login & Check Balance";
    cout << "\n 2. Withdraw Amount";
    cout << "\n 3. Account Details";
    cout << "\n 4. Go Back";
    cout << "\n\n Enter Your Choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        menu();
    default:
        cout << "\n\n Invalic Value...Please Try Again....";
        break;
    }
    getch(); // like mainloop
    goto p;  // repeating the function
}

// function for atm_management
void bank::atm_management()
{
p:
    system("cls");
    int choice;
    cout << "\n\n\t\t\tATM Management System";
    cout << "\n\n 1. New User";
    cout << "\n 2. Already User";
    cout << "\n 3. Deposit Option";
    cout << "\n 4. Withdraw Option";
    cout << "\n 5. Transfer Option";
    cout << "\n 6. Payment Option";
    cout << "\n 7. Search User Record";
    cout << "\n 8. Edit User Record";
    cout << "\n 9. Delete User Record";
    cout << "\n 10. Show All Records ";
    cout << "\n 11. Payment All Records ";
    cout << "\n 12. Go Back ";
    cout << "\n\n Enter Your Choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        break;
    case 11:
        break;
    case 12:
        menu(); // go back
    default:
        cout << "\n\n Invalic Value...Please Try Again....";
        break;
    }
    getch(); // like mainloop
    goto p;  // repeating the function
}

// main function
int main()
{
    bank obj;   // creating the object of bank class
    obj.menu(); // calling the menu function
}
