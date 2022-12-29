/*Assignment_31
*Question: 
*Write class declarations and member function definitions for a C++ base class to represent an *Employee(emp-code, name).
*
*Derive two classes as Fulltime (daily rate, number of days, salary) and Parttime(number of *working hours, hourly rate, salary).
*
*Write a memu driven program to:
* 1. Accept the details of 'n' employees.
* 2. Display the details of 'n' employees
* 3. Search a given Employee by emp-code.
*Author: Virendra Kumar
*Date-: 26-Dec-2022*/
 
#include<iostream>
#include<cstring>
using namespace std;
class Employee			//employee class
{
  protected:			//private members
   int emp_code=0;
   char name[50]="Garbage";
  public:			//public members
   void setId()			//this is used to set emp_Code of Employee
   {
     cout<<"\nEnter Id: ";
     cin>>emp_code;
   }
   
   void setName()		//this is used to set employee Name
   {
     cout<<"\nEnter Name:";
     cin.ignore();		//this is used to vacant input buffer
     fgets(name,50,stdin);
   }
   
   char* getName()		//this will return the address of name
   { return name; }
   
   int getId()			//this will return the emp_code
   { return emp_code; }
   
};

class Fulltime: public Employee		//Fulltime class inherites the employee class
{
  protected:			//protected members
   int dailyRate=0;
   int noDays=0;
   int salary=0;
  public:			//public members
   void details(Fulltime e[],int i)		//this will set the details of Fulltime employee 
   {
     this->setId();
     try			//exception handling for emp_code
     {
       if(emp_code<=0)
         throw 101;
       
     }
     catch(int a)
     {
       cout<<"Please, Enter a valid emp_code...Error"<<a<<endl;
       exit(0);
     }
     catch(...)
     {
       cout<<"Unexpected Error.."<<endl;
       exit(0);
     }

     this->setName();
     for(int i=0; i<strlen(name)-1; i++)	//Exception Handing for employee name
     {
       try
       {
         if((name[i]>=65 && name[i]<=90) || (name[i]>=97 && name[i]<=122) || (name[i]==' '))
            continue;
         else
             throw 201;
       }
       catch(int a)
       {
         cout<<"Please, Enter a valid name...Error"<<a<<endl;
         exit(0);
       }
       catch(...)
       {
         cout<<"Unexpected Error..."<<endl;
         exit(0);
       }
     }
     cout<<"\nEnter daily rate: ";
     cin>>dailyRate;
     try			//exception handling for dailyRate
     {
       if(dailyRate<0)
         throw 102;
     }
     catch(int a)
     {
       cout<<"Please, Enter a valid dailyRate...Error"<<a<<endl;
       exit(0);
     }
     catch(...)
     {
       cout<<"Unexpected Error.."<<endl;
       exit(0);
     }
     cout<<"\nEnter number of working days: ";
     cin>>noDays; 
     try			//exception handling for working days
     {
       if(noDays<=0)
         throw 103;
     }
     catch(int a)
     {
       cout<<"Please, Enter valid value for working days...Error"<<a<<endl;
       exit(0);
     }
     catch(...)
     {
       cout<<"Unexpected Error.."<<endl;
       exit(0);
     }
     salary=noDays*noDays;
   }
   
   void display()	//this will print the name, id and salary of Fulltime employee 
   {
     cout<<"ID: "<<this->getId()<<endl;
     cout<<"Name: "<<this->getName();
     if(!strcmp(this->getName(),name))
        cout<<endl;
     cout<<"Salary: "<<salary<<"Rs/-"<<endl;
   }
   
   int search(int i)
   {
     if(this->getId()==i)
       return 1;
   }
};

