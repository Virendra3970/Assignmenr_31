/*Consider two base classes
worker(int code, char name, float salary),
officer(float DA, HRA)
class manger(float TA(is 10% of salary), gross salary) is derived from both base
classes and input and show n workers inforamtions.
Write necessary member functions.*/

#include<iostream>
#include<cstring>
using namespace std;
class Worker
{
  protected:
   int code;
   char name[50];
   float gsalary;
  public: 
};

class Officer
{
  protected:
   float DA;		//DA stands for Dearness Allowance(mahangai bhatta)
   float HRA;		//HRA stands for House Rent Allowance
  public:
   
};

class Manager: public Worker, public Officer
{ 
  private:
    float TA;
    float salary;		 //TA stands for Travel Allowance.TA is given 10% of salary
  public:
  //To take the details of worker and officer
  void details(Manager m[], int a, int j)
  { 
    cout<<"\nEnter "<<a+1<<" Worker information: _____________"<<endl;
    cout<<"\nEnter code: ";
    cin>>code;
    try
    {
      if(code<=0)
        throw 101;
      if(m[a].code==m[a-1].code)
        throw 102;
    }
    catch(int a)
    {
      if(a==101)
        cout<<"Please, Enter valid code. Error.."<<a<<endl;
      else
        cout<<"Id Codes can never same. Error.."<<a<<endl;
       exit(0);
    }
    
    cout<<"\nEnter the name: ";
    cin.ignore();
    fgets(name, 50, stdin);
    for(int i=0; i<strlen(name)-1; i++)
    {
      try
      {
        if(name[i]>='A' && name[i]<='Z' || name[i]>='a' && name[i]<='z' || name[i]==' ')
          continue;
        else
          throw 201;
      }
      catch(int a)
      {
        cout<<"Please, Enter a valid name. Error.."<<a<<endl;
        exit(0);
      }
    }
    
    cout<<"\nEnter DA: ";
    cin>>DA;
    try
    {
      if(DA<0)
        throw 301;
    }
    catch(int a)
    {
       cout<<"Please, Enter a valid DA. Error"<<a<<endl;
       exit(0);
    }
    cout<<"\nEnter HRA: ";
    cin>>HRA;
    try
    {
      if(HRA<0)
        throw 301;
    }
    catch(int a)
    {
       cout<<"Please, Enter a valid HRA. Error"<<a<<endl;
       exit(0);
    }
    cout<<"\nEnter TA: ";
    cin>>TA;
    try
    {
      if(TA<0)
        throw 301;
    }
    catch(int a)
    {
       cout<<"Please, Enter a valid TA. Error"<<a<<endl;
       exit(0);
    }
    cout<<"\nEnter the basic salary: ";
    cin>>salary;
    try
    {
      if(salary<0)
        throw 301;
    }
    catch(int a)
    {
       cout<<"Please, Enter a valid salary. Error"<<a<<endl;
       exit(0);
    }
  }
  
  void display(int b)
  {
    gsalary= salary+TA+DA+HRA;
    cout<<"\n"<<b+1<<" Worker iformation is: ____________________"<<endl;
    cout<<"\nName		: "<<name;
    cout<<"\nCode		: "<<code;
    cout<<"\nDA		: "<<DA<<"$/-";
    cout<<"\nHRA		: "<<HRA<<"$/-";
    cout<<"\nTA  n           : "<<TA<<"$/-";
    cout<<"\nGross Salary   : "<<gsalary<<"$/-"<<endl;
  }
};

int main()
{ 
  int a;
  cout<<"\nEnter, How many worker's information, Do you want? ";
  cin>>a;
  Manager m[a];
  for(int i=0; i<a; i++)
  {
    m[i].details(m,i,a);
  }
  for(int i=0; i<a; i++)
  {
    m[i].display(i);
  }
  return 0;
}
