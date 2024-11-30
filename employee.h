#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;
class employee
{
private:
    string emp_id;
    string pass;
    string mobile;
    double salary;
    int permission;
    void pass_change();
    void mobile_change();

public:
    employee();
    employee(string v);
    void display_details();
    void change_details();
    void set_emp();
    void writefile();
    int get_p();
    void change_p();
    string getid();
};