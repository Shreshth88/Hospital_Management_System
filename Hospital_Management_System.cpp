#include<iostream> 
#include<string> 
using namespace std; 
class Patient 
{ 
 protected: 
 string name; 
 string surname; 
 int age; 
 string contact; 
 int amount; 
 string date; 
 public: 
 void patientinfo() 
 { 
    cout<<"Enter The Patient's Name: "; 
    cin>>name; 
    cout<<"Enter The Patient's Surname: "; 
    cin>>surname; 
    cout<<"Enter The Patient's Age: "; 
    cin>>age; 
    cout<<"Enter The Patient's Contact Number: "; 
    cin>>contact; 
    cout<<"Enter the date: "; 
    cin>>date; 
 } 
}; 
class Chargesinfo : public Patient 
{ 
    protected: 
        string a; 
        string b; 
        string room; 
        string type; 
        double deluxe; 
        double semideluxe; 
        double superdeluxe; 
        int dfees=500; 
    public: 
        void chargesinfo() 
        { 
            cout<<"Do you want a room (Y or N): "; 
            cin>>a; 
            if(a=="Y") 
            { 
                cout<<"The cost of the room are following:-"<<endl; 
                cout<<"Semi Deluxe: 10,000"<<endl; 
                cout<<"Deluxe: 15,000"<<endl; 
                cout<<"Super Deluxe: 20,000"<<endl; 
                cout<<"Enter the room type(Semi Deluxe,Deluxe,Super Deluxe): "; 
                cin>>room; 
            
            } 
            cout<<"Is there any diagnosis/Test/laboratory charges ?"; 
            cin>>b; 
            if(b=="Y") 
            { 
                cout<<"Enter the amount of diagnosis/Test/laboratory charge: "; 
                cin>>amount; 
            } 
        } 
}; 
class Medicineinfo: public Chargesinfo 
{ 
    protected: 
        string medname[50]; 
        int medcost[50]; 
        int num,sum=0; 
    public: 
        void medicineinfo() 
        { 
            cout<<"Enter the number of medicine "; 
            cin>>num; 
            for(int i=1;i<=num;i++) 
            { 
                cout<<"Enter the Name of medicine "; 
                cin>>medname[i]; 
                cout<<"ENter the Cost of medicine "; 
                cin>>medcost[i]; 
            } 
        } 
        void total() 
        { 
            for(int i=1;i<=num;i++) 
            { 
                sum=sum+medcost[i]; 
            } 
        } 
};  
class Display: public Medicineinfo 
{ 
 public: 
 void display() 
 { 
 cout<<"---------------------------------------------Detail-----------------------------------------------------"<<endl; 
 cout<<"Patient: "<<name<<" "<<surname<<" "<<"DATE: "<<date<<endl; 
 cout<<"Patient's Age: "<<age<<endl; 
 cout<<"Patient's Contact Number: "<<contact<<endl<<endl<<endl; 
 cout<<"---------------------------------------------CHARGES-----------------------------------------------------"<<endl; 
 if(a=="Y") 
 { 
 if(room=="deluxe") 
 { 
 deluxe=15000; 
 cout<<"The cost of the Deluxe Room is: "<<deluxe<<endl; 
 } 
 else if (room=="semideluxe") 
 { 
 semideluxe=10000; 
 cout<<"The cost of the Semi Deluxe Room is: "<<semideluxe<<endl; 
 } 
 else if(room=="superdeluxe") 
 { 
 superdeluxe=20000; 
 cout<<"The cost of the Super Deluxe Room is : "<<superdeluxe<<endl; 
 } 
 else 
 { 
 cout<<"No room is there which input is given by you"<<endl; 
 } 
 } 
 else if(a=="N") 
 { 
 cout<<"No room charges"<<endl; 
 } 
 cout<<"The Doctor consultant fees is: "<<dfees<<endl<<endl<<endl; 
 cout<<"Medicine Name"<<" "<<"Medicine Cost"<<endl; 
 for(int i=1;i<=num;i++) 
 { 
 
 cout<<medname[i]<<" "<<medcost[i]<<endl; 
 } 
 cout<<"-----------------------------------------------------------------------------------------------------"<<endl; 
 if(a=="Y") 
 { 
 if(room=="deluxe") 
 { 
 if(b=="Y") 
 { 
 cout<<"Total Cost : "<<sum+deluxe+dfees+amount<<endl; 
 } 
 else 
 { 
 cout<<"Total Cost : "<<sum+deluxe+dfees<<endl; 
 } 
 
 } 
 else if(room=="semideluxe") 
 { 
 if(b=="Y") 
 { 
 cout<<"Total Cost : "<<sum+semideluxe+dfees+amount<<endl; 
 } 
 else 
 { 
 cout<<"Total Cost : "<<sum+semideluxe+dfees<<endl; 
 } 
 
 } 
 else if(room=="superdeluxe") 
 { 
 if(b=="Y") 
 { 
 cout<<"Total Cost : "<<sum+superdeluxe+dfees+amount<<endl; 
 } 
 else 
 { 
 cout<<"Total Cost : "<<sum+superdeluxe+dfees<<endl; 
 } 
 
 } 
 } 
 else if(a=="N") 
 { 
 if(b=="Y") 
 { 
 cout<<"Total Cost : "<<sum+dfees+amount<<endl; 
 } 
 else 
 { 
 cout<<"Total Cost : "<<sum+dfees<<endl; 
 } 
 
 } 
 cout<<"-----------------------------------------------------------------------------------------------------"<<endl; 
 } 
}; 
int main() 
{ 
 Display d; 
 d.patientinfo(); 
 d.chargesinfo(); 
 d.medicineinfo(); 
 d.total(); 
 d.display(); 
 return 0; 
} 