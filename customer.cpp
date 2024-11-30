#include "customer.h"
customer::customer()
{
    ;
}
customer::customer(string v)
{
        string cust_id1;
        string pass1;
        string mobile1;
    ifstream in;
    in.open("cust_details");
    while(!in.eof())
    {
        in>>cust_id1>>pass1>>mobile1;
        if(cust_id1==v)
        {
            cust_id=cust_id1;
            pass=pass1;
            mobile=mobile1;break;
        }
    }
    in.close();
}
void customer::set_customer()
{
    customer *t=this;
    int j;
    ifstream in;
    in.open("customer");
    in>>j;
    in.close();
    in.open("cust_details");
    for(int i=0;i<j;i++,t++)
    {
        in>>t->cust_id;
        in>>t->pass;
        in>>t->mobile;
    }
    in.close();
}
void customer::display_details()
{
    cout<<setw(11)<<"Id:"<<cust_id<<endl;
    cout<<setw(11)<<"mobile no.:"<<mobile<<endl;
}
string customer::getid()
{
    return cust_id;
}
void customer::change_details()
{   int j;
    ifstream in;
    in.open("customer");
    in>>j;
    in.close();
    customer c1[j];
    c1[0].set_customer();
    for(int i=0;i<j;i++)
    {
        if(cust_id==c1[i].getid())
        {   j=i;break;}
    }
    cout<<"Enter 1 for changing password\n"<<"Enter 2 for changing mobile no."<<endl;
    int o;
    cin>>o;
    switch(o)
    {
        case 1:
            c1[j].pass_change();break;
        case 2:
            c1[j].mobile_change();break;
        default:
            cout<<"incorrect option number"<<endl;
    }
    c1[0].writefile();
}
void customer::pass_change()
{
    string p;
    cout<<"Enter old password:"<<endl;
    cin>>p;
    if(p==pass)
    {
        cout<<"Enter new password:"<<endl;
        cin>>pass;
    }
    else{
        cout<<"Wrong password"<<endl;
    }
}
void customer::mobile_change()
{
    cout<<"Enter mobile number:"<<endl;
    cin>>mobile;
}
void customer::writefile()
{
    customer *t=this;
    int j;
    ifstream in;
    in.open("customer");
    in>>j;
    in.close();
    ofstream w;
    w.open("cust_details");
    for(int i=0;i<j;i++,t++)
    {
        if(!(t->cust_id=="null"||t->cust_id=="NULL"||t->cust_id=="\0"||t->cust_id=="\n")){
        w<<t->cust_id<<" "<<t->pass<<" "<<t->mobile<<endl;
        }
    }
    w.close();
}