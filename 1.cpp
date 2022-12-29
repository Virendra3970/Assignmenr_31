/*Define a class Person with instance members name and age. Also define member functions setName(), setAge(), getAge(). Now define class Employee by inheriting Person class. In the Employee class define empid and salary as instance members. Also define setEmpid, setSalary, getEmpid and getSalary. */

#include<iostream>
#include<cstring>
using namespace std;
class Person			//Person class
{
  private:			//private members
    int age;
    char name[50];
 
  public:			//public members
    void setName()		//this function will set the Name of employee
    {
      cout<<"\nEnter the employee name: ";
      cin.ignore();  
      fgets(name,50,stdin);
      for(int i=0; name[i]!='\n'; i++)
      {
        if(name[i]>='A' && name[i]<='Z' || name[i]>='a' && name[i]<='z' || name[i]==' ')
          continue;
        else{
          cout<<"Please, enter a valid name....\nMisuse of digits"<<endl;
		exit(0);}
      }
      cout<<endl;
    }
    void setAge()		// this function will set the age of employee
    {
      cout<<"\nEnter the employee's age: ";
      cin>>age;
      try
      {
        if(age<=0 || age<=14)
           throw 101;
      }
      catch(int a)
      {
        cout<<"Please, enter age greater than 14 years....Error "<<a<<endl; 
		exit(0);
      }
      catch(...)
      {
        cout<<"Unknown exception"<<endl;
        exit(0);
      }
      cout<<endl;
    }
    char* getName()		// this function will return the name of caller obj(employee)
    {
     return name;
    }
    int  getAge()		// this function will return the age of caller obj
    {
     return age;
    }
};

class Employee: public Person	//Employee class inherites Person publically
{
  private: 			//private members
   int salary;
   int empid;
  
  public:			//public members
   void setSalary()		//this function will set salary of employee
   {
     cout<<"\nEnter the employee's salary: ";
     cin>>salary;
     cout<<endl;
   }
   void setEmpId()		//this function will set the id of employee
   {
     cout<<"\nEnter the employee's empId: ";
     cin>>empid;
     if(empid<=0)
     {
       cout<<"Please, Enter other zero for empid"<<endl;
       exit(0);
     }
     cout<<endl;
   }
   int getSalary()		//this function will return the salary of caller obj
   {
     return salary;
   }
   int getEmpid()		//this function will return the empid of caller obj
   {
     return empid;
   }
   void details()		//this will print all the details of employee on the screen
   {
     cout<<"Employee's Details are: "<<endl;
     cout<<"Id     : "<<getEmpid()<<endl;	
     cout<<"Name   : "<<getName();
     cout<<"Salary : "<<getSalary()<<endl;
     cout<<"Age    : "<<getAge()<<endl;
   }
};

int main()			// mian() function
{
  Employee e1, e2;     		//these are two objects of Employee class 
  e1.setEmpId();		//this fuction is of Employee function
  e1.setName();			//this functin is inherited from Person class to Employee 
  e1.setAge();			//this function is inherited from Person class to Employee
  e1.setSalary();		//this is of Employee class
  e1.details();
  return 0;
}
