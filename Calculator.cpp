#include <iostream>
#include <math.h>

using namespace std;

class calc{
double num1,num2;

public:

calc(){
    num1=0;
    num2=0;
}
void input(){
    cout<<"Enter First Number: ";
    cin>>num1;
    cout<<"Enter Second Number: ";
    cin>>num2;
}

void add(){
    cout<<num1<<" + "<<num2<<" = "<<num1+num2<<endl;
}

void sub(){
    cout<<num1<<" - "<<num2<<" = "<<num1-num2<<endl;
}

void mul(){
    cout<<num1<<" * "<<num2<<" = "<<num1*num2<<endl;
}

void div(){
    if(num2!=0)
    cout<<num1<<" / "<<num2<<" = "<<num1/num2<<endl;
    else
    cout<<"Math Eroror"<<endl;
}
};

int main(){
    calc one;
    one.input();
    char operation;
    cout<<"Enter Operation (+,-,*,/):  ";
    cin>>operation;
    switch(operation){
        case '+':
        {
            one.add();
            break;
        }
        case '-':
        {
            one.sub();
            break;
        }
        case '*':
        {
            one.mul();
            break;
        }
        case '/':
        {
            one.div();
            break;
        }
        default:
            cout<<"Invalid Operaion.";
            break;
    }

    return 0;
}
