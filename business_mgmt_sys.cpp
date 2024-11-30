/*Business management system

    E.g. Webstore
    details stored:
        employee details
        login details
        inventory details
        customer details
        bills
    features:
        account creation
        user authentication
        editing customer or employee details
        editing inventory stocks
        shopping cart usability
        generating bills
        permenent/non-volatile storing info
        permission distribution on basis of user
        exception handling
        user friendly
    files:
        inventory_stock
        cust_details
        emp_details
        inventory
        customer
        emp
        bills1,bills2,...
        inventory.h
        employee.h
        customer.h
        employee.cpp
        customer.cpp
        inventory.cpp
        business_mgmt_sys.cpp
*/
#include "employee.h"
#include "customer.h"
#include "inventory.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;
#ifndef MAX_FILE_LENGTH
#define MAX_FILE_LENGTH 255
#endif
struct CommandLineException
{
    CommandLineException(int max, int provided)
    {
        cout << endl;
        cout << "The number of command line arguments doesn't match." << endl;
        cout << provided << " arguments were entered, and " << max << " are required." << endl;
    }
};
struct FileException
{
    FileException(const string file)
    {
        cout << endl
             << "'" << file << "'" << " could not be opened." << endl;
    }
};
void lines()
{
    for (int i = 0; i < 150; i++)
        cout << "-";
    cout << endl;
}
void bill(string i)
{
    int n2;
    inventory n1(i);
    cout << "Amount would be debited from your linked account";
    n1.display();
    cout << "Thank you for purchasing" << endl;
    ifstream in2("billing");
    in2 >> n2;
    in2.close();
    ofstream n;
    n.open("bill" + to_string(++n2));
    n << n1.name << endl;
    n << n1.details << endl;
    n << n1.price << endl;
    n << n1.link << endl;
    n.close();
    n.open("billing");
    n << n2;
    n.close();
}
void shopping()
{
    int j;
    string m;
    ifstream in1;
    in1.open("inventory");
    in1 >> j;
    in1.close();
    inventory n1[j];
    n1[0].set_inventory();
    cout << "enter 1 to search" << endl;
    cout << "enter 2 to display all items" << endl;
    cout << "enter 3 for exit" << endl;
    cout << "enter 4 for purchasing" << endl;
    int o;
    cin >> o;
    switch (o)
    {
    case 1:
        cout << "Enter name:" << endl;
        while (getchar() != '\n')
            ;
        getline(cin, m);
        for (int i = 0; i < j; i++)
        {
            if (m.compare(n1[i].getname()) <= 0)
                n1[i].display();
        }
        break;
    case 2:
        for (int i = 0; i < j; i++)
            n1[i].display();
        break;
    case 3:
        break;
    case 4:
        cout << "Enter inventory id to be purchased:" << endl;
        cin >> m;
        for (int i = 0; i < j; i++)
        {
            if (n1[i].getid() == m)
                bill(m);
        }
        break;
    default:
        cout << "incorrect option number" << endl;
    }
}
void edit_inventory()
{
    int j;
    string p;
    ifstream in;
    cout << "Enter inventory id:" << endl;
    cin >> p;
    inventory n1(p);
    n1.display();
    n1.change_details();
}
void manage_c(string c)
{
    customer c1(c);
    int o = -1;
    do
    {
        lines();
        cout << "Welcome Dear Customer" << endl;
        lines();
        cout << "enter 1 for viewing profile" << endl;
        cout << "enter 2 for editing profile" << endl;
        cout << "enter 3 for shopping" << endl;
        cout << "enter 4 for exit" << endl;
        cin >> o;
        switch (o)
        {
        case 1:
            c1.display_details();
            break;
        case 2:
            c1.change_details();
            break;
        case 3:
            cout << "Shopping..." << endl;
            shopping();
            break;
        case 4:
            cout << "exiting..." << endl;
            break;
        default:
            cout << "enter correct option." << endl;
        }
    } while (o != 4);
}
void login1()
{
    ifstream in;
    in.open("cust_details");
    string m, m1, c, p, p1, p2;
    cout << "Enter mobile no." << endl;
    cin >> m;
    while (!in.eof())
    {
        in >> c >> p1 >> m1;
        if (m.compare(m1) == 0)
        {
            p = p1;
            break;
        }
    }
    cout << "Enter password:" << endl;
    cin >> p2;
    if (p2 == p1)
    {
        manage_c(c);
    }
    else
    {
        cout << "invalid access" << endl;
    }
}
void edit_customer()
{
    cout << "Enter 1 for using customer login details" << endl;
    cout << "Enter 2 for using customer id" << endl;
    int o;
    cin >> o;
    if (o == 1)
    {
        login1();
    }
    else if (o = 2)
    {
        string p;
        cout << "Enter customer id:" << endl;
        cin >> p;
        customer c1(p);
        c1.change_details();
    }
    else
    {
        cout << "incorrect option number" << endl;
    }
}

