/*Write a C++ program to demonstrate how a common friend function can be used exchange the private values of two classes.(Use call by rederence method).*/

#include<iostream>
using namespace std;
//declaration of derived class 

class Derived;

//defining base class

class Base
{
  //private members of Base class
  private:				
   int a,b;
  //public members of Base class 
  public:				
  
  friend void swap(Base&, Derived&);	//declaration of swap() as a friend 
 
  void setData()			//setData() function for Base class
  {
    cout<<"\nEnter two numbers: ";
    cin>>a>>b;
  }
  
  void display()			//display() function for Derived class
  {
    cout<<"a= "<<a<<", b= "<<b<<endl;
  }	
 
  Base(){}				//default constructor
 
  Base(int a, int b)			//parameterized constructor
  { this->a=a; this->b=b;}
  
};

//defintion of Derived Class

class Derived: public Base
{
//private members of Derived class
  private: 				
   int x, y;
//public members of Derived class 
  public: 				
   friend void swap(Base&, Derived&);	//declaration of swap() as a friend
 
  void setData()			//setData() function for Derived class
  {
    cout<<"\nEnter two numbers: ";
    cin>>x>>y;
  }
  
  void display()			//display() function for derived class
  {
    cout<<"x= "<<x<<", y= "<<y<<endl;
  }

  Derived(){}				//default construtor

  Derived(int x, int y)			//parameterized constructor
  { this->x=x; this->y=y;}
  
};

//definition of swap() function which is friend to both above classes

void swap(Base &b, Derived &d)
{
  //Create logic to swap objects of Base and Derived classes
  int i,j;				//these are temparary variables 
  i=b.a;
  j=b.b;
 
  b.a=d.x;
  b.b= d.y;
  
  d.x=i;
  d.y=j;
}

int main()
{
  Base b1;
  Derived d1;
//setData for both objects
  b1.setData();
  d1.setData();
//Before swapping 
  cout<<"Before Swapping: "<<endl;
  b1.display();
  d1.display();   
  swap(b1,d1);
//After swapping
  cout<<"After swapping: "<<endl;
  b1.display();
  d1.display();  
  return  0;
}
