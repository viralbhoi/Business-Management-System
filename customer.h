#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;
class customer
{
    private:
        string cust_id;
        string pass;
        string mobile;
        void pass_change();
        void mobile_change();
    public:
        customer();
        customer(string v);
        string getid();
        void display_details();
        void change_details();
        void set_customer();
        void writefile();
};