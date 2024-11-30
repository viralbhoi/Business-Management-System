#include "inventory.h"
inventory::inventory()
{
    ;
}
inventory::inventory(string v)
{
        string i_id1;
        string name1;
        string details1;
        string link1;
        string price1;
    ifstream in;
    in.open("inventory_stock");
    while(!in.eof())
    {
        getline(in,i_id1);
        getline(in,name1);
        getline(in,details1);
        getline(in,link1);
        getline(in,price1);
        if(i_id1==v)
        {
            i_id=i_id1;
           name=name1;
           details=details1;
           link=link1;
           price=price1;
           break;
        }
    }
    in.close();
}
void inventory::set_inventory()
{
    inventory *t=this;
    int j;
    ifstream in;
    in.open("inventory");
    in>>j;
    in.close();
    in.open("inventory_stock");
    for(int i=0;i<j;i++,t++)
    {
        getline(in,t->i_id);
        getline(in,t->name);
        getline(in,t->details);
        getline(in,t->link);
        getline(in,t->price);
    }
    in.close();
}
void inventory::display()
{
    cout<<setw(12)<<left<<"id:"<<i_id<<endl;
    cout<<setw(12)<<left<<"Name:"<<name<<endl;
    cout<<setw(12)<<left<<"Details:"<<details<<endl;
    cout<<setw(12)<<left<<"Price:"<<price<<endl;
    cout<<"More Details-"<<link<<endl;
}
void inventory::change_details()
{
    int j;
    ifstream in;
    in.open("inventory");
    in>>j;
    in.close();
    inventory c1[j];
    c1[0].set_inventory();
    for(int i=0;i<j;i++)
    {
        if(i_id==c1[i].getid())
        {   j=i;break;}
    }
    cout<<"Enter 1 for changing name\n"<<"Enter 2 for changing details\n"<<"Enter 3 for changing link\n"<<"Enter 4 for changing price\n"<<endl;
    int o;
    cin>>o;
    switch(o)
    {
        case 1:
            cout<<"Enter new name:"<<endl;
            while(getchar()!='\n');
            getline(cin,c1[j].name);
            break;
        case 2:
            cout<<"Enter new details:"<<endl;
             while(getchar()!='\n');
            getline(cin,c1[j].details);
            break;
        case 3:
            cout<<"Enter new link:"<<endl;
             while(getchar()!='\n');
            getline(cin,c1[j].link);
            break;
        case 4:
            cout<<"Enter new price:"<<endl;
             while(getchar()!='\n');
            getline(cin,c1[j].price);
            break;
        default:
            cout<<"incorrect option number"<<endl;
    }
    c1[0].writefile();
}
string inventory::getid()
{
    return i_id;
}
void inventory::writefile()
{
    inventory *t=this;
    int j;
    ifstream in;
    in.open("inventory");
    in>>j;
    in.close();
    ofstream w;
    w.open("inventory_stock");
    for(int i=0;i<j;i++,t++)
    {
        if(!(t->i_id=="null"||t->i_id=="NULL"||t->i_id=="\0"||t->i_id=="\n")){
        w<<t->i_id<<endl;
        w<<t->name<<endl;
        w<<t->details<<endl;
        w<<t->link<<endl;
        w<<t->price<<endl;}
    }
    w.close();
}
string inventory::getname()
{
    return name;
}