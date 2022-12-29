/*Write a cpp program to calculate the percentage of a student using multi-level inheritance. Accept the marks of three subjects in base class. A class will be derived from the above mentioned class which includes a function to find the total obtained marks and another class which calculates and displays the percentage of students.*/

#include<iostream>
using namespace std;
class Subjects			//subject class 
{
  private:	 		//private members
   int mathMarks;		
   int phyMarks;		
   int cheMarks;		
  public:			//public members
   void setMarks(int m, int p, int c)
   {
    // cout<<"setMarks() called"<<endl;
    mathMarks=m; phyMarks=p; cheMarks=c;
   }
  protected:
   int getMathMarks()
   {
     //cout<<"get1 called."<<endl;
     return mathMarks;
   }
   int getPhyMarks()
   {
     //cout<<"get2 called."<<endl;
     return phyMarks;
   }
   int getCheMarks()
   { 
     //cout<<"get3 called."<<endl;
     return cheMarks;
   }
};

class Marks: public Subjects		//class Marks inherited from Subjects class
{
  private:
   double total;
  public:
   int getTotal()
   { 
     //cout<<"getTotal() called."<<endl;
     total=getMathMarks()+getPhyMarks()+getCheMarks();
     return total;
   }
};

class Result: public Marks		//class Result inherited from Marks class
{
   private:
    int total;
    double res;
   public:
    void setTotalMarks(int a)
    {
      total=a;
      //cout<<"set2 called."<<total<<endl;
    }
    double result()
    {
      double temp=getTotal()*100;
      res=(temp/total);
      //cout<<"result() called."<<res<<temp<<endl;
      return res;
    }
};

int main()
{
  Result s1;
  int m,p,c,t;
  cout<<"All marks' max value is 100\nThis is result of three subjects only. "<<endl;
  cout<<"\nEnter the total marks: ";
  cin>>t;
  cout<<"\nEnter the obtained marks in Math, Physics and Chemistry: ";
  cin>>m>>p>>c;
  try
  {
    if(m<0 || p<0 || c<0)
       throw 1;
    else if(m>100 || p>100 || c>100 )
       throw 2;
    else
        s1.setMarks(m,p,c);        
     }
     catch (int a)
     {
       if(a==1)
         cout<<"Please, enter correct marks.\n Marks must be >= 0...Error.."<<a<<endl;
       else
         cout<<"Please, enter correct marks.\n Marks must be <= 100...Error.."<<a<<endl;
       return 0;
     }
     catch(...)
     {
       cout<<"Unknown Error!!..."<<endl;
     }
  
  s1.setTotalMarks(t);
//the below code are only for print grade only  
  int choice=(int)s1.result();
  cout<<"Your result  : "<<s1.result()<<"%"<<endl;
  switch(choice)
  {
    case 95 ... 100:
      cout<<"Weldone!! You have got 'A++' grade."<<endl;
      break;
    case 90 ... 94:
      cout<<"Congrats!! You have got 'A' grade."<<endl;
      break;
    case 80 ... 89:
      cout<<"Wow!! You have got 'B++' grade."<<endl;
    case 60 ... 79:
      cout<<"Very Good!! You have got 'B' grade."<<endl;
      break;
    case 40 ... 50:
      cout<<"Good!! You have got 'c' grade."<<endl;
      break;
    default:
      cout<<"Sorry Dear!! \nYou Failed, Try again."<<endl;
      break;
      
  }
  
  return 0;
}
