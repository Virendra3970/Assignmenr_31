/*Write a cpp program to add two numbers using single inheritance. Accept these two numbers from the user in base class and display the sum of these two numbers in derived class*/

#include<iostream>
using namespace std;
class Base				//Base class
{
  private:				//private members
   int a,b;
  
  public:				//public members
   void setNumbers(int a, int b) 	//setNumber() is used to store two numbers
   {
     this->a=a;
     this->b=b;
   }
};

class Derived: public Base		//Derived class inherited from Base class
{
  private:				//private members
    int sum=0;
 
  public:				//public members
    void displaySum(int a, int b) 	//To display the sum of entered numbers
    {					
      this->setNumbers(a,b);
      sum=a+b;				//setNumbers() is invoked by this poointer which contains the address of Derived object
      cout<<"\nSum is : "<<sum<<endl;
    }
};

int main()
{
  Derived d1;
  int a, b;
  cout<<"\nEnter First number: ";	//Input first number
  cin>>a;
  cout<<"\nEnter Second number: ";	//Input second number
  cin>>b;				
  d1.displaySum(a,b);			//DisplaySum() is invoked by derived object.
  return 0;
}