void manage_e(string e)
{
    employee c1(e);
    int o = -1;
    do
    {
        lines();
        cout << "Welcome Dear Employee" << endl;
        lines();
        cout << "enter 1 for viewing profile" << endl;
        cout << "enter 2 for editing profile" << endl;
        cout << "enter 3 for editing inventory" << endl;
        cout << "enter 4 for editing customer details" << endl;
        cout << "enter 5 for exit" << endl;
        cin >> o;
        switch (o)
        {
        case 1:
            c1.display_details();
            break; 
        case 2:
            c1.change_details();
            break;
        case 3:
            cout << "inventory records..." << endl;
            if (c1.get_p() == 1)
            {
                edit_inventory();
            }
            else
            {
                cout << "invalid access" << endl;
            }
            break;
        case 4:
            cout << "customer records..." << endl;
            if (c1.get_p() == 1)
            {
                edit_customer();
            }
            else
            {
                cout << "invalid access" << endl;
            }
            break;
        case 5:
            cout << "exiting..." << endl;
            break;
        default:
            cout << "enter correct option." << endl;
        }
    } while (o != 5);
}
void create1()
{
    string m, p, p1;
    cout << "Enter mobile no." << endl;
    cin >> m;
    cout << "Enter password:" << endl;
    cin >> p;
    cout << "Enter password again to confirm:" << endl;
    cin >> p1;
    if (p == p1)
    {
        fstream n;
        int n1;
        n.open("customer", ios::in);
        n >> n1;
        n.close();
        n.open("cust_details", ios::app);
        n << endl;
        n << "c" + to_string(++n1) << " " << p << " " << m;
        n.close();
        n.open("customer", ios::out);
        n << n1;
        n.close();
        cout << "Created successfully" << endl;
    }
    else
    {
        cout << "password does not match above password" << endl;
    }
}
void create2()
{
    string m1;
    cout << "Enter admin password:" << endl;
    cin >> m1;
    if (m1 == "Ak04_02")
    {
        string m, p, p1;
        int per;
        double s;
        cout << "Enter mobile no." << endl;
        cin >> m;
        cout << "Enter salary:" << endl;
        cin >> s;
        cout << "Enter permission(0 for no file access and 1 for all file access):" << endl;
        cin >> per;
        cout << "Enter password:" << endl;
        cin >> p;
        cout << "Enter password again to confirm:" << endl;
        cin >> p1;
        if (p == p1)
        {
            fstream n;
            int n1;
            n.open("emp", ios::in);
            n >> n1;
            n.close();
            n.open("emp_details", ios::app);
            n << "e" + to_string(++n1) << " " << p << " " << m << " " << s << " " << per << endl;
            n.close();
            n.open("emp", ios::out);
            n << n1;
            n.close();
            cout << "Created successfully" << endl;
        }
        else
        {
            cout << "password does not match above password" << endl;
        }
    }
    else
    {
        cout << "invalid access" << endl;
    }
}

void login2()
{
    ifstream in;
    in.open("emp_details");
    string m, e, m1, p, p1, p2;
    double s;
    int per;
    cout << "Enter mobile no." << endl;
    cin >> m;
    while (!in.eof())
    {
        in >> e >> p1 >> m1 >> s >> per;
        if (m.compare(m1) == 0)
        {
            p = p1;
            break;
        }
    }
    cout << "Enter password:" << endl;
    cin >> p2;
    if (p2 == p1)
    {
        manage_e(e);
    }
    else
    {
        cout << "invalid access" << endl;
    }
}
void create()
{
    cout << "Which account customer or employee?(1 or 2)" << endl;
    int o = 0;
    cin >> o;
    switch (o)
    {
    case 1:
        cout << "Loading..." << endl;
        create1();
        break;
    case 2:
        cout << "Loading..." << endl;
        create2();
        break;
    default:
        cout << "incorrect option";
    }
}
void login()
{
    cout << "Which account customer or employee?(1 or 2)" << endl;
    int o = 0;
    cin >> o;
    switch (o)
    {
    case 1:
        cout << "Loading..." << endl;
        login1();
        break;
    case 2:
        cout << "Loading..." << endl;
        login2();
        break;
    default:
        cout << "incorrect option";
    }
}
void manage_user()
{
    lines();
    cout << "\t\t\t\t\t\t\t\tWelcome to Our Webstore" << endl;
    lines();
    int p = 0;
    int o = 0;
    do
    {
        cout << "1.Enter 1 for login" << endl;
        cout << "2.Enter 2 for signup" << endl;
        cin >> o;
        switch (o)
        {
        case 1:
            p = 1;
            login();
            break;
        case 2:
            p = 1;
            create();
            break;
        default:
            cout << "please enter correct option number" << endl;
        }
    } while (!p);
}

int main(int argc, char *argv[])
{
    const int n_paramters = 7;
    try
    {
        char fn[n_paramters][MAX_FILE_LENGTH]; // file names for input and output

        // If there are not proper amount of parameters from command line
        if (argc != n_paramters + 1)
        {
            throw CommandLineException(n_paramters, argc - 1);
        }

        // copy necessary command line parameters
        for (int i = 0; i < n_paramters; i++)
        {
            strcpy(fn[i], argv[i + 1]);
        }

        ifstream i1(fn[0]);
        ifstream i2(fn[1]);
        ifstream i3(fn[2]);
        ifstream i4(fn[3]);
        ifstream i5(fn[4]);

        if (!i1)
            throw FileException(fn[0]);
        if (!i2)
            throw FileException(fn[1]);
        if (!i3)
            throw FileException(fn[2]);
        if (!i4)
            throw FileException(fn[2]);
        if (!i5)
            throw FileException(fn[2]);
        i1.close();
        i2.close();
        i3.close();
        i4.close();
        i5.close();
        manage_user();
    }
    catch (...)
    {
        cout << "Program ended with exception." << endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}
