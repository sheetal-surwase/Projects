#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<ctime>
using namespace std;
const char pass[] = "0123456789!@#$%^&*()"
                    "abcdefghijklmnopqrstuvwxyz"
                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int string_length = sizeof(pass)-1;
int main(){
    int length = 0;
    cout<<"Enter length of your password :";
    cin>>length;
    cout<<"Your generated password is :";

    for( int i=0; i<length; i++)
    {
    cout<<pass[rand() % string_length];
    }
return 0;
}


