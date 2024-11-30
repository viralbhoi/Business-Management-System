#include "employee.h"
employee::employee()
{
    ;
}
void employee::set_emp()
{
    employee *t = this;
    int j;
    ifstream in;
    in.open("emp");
    in >> j;
    in.close();
    in.open("emp_details");
    for (int i = 0; i < j; i++, t++)
    {
        in >> t->emp_id;
        in >> t->pass;
        in >> t->mobile;
        in >> t->salary;
        in >> t->permission;
        break;
    }
    in.close();
}
int employee::get_p()
{
    return permission;
}
void employee::change_p()
{
    if (permission == 0)
        permission = 1;
    else
        permission = 0;
}
employee::employee(string v)
{
    string emp_id1;
    string pass1;
    string mobile1;
    double salary1;
    int permission1;
    ifstream in;
    in.open("emp_details");
    while (!in.eof())
    {
        in >> emp_id1 >> pass1 >> mobile1 >> salary1 >> permission1;
        if (emp_id1 == v)
        {
            emp_id = emp_id1;
            pass = pass1;
            mobile = mobile1;
            salary = salary1;
            permission = permission1;
        }
    }
    in.close();
}
void employee::display_details()
{
    cout << setw(11) << left << "Id:" << emp_id << endl;
    cout << setw(11) << left << "mobile no.:" << mobile << endl;
    cout << "salary:" << salary << endl;
}
string employee::getid()
{
    return emp_id;
}
void employee::change_details()
{
    int j;
    ifstream in;
    in.open("emp");
    in >> j;
    in.close();
    employee c1[j];
    c1[0].set_emp();
    for (int i = 0; i < j; i++)
    {
        if (emp_id == c1[i].getid())
        {
            j = i;
            break;
        }
    }
    cout << "Enter 1 for changing password\n"
         << "Enter 2 for changing mobile no." << endl;
    int o;
    cin >> o;
    switch (o)
    {
    case 1:
        c1[j].pass_change();
        break;
    case 2:
        c1[j].mobile_change();
        break;
    default:
        cout << "incorrect option number" << endl;
    }
    c1[0].writefile();
}
void employee::pass_change()
{
    string p;
    cout << "Enter old password:" << endl;
    cin >> p;
    if (p == pass)
    {
        cout << "Enter new password:" << endl;
        cin >> pass;
        cout << "Changed" << endl;
    }
    else
    {
        cout << "Wrong password" << endl;
    }
}
void employee::mobile_change()
{
    cout << "Enter mobile number:" << endl;
    cin >> mobile;
    cout << "Changed" << endl;
}
void employee::writefile()
{
    employee *t = this;
    int j;
    ifstream in;
    in.open("emp");
    in >> j;
    in.close();
    ofstream w;
    w.open("emp_details");
    for (int i = 0; i < j; i++, t++)
    {
        if (!(t->emp_id == "null" || t->emp_id == "NULL" || t->emp_id == "\0" || t->emp_id == "\n"))
        {
            w << t->emp_id << " " << t->pass << " " << t->mobile << " " << t->salary << " " << t->permission << endl;
        }
    }
    w.close();
}