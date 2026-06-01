#include<iostream>
#include<string>

using namespace std;
//task a
class electronics
{
private:
    string brand;
    double price;
    string deviceId;
public:
    void setbrand(string b){brand=b;}

    void setprice(double p){price=p;}

    void setdeviceid(string id){deviceId=id;}

    string getbrand()const{return brand; }

    double getprice()const{return price;}

    string getdeviceid()const{return deviceId;}

    //task b
    electronics(){
        brand="nokia";
        price=0.0;
        deviceId="Id001";
        }

    electronics(string b,double p, string id)
    {
        brand=b; price=p; deviceId=id;
        cout<<"parameterised constructor created successfully!"<<endl;
    }

    //overloading
     int calculateWarantee(int years)
    {
        return years;
    }
    int calculateWarantee(int years, int time)
    {
        cout<<"years: "<<years<<endl;
         cout<<"time: "<<time<<endl;
    }

    ~electronics(){cout<<"destructor successfully created"<<endl;}
    void display()
    {
        cout<<"brand: "<<brand<<endl;
        cout<<"price: "<<price<<endl;
        cout<<"device id: "<<deviceId<<endl;
    }
};
//task c
class smartphone: public electronics
{
    //single inheritance
public:
    string cameraResolution;

    smartphone(string b,double p, string id,string cam)
    :electronics(b,p,id)
    {
       cameraResolution=cam;
    }
    void display()
    {
        electronics::display();
        cout<<"camera resolution: "<<cameraResolution<<endl;
    }

};
class laptop: public electronics
{
    //single inheritance
public:
    double RAMsize;
    laptop(string b, double p, string id, double RAM)
    :electronics( b,p,id)
    {
        RAMsize=RAM;
    }
    void display()  {
        electronics::display();
        cout<<"RAM size: "<<RAMsize<<endl;
    }


};
class smartwatch: public smartphone
{
    //multi level inheritance
public:
    int batterylife;
    smartwatch(string b,double p, string id,string cam,int bat)
    :smartphone(b,p,id,cam)
    {
        batterylife=bat;
    }
    void display()
    {
        smartphone::display();
        cout<<"Battery life: "<<batterylife<<endl;
    }
};
int main()
{
    cout<<"\n---------------SMARTPHONE OBJECT---------------------\n";
    smartphone sp2("APPLE",1500,"id200","MP");
    sp2.display();
    cout<<"\n-----------------------------------------------------\n";

    cout<<"\n-----------------LAOTOPS OBJECT----------------------\n";
    laptop lp("intel",1620,"id300",4);
    lp.display();
    cout<<"\n-----------------------------------------------------\n";

    cout<<"\n---------------SMARTWATCH OBJECT---------------------\n";
    smartwatch sw("APPlE",200.0,"id400","Mc",100);
    sw.display();
    cout<<"\n-----------------------------------------------------\n";

    cout<<"\n------------ELECTRONIC DEVICED OBJECT----------------\n";
    electronics e1("ITEL",100,"ID100");
    e1.display();
    cout<<"\n-----------------------------------------------------\n";

    return 0;
}

