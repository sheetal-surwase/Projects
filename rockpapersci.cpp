#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
int main()
{
    int user=0;
    int cpu=0;
    srand(time(NULL));
    cout<<"ROCK PAPER SCISSORS GAME"<<endl;
    cout<<"1] Rock"<<endl;
    cout<<"2] Paper"<<endl;
    cout<<"3] Scissors"<<endl;
    cout<<"Choose the option no : ";
    cin>>user;
    if(user==1)
    {
        cout<<"you have choose rock!"<<endl;
    }
    else if(user==2)
    {
        cout<<"you choose paper"<<endl;
    }
    else
    {
        cout<<"you choose scissors"<<endl;
    }
    cpu=rand()%3+1;
    if(cpu==1)
    {
        cout<<"cpu chooses rock!"<<endl;
    }
    else if(cpu==2)
    {
        cout<<"cpu chooses paper"<<endl;
    }
    else
    {
        cout<<"cpu chooses scissors"<<endl;
    }
    if(user==cpu)
    {
        cout<<"It's a tie"<<endl;
    }
    else if(user==1)
    {
        if(cpu==2)
        {
            cout<<"you lose!"<<endl;
        }
        if(cpu==3)
        {
            cout<<"you win!"<<endl;
        }
    }
    else if(user==2)
    {
        if(cpu==1)
        {
            cout<<"you win!"<<endl;
        
        }
        if(cpu==3)
        {
            cout<<"you lose!"<<endl;
        }
    }
    else if(user==3)
    {
        if(cpu==1)
        {
            cout<<"you lose!"<<endl;
        
        }
        if(cpu==2)
        {
            cout<<"you win!"<<endl;
        }
    }

    return 0;
}