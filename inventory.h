#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;
class inventory{
    private:
        string i_id;
        string name;
        string details;
        string link;
        string price;
    public:
        inventory();
        inventory(string v);
        void set_inventory();
        void display();
        void change_details();
        void writefile();
        string getid();
        string getname();
        friend void bill(string s);
};