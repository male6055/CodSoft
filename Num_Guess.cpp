#include <cstdlib>
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

class number_guess{

int upper_bound, lower_bound,num,user_guess;

public:

number_guess(){
    upper_bound=100;
    lower_bound=0;
}

void loading_bar() {
        cout << "\n         Choosing a random number";
        for (int i = 0; i < 10; i++) {
            cout << ".";
            cout.flush();
            Sleep(200); 
        }
        cout <<"\n"<< endl;
    }

int rand_num(){
    srand(time(0));
    cout<<"\nEnter a positive Lower Bound:";
    cin>>lower_bound;
    while(lower_bound<0){
        cout<<"Enter a valid Lower bound."<<endl;
        cout<<"Enter Lower Bound again:";
        cin>>lower_bound;
        
    }
    cout<<"Enter a positive Upper Bound:";
    cin>>upper_bound;
    while(upper_bound<0 || upper_bound<lower_bound){
        cout<<"Enter a valid Upper bound."<<endl;
        cout<<"Enter Upper Bound again:";
        cin>>upper_bound;
    }
    loading_bar();
    num=lower_bound+(rand()%(upper_bound-lower_bound+1));
    return num;
}

void check(){

    //int lives=7;
    
    while(true){
        cout<<"Enter You Guess:";
        cin>>user_guess;
    if (user_guess>num){
        cout<<"         You guessed it high."<<endl;
        // cout<<"             Lives left="<<lives<<endl;
    }
    else if(user_guess<num){
        cout<<"         You guessed it low. "<<endl;
        // cout<<"             Lives left="<<lives<<endl;
    }
    else{
    cout<<"             You guessed it right :)."<<endl;
    cout<<endl;
    return;
    }
    // lives --;
    }
    // if(lives==0){
    //     cout<<"Better Luck Next Time :)"<<endl;
    // }
}

};

int main(){
    number_guess one;
    
    one.rand_num();
    one.check();
    
return 0;
}