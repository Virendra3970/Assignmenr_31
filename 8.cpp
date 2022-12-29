/*Assignment_31
*Question: 
*In a bank, different customers have savings account. Some customers may
*have taken a loan from the bank. So bank always maintain information about
*bank depositors and borrowers.
*Design a Base class Customer (name, phone-number). Derive a class
*Depositor(accno, balance) from Customer.
*Again, derive a class Borrower (loan-no, loan-amt) from Depositor.
*Write necessary member functions to read and display the details of ‘n’ customers.
*Author: Virendra Kumar
*Date: 26 Dec 2022*/

#include<iostream>
using namespace std;
class Customer			//customer class(base class)
{
  private:			//private members
   char name[50];
   long long int phone;
  public:			//public members
   void setName()		//this will set customer's name
   {
     cout<<"\nEnter Customer's name: ";
     cin.ignore();		//used for input buffer
     fgets(name,50,stdin);
   }
   void setPhone()		//this will store customer's phone number
   {
     cout<<"\nEnter the mobile number: ";
     cin>>phone;
   }
   char* getName()		//this will return the address of name 
   {
     return name;
   }
   long long int getPhone()	//this will return customer's phone
   {
     return phone;
   }
  
};

class Depositor: public Customer	//Depositor class inherites by Customer class
{
   private:				//private members of Depositor class
    long long int accNo;
    long long int balance;
   public:				//public members of Depositor's class 
    void details(int i, Depositor d[])	//this will take all the details of Depositor
    {
      cout<<"Enter "<<i+1<<" Customer(Depositer) Details: "<<endl;
      d[i].setName();
      d[i].setPhone(); 
      cout<<"\nEnter Account Number: ";
      cin>>accNo;
      cout<<"\nEnter Balance: ";
      cin>>balance;
    }
    
    void display(int i, Depositor d[])		//this will display the details of a depositor
    {
      cout<<i+1<<" \nCustomer(Depositer) Details: "<<endl;
      cout<<"\nName: "<<d[i].getName();
      cout<<"\nPhone: "<<d[i].getPhone()<<endl;
      cout<<"\nAccount Number: "<<accNo<<endl;
      cout<<"\nCurrent Balance: "<<balance<<endl;
    }
    
};

class Borrower: public Depositor	//Borrower class inherited by Depositor class
{	
  private:				//private members
   long long int loan_No;
   long long int loan_amt;
  public:				//public members
    void details(int i, Borrower d[])	//this will take the inputs of Boorrower
    {
      cout<<"\nEnter "<<i+1<<" Customer(Borrower) Details: "<<endl;
      d[i].setName();
      d[i].setPhone(); 
      cout<<"\nEnter Loan Number: ";
      cin>>loan_No;
      cout<<"\nEnter Loan Amount: ";
      cin>>loan_amt;
    }
    
    void display(int i, Borrower d[])	//this will display the details of borrower
    {
      cout<<i+1<<" Customer(Borrower) Details: "<<endl;
      cout<<"\nName: "<<d[i].getName();
      cout<<"\nPhone: "<<d[i].getPhone()<<endl;
      cout<<"\nLoan Number: "<<loan_No<<endl;
      cout<<"\nCurrent Loan Amount: "<<loan_amt<<endl;
    }
    
};

int main()				//main fuction
{
  int n,choice;
  cout<<"\nEnter the number of Customers: ";
  cin>>n;
  Depositor d[n];	//array object of depositor
  Borrower b[n];	//array objects of borrower
  cout<<"1. Do you want to Depositers details. "<<endl;
  cout<<"2. Do you want to Borrower details. "<<endl;
  cout<<"3. Exit. "<<endl;
  cout<<"Enter your choice: ";
  cin>>choice;
  switch(choice)		//switch case statement
  {
   case 1:
   	for(int i=0; i<n; i++)  
        {
          d[i].details(i,d);
        }
        for(int i=0; i<n ;i++)
        {
          d[i].display(i,d);
        }
        break;
   case 2:
        for(int i=0; i<n; i++)  
  	{
  	  b[i].details(i,b);
  	}
  	for(int i=0; i<n ;i++)
  	{
  	  b[i].display(i,b);
  	}
  	break;
   case 3:
     	exit(0);
   default:
   	cout<<"Please, Enter a valid choice."<<endl;
   }
  return 0;
}
