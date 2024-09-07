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
private:
    int pin;
    float balance;
    string id, password, name, fname, address, phone;

public:
    void menu();
    void bank_management();
    void atm_management();
    void new_user();
    void already_user();
    void deposit();
    void withdraw();
    void transfer();
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

// function for atm_management
void bank::atm_management()
{
p:
    system("cls");
    int choice;
    cout << "\n\n\t\t\tATM Management System";
    cout << "\n\n 1. User Login & Check Balance";
    cout << "\n 2. Withdraw Amount";
    cout << "\n 3. Account Details";
    cout << "\n 4. Go Back";
    cout << "\n\n Enter Your Choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        new_user();
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

// function for bank_management
void bank::bank_management()
{
p:
    system("cls");
    int choice;
    cout << "\n\n\t\t\tBank Management System";
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
        new_user();
        break;
    case 2:
        already_user();
        break;
    case 3:
        deposit();
        break;
    case 4:
        withdraw();
        break;
    case 5:
        transfer();
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

// creating the new_user function
void bank::new_user()
{
p:
    system("cls");
    fstream file;
    int p;
    float bal;
    string n, f, pass, addr, ph, i;
    cout << "\n\n\t\t\tAdd New User";
    cout << "\n\n User ID : ";
    cin >> id;
    cout << "\n\n\t\tName : ";
    cin >> name;
    cout << "\n\n Father Name : ";
    cin >> fname;
    cout << "\n\n\t\t Address : ";
    cin >> address;
    cout << "\n\n Pin Code (6 digit) : ";
    cin >> pin;
    cout << "\n\n\t\tPassword :";
    cin >> password;
    cout << "\n\n Phone No : ";
    cin >> phone;
    cout << "\n\n\t\tCurrent Balance : ";
    cin >> balance;
    file.open("bank.txt", ios::in);
    if (!file)
    {
        file.open("bank.txt", ios::app | ios::out);
        file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << password << " " << phone << " " << balance << endl;
        file.close();
    }
    else
    {
        file >> i >> n >> f >> addr >> p >> pass >> ph >> bal;
        while (!file.eof())
        {
            if (i == id)
            {
                cout << "\n\n User ID Already Exist...";
                getch();
                goto p;
            }
            file >> i >> n >> f >> addr >> p >> pass >> ph >> bal;
        }
        file.close();
        file.open("bank.txt", ios::app | ios::out);
        file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << password << " " << phone << " " << balance << endl;
        file.close();
    }
    cout << "\n\n New User Added Successfully..";
}

void bank::already_user()
{

    system("cls");
    fstream file;
    string test_id;
    int found = 0;
    cout << "\n\n\t\t\tAlready User Account";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error...";
    }
    else
    {
        cout << "\n\n User ID : ";
        cin >> test_id;
        file >> id >> name >> fname >> address >> pin >> password >> phone >> balance;
        while (!file.eof())
        {
            if (test_id == id)
            {
                system("cls");
                cout << "\n\n\t\t\t Already User Account";
                cout << "\n\n User ID : " << id << "   Pin Code : " << pin << "   Password : " << password;
                found++;
            }
            file >> id >> name >> fname >> address >> pin >> password >> phone >> balance;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n User ID Can't Found...";
        }
    }
}

// function for deposit option
void bank::deposit()
{

    fstream file, file1;
    string test_id;
    float dep;
    int found = 0;
    system("cls");
    cout << "\n\n\t\t\tDeposit Amount Option";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error...";
    }
    else
    {
        cout << "\n\n User ID : ";
        cin >> test_id;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> password >> phone >> balance;
        while (!file.eof())
        {
            if (test_id == id)
            {
                cout << "\n\n Amount For Deposit : ";
                cin >> dep;
                balance += dep;
                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << password << " " << phone << " " << balance << endl;
                found++;
                cout << "\n\n\t\t\tYour Amount " << dep << " Successfully Deposited...";
            }
            else
            {
                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << password << " " << phone << " " << balance << endl;
            }
            file >> id >> name >> fname >> address >> pin >> password >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0)
        {
            cout << "\n\n User ID Can't Found...";
        }
    }
}

// function for withdraw
void bank::withdraw()
{

    fstream file, file1;
    string test_id;
    float with;
    int found = 0;
    system("cls");
    cout << "\n\n\t\t\tWithdraw Amount Option";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error...";
    }
    else
    {
        cout << "\n\n User ID : ";
        cin >> test_id;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> password >> phone >> balance;
        while (!file.eof())
        {
            if (test_id == id)
            {
                cout << "\n\n Amount For Withdraw : ";
                cin >> with;
                // condition for balance
                if (with <= balance)
                {
                    balance -= with;
                    file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << password << " " << phone << " " << balance << endl;
                    cout << "\n\n\t\t\tYour Amount " << with << "Successfully Withdrawed...";
                }
                else
                {
                    file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << password << " " << phone << " " << balance << endl;
                    cout << "\n\n\t\t\tYour Current Balance " << balance << " Is Less.....";
                }
                found++;
            }
            else
            {
                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << password << " " << phone << " " << balance << endl;
            }
            file >> id >> name >> fname >> address >> pin >> password >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0)
        {
            cout << "\n\n User ID Can't Found...";
        }
    }
}

// transfer function
void bank::transfer()
{
    fstream file, file1;
    system("cls");
    string sender_id, reciver_id;
    int found = 0;
    float amount;
    cout << "\n\n\t\t\tPayment Transfer Option";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\n File Opening Error....";
    }
    else
    {
        cout << "\n\n Enter Sender User ID For Transaction : ";
        cin >> sender_id;
        cout << "\n\n Reciver User ID For Transaction : ";
        cin >> reciver_id;
        cout << "\n\n Enter Transaction Amount : ";
        cin >> amount;
        file >> id >> name >> fname >> address >> pin >> password >> phone >> balance;
        while (!file.eof())
        {
            if (sender_id == id && amount >= balance)
                found++;
            else if (reciver_id == id)
                found++;

            file >> id >> name >> fname >> address >> pin >> password >> phone >> balance;
        }
        file.close();
        if (found == 2)
        {
            file.open("bank.txt", ios::in);
            file1.open("bank1.txt", ios::app | ios::out);
            file >> id >> name >> fname >> address >> pin >> password >> phone >> balance;
            while (!file.eof())
            {
                if (sender_id == id)
                {
                    balance -= amount;
                    file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << password << " " << phone << " " << balance << endl;
                }
                else if (reciver_id == id)
                {
                    balance += amount;
                }
                else
                {
                    file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << password << " " << phone << " " << balance << endl;
                }
                file >> id >> name >> fname >> address >> pin >> password >> phone >> balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt", "bank.txt");
        }
        else
        {
            cout << "\n\n\t\t\tBoth Transaction User ID's & Balance Are Invalid....";
        }
    }
}

// main function
int main()
{
    bank obj;   // creating the object of bank class
    obj.menu(); // calling the menu function
}