class Parttime: public Employee		//Parttime class inherites the Employee class
{
  protected:				//protected members
   int workingHours=0;
   int hRate=0;
   int salary=0;
  public:				//public members
    void details(Parttime e[], int i)			//this will set the details of Parttime employees
   {
     this->setId();
     try			//exception handling for emp_code
     {
       if(emp_code<=0)
         throw 101;
       
     }
     catch(int a)
     {
       cout<<"Please, Enter a valid emp_code...Error"<<a<<endl;
       exit(0);
     }
     catch(...)
     {
       cout<<"Unexpected Error.."<<endl;
       exit(0);
     }

     this->setName();
     for(int i=0; i<strlen(name)-1; i++)	//Exception Handing for employee name
     {
       try
       {
         if((name[i]>=65 && name[i]<=90) || (name[i]>=97 && name[i]<=122) || (name[i]==' '))
            continue;
         else
             throw 201;
       }
       catch(int a)
       {
         cout<<"Please, Enter a valid name...Error"<<a<<endl;
         exit(0);
       }
       catch(...)
       {
         cout<<"Unexpected Error..."<<endl;
         exit(0);
       }
     }
     cout<<"\nEnter number of working hours: ";
     cin>>workingHours;
     try			//exception handling for working_Hours
     {
       if(workingHours<=0)
         throw 104;
     }
     catch(int a)
     {
       cout<<"Please, Enter a valid value for working hours...Error"<<a<<endl;
       exit(0);
     }
     catch(...)
     {
       cout<<"Unexpected Error.."<<endl;
       exit(0);
     }
     cout<<"\nEnter hour rate: ";
     cin>>hRate;
     try			//exception handling for Hour Rate
     {
       if(hRate<=0)
         throw 105;
     }
     catch(int a)
     {
       cout<<"Please, Enter a valid value for Working hour rate...Error"<<a<<endl;
       exit(0);
     }
     catch(...)
     {
       cout<<"Unexpected Error.."<<endl;
       exit(0);
     } 
     salary=workingHours*hRate;
   }
   void display()			//this is used to print the details of Parttime employees
   {
     
     cout<<"ID: "<<this->getId()<<endl;
     cout<<"Name: "<<this->getName();
     if(!strcmp(this->getName(),name))
        cout<<endl;
     cout<<"Salary: "<<salary<<"Rs/-"<<endl;
   }
   
   int search(int i)
   {
     if(this->getId()==i)
       return 1;
   }
};

int main()
{
  int choice;
  int n1;
  while(1)
  {
    cout<<"\nEnter how many details, do you want to add: ";
    cin>>n1;
    Fulltime e[n1]; Parttime e1[n1];
    cout<<"1. Accept the details of 'n' employees: "<<endl;
    cout<<"2. Display the details of 'n' employees: "<<endl;
    cout<<"3. Search a given employee by emp_code: "<<endl;
    cout<<"\nEnter your choice: ";
    cin>>choice;
    switch(choice)		//switch statements
    {
      case 1:
         cout<<"There are two types of employees:- "<<endl;
         cout<<"1. Full Time Employee"<<endl;
         cout<<"2. Part Time Employee"<<endl;
         int ch;
         cout<<"Enter which details, do you want to add: ";
         cin>>ch;
         if(ch==1)
         {
           for(int i=0; i<n1; i++)
           {
             cout<<i+1<<" Full Time Employee Details: "<<endl;
             e[i].details(e,i);
           }
         }
         else if(ch==2)
         {
           Parttime e[n1];
           for(int i=0; i<n1; i++)
           {
             cout<<i+1<<" Part Time Employee Details: "<<endl;
             e[i].details(e,i);
           }
          }
         else
         {
           cout<<"Please, Enter valid choice.\nTry Again!!!"<<endl;
           return 0;
         }
         break;
      case 2:
         cout<<"There are two types of employees:- "<<endl;
         cout<<"1. Full Time Employee"<<endl;
         cout<<"2. Part Time Employee"<<endl;
         int ask;
         cout<<"Enter which details, do you want to display: ";
         cin>>ask;
         if(ask==1)
         {
           cout<<"\nEnter how many details, do you want to add: ";
  	   cin>>n1;   
           cout<<"\nEnter how many details, do you want to display: ";
           cin>>n1;
           Fulltime e[n1];
           for(int i=0; i<n1; i++)
           {
             cout<<i+1<<". Full Time Employee Details: "<<endl;
             e[i].display();
           }
         }
         else if(ask==2)
         {
         
           cout<<"\nEnter how many details, do you want to display: ";
           cin>>n1;
           for(int i=0; i<n1; i++)
           {
             cout<<i+1<<". Part Time Employee Details: "<<endl;
             e1[i].display();
           }
          }
         else
         {
           cout<<"Please, Enter valid choice.\nTry Again!!!"<<endl;
           return 0;
          }
          break;
      case 3:
         int id;
         cout<<"Welcome in searching portal: "<<endl;
         cout<<"Enter employee's id to search: ";
         cin>>id;
         for(int i=0; i<n1; i++)
         {
           if(e[i].search(id))
           {
             e[i].display();
             exit(0);
           }
           else
           {
           if(e1[i].search(id))
           {
             e1[i].display();
             exit(0);
           }
          }
        }       
          break;
      default:
        cout<<"Please, Enter a valid choice.\n Try again!!!"<<endl;
        exit(0);
     }
    }
  return 0;
}
 
/*Note: private members ko initilize karne se matlab yah hai ki yadi by chance user details enter kiye bina display() function ko call karta hai to wahan par garbage na print ho*/
