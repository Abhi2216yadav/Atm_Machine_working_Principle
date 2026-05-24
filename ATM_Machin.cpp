//ATM Machine working code

#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

struct User{
    string name;
    int pin;
    double amount;
    string BankName;

    User(string n, int p, double a, string Bn){
        name = n;
        pin = p;
        amount = a;
        BankName = Bn;
    }
};
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
int pinno(){
    int pin;
    cout<< "\nEnter your 4 Digit pin : ";
    cin>>pin;
    return pin;
}

void withdrawal(string name, User& user1,User& user2){
    double val;
    cout<< "Enter amount : ";
    cin>>val;

    int pin = pinno();
    if(name == user1.name){

        if(pin == user1.pin){
            
            if(val <= user1.amount){
                cout<< "\nYour " << user1.BankName<< " Bank is Debited by : "<<val<< " Rs.."<<endl;
                user1.amount -= val;
            }else{
                cout<<"\n Sorry !, You don`t have Enough Balance"<<endl;
            }

        }else{
            cout<< "Wrong pin ! Try Again.. "<<endl;
        }

    }else if(name == user2.name){
    
        if(pin == user2.pin){
            
            if(val <= user2.amount){
                cout<< "\nYour " << user2.BankName<< " Bank is Debited by : "<<val<< " Rs.."<<endl;
                user2.amount -= val;
            }else{
                cout<<"\n Sorry !, You don`t have Enough Balance"<<endl;
            }
        
        }else{
            cout<< "Wrong pin ! Try Again.. "<<endl;
        }
    }else{
        cout<< "User name not found ..."<<endl;
    }
}

void  deposite(string name, User& user1,User& user2){
    double val;
    cout<< "Enter amount : ";
    cin>>val;

    int pin = pinno();

    if(name == user1.name){

        if(pin == user1.pin){
            cout<< "\nYour " << user1.BankName<< " Bank is credited by : "<<val<< " Rs.."<<endl;
            user1.amount += val;

        }else{
            cout<< "Wrong pin ! Try Again.. "<<endl;
        }
    
    }else if(name == user2.name){

        if(pin == user2.pin){
            cout<< "\nYour " << user2.BankName<< " Bank is credited by : "<<val<< " Rs.."<<endl;
            user2.amount += val;
        }else{
            cout<< "Wrong pin ! Try Again.. "<<endl;
        }
    }else{
        cout<<"User name not found .."<<endl;
    }
}

void checkAmount(string name, User& user1,User& user2){
    int pin = pinno();
    if(name == user1.name){

        if(pin == user1.pin){

            cout<< "\nYour " << user1.BankName<< " Bank Balance is : "<<user1.amount<< " Rs.."<<endl;
        }else{
            cout<< "Wrong pin ! Try Again.. "<<endl;
        }

    }else if(name == user2.name){

        if(pin == user2.pin){

            cout<< "\nYour " << user2.BankName<< " Bank Balance is : "<<user2.amount<< " Rs.."<<endl;
        }else{
            cout<< "Wrong pin ! Try Again.. "<<endl;
        }
    }else{
        cout<<"User name not found .."<<endl;
    }
}

int main(){
    int ch;
    string name;

    User user1("Abhay Yadav", 1122, 70000, "Bank Of Baroada");
    User user2("Ajay Yadav", 1234, 100000, "HDFC Bank");

    cout<< "\n -->> Welcome to ATM Machine <<-- "<<endl;

    cout<< "\nEnter Bank Holder name as given in your Card : ";
    getline(cin, name);
    
    while(1){

        cout<< "\n1. Widrawal Money "<<endl;
        cout<< "2. Deposite Money" <<endl;
        cout<< "3. Check Amount" << endl;
        cout<< "4. Cancl Transection"<<endl;
        cout<< "Enter your choice : ";
        cin>>ch;

        switch(ch){

            case 1: withdrawal(name, user1, user2); break;

            case 2: deposite(name,  user1, user2); break;

            case 3: checkAmount(name,  user1, user2); break;
                 
            case 4: cout<< "\nThanks for Visiting ! Have a good day."<<endl;
                exit(0); 
                break;

            default : cout<< "\nEnter valid number"<<endl; break;
        }
    }
    return 0;
}
/* Output as you wish..
 -->> Welcome to ATM Machine <<-- 

Enter Bank Holder name as given in your Card : Ajay Yadav

1. Widrawal Money
2. Deposite Money
3. Check Amount
4. Cancl Transection
Enter your choice : 1
Enter amount : 20000

Enter your 4 Digit pin : 1234

Your HDFC Bank Bank is Debited by : 20000 Rs..

1. Widrawal Money
2. Deposite Money
3. Check Amount
4. Cancl Transection
Enter your choice : 2
Enter amount : 12000

Enter your 4 Digit pin : 1233
Wrong pin ! Try Again.. 

1. Widrawal Money
2. Deposite Money
3. Check Amount
4. Cancl Transection
Enter your choice : 2
Enter amount : 12000

Enter your 4 Digit pin : 1234

Your HDFC Bank Bank is credited by : 12000 Rs..

1. Widrawal Money
2. Deposite Money
3. Check Amount
4. Cancl Transection
Enter your choice : 3

Enter your 4 Digit pin : 1231
Wrong pin ! Try Again.. 

1. Widrawal Money
2. Deposite Money
3. Check Amount
4. Cancl Transection
Enter your choice : 3

Enter your 4 Digit pin : 1234

Your HDFC Bank Bank Balance is : 92000 Rs..

1. Widrawal Money
2. Deposite Money
3. Check Amount
4. Cancl Transection
Enter your choice : 4

Thanks for Visiting ! Have a good day.*/