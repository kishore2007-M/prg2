#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Account
{
    public:
        int accountNo;
        string Name;
        string accountType;
        double balance;
}; 
vector<Account>accounts;
bool login()
{
     string username,password;

    for(int i=0;i<3;i++)
    {
        cout<<"\nUsername: ";
        cin>>username;
        cout<<"\npassword: ";
        cin>>password;

        if(username=="Kishore" && password=="1234")
        {
              cout<<"\nLogin Successfully...!";
              return true;
        }
    cout<<"\nLogin Unsuccessfull  and Attempt Lefts..."<< 2-i <<endl;
    }
    return false;
}
void createAccount()
{
    Account a;
    cout<<"\nEnter the Account Number: "<<endl;
    cin>>a.accountNo;
    for (int i=0;i<accounts.size();i++)
    {
        if(accounts[i].accountNo==a.accountNo)
        { 
           cout<<"\nAccount number Already Contained: ";
           return;
        }
    }
    cout<<"\nEnter the customer Name: "<<endl;
    cin>>a.Name;

    cout<<"\nEnter the Account Type(Current/Savings): "<<endl;
    cin>>a.accountType;

    cout<<"\nEnter the balance: "<<endl;
    cin>>a.balance;

    accounts.push_back(a);

    cout<<"\nAccount Created Successfully !!..."<<endl;
    cout<<"\n================================================";

}
void veiwAccounts()
{
    if(accounts.empty())
    {
        cout<<"Accounts not found...";
        return;
    }
    cout<<"Accounts Available..";
    for(int i=0;i<accounts.size();i++)
    {
        cout<<"\n===============Accounts Full Information==================";

        cout<<"\nAccount number: "<<accounts[i].accountNo;
        cout<<"\nCustomer Name: "<<accounts[i].Name;
        cout<<"\nAccount Type: "<<accounts[i].accountType;
        cout<<"\nBalance: "<<accounts[i].balance;

        cout<<"\n===========================================================";
    }
}
void depositMoney()
{
    int accountno;
    double amount;

    cout << "\nEnter the Account Number: ";
    cin >> accountno;

    for(int i=0;i < accounts.size();i++)
    {
        if(accounts[i].accountNo==accountno)
        {
            cout<<"Enter the Deposit amount: "<<endl;
            cin>>amount;
            
            accounts[i].balance +=amount;

            cout<<"\nDeposit Amount Added Successfully..";
            cout<<"\nCurrent Balance Amount: "<<accounts[i].balance<<endl;
            return;
        }
    }
    cout<<"\nAccount not Found...";

}
void withdrawmoney()
{
    int accountno;
    double amount;

    cout << "\nEnter the Account Number: ";
    cin >> accountno;

    for(int i=0;i < accounts.size();i++)
    {
        if(accounts[i].accountNo==accountno)
        {
            cout<<"Enter the withdraw amount: "<<endl;
            cin>>amount;
           if(amount>accounts[i].balance)
            {
                cout<<"\nInsufficent amount!..";
            }
              
            accounts[i].balance -=amount;

            cout<<"\nDeposit Successfully..";
            cout<<"\nRemainning Balance Amount: "<<accounts[i].balance<<endl;
            return;
        }
    }
    cout<<"\nAccount not Found...";

}
void searchaccount()
{
    int accountNo;
    cout<<"\nEnter the Account number: ";
    cin>>accountNo;
    for(int i=0;i<accounts.size();i++)
    {
        if(accounts[i].accountNo==accountNo)
        {
            cout << "\nAccount Found!";
            cout << "\nAccount Number : " << accounts[i].accountNo;
            cout << "\nCustomer Name  : " << accounts[i].Name;
            cout << "\nAccount Type   : " << accounts[i].accountType;
            cout << "\nBalance        : " << accounts[i].balance;
            return;
        }
    }
}
void deleteaccount()
{
    int accountNo;
    cout<<"Enter the account number: ";
    cin>>accountNo;
    for(int i=0;i<accounts.size();i++)
    {
        if(accounts[i].accountNo==accountNo)
        {
            accounts.erase(accounts.begin() +i);
            cout<<"\nAccount Deleted Asuccessfully..!!";
            return;
        }
    }
    cout<<"\nInvalid Account..."<<endl;
}
int main()
{
    int choice;
    if(!login())
    {
        cout << "\nToo Many Failed Attempts!";
        return 0;
    }
    
    
    do
    {
        cout<<"\n\n=========BANK MANAGEMENT System==============\n";
        cout<<"1.Create Account\n";
        cout<<"2.view Account\n";
        cout<<"3.Deposit Money\n";
        cout<<"4.Withdarw Money\n";
        cout<<"5.Search Account\n";
        cout<<"6.Delete Account\n";
        cout<<"7.Exit.....\n";

        cout<<"\nEnter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                createAccount();
                break;
            case 2:
                veiwAccounts();            
                break;
            case 3:
                depositMoney();
                break;
            case 4:
                withdrawmoney();
                break;
            case 5:
                searchaccount();
                break;
            case 6:
                deleteaccount();
                break;
            case 7:
                cout << "\nThank You...";
                 break;
            default:
                cout<<"\nInvalid Choice"<<endl;
                break;
        }
    }while (choice !=7);
    return 0;
    
}