#include<iostream>
using namespace std;

int main(){
    int a,b,total;
    int c;
    cout<<"################ MENU ###############";
    cout<<"\n1.Addition";
    cout<<"\n2.Subtraction";
    cout<<"\n3.Multiplication";
    cout<<"\n4.Division";
    cout<<"\nEnter First number:-";
    cin>>a;
    cout<<"\nEnter second number:-";
    cin>>b;
    cout<<"\nEnter your choice:-";
    cin>>c;
    switch(c){
        case 1 :
            total=a+b;
            cout<<"total is: "<<total << endl; 
            break;
        case 2 :
            total=a-b;
            cout<<"total is: "<<total << endl; 
            break;
        case 3 :
            total=a*b;
            cout<<"total is: "<<total << endl; 
            break;
        case 4 :
            total=a/b;
            cout<<"total is: "<<total << endl;    
            break;
        }
        

    }
    


