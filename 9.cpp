/*Assignment_31
*
*Write a C++ program to implement the following class hierarchy:
*
* Student: id, name
* StudentExam (derived from Student): Marks of 6 subjects
* StudentResult (derived from StudentExam) : percentage
*
* Define appropriate functions to accept and display details.
*
* Create 'n' objects of the StudentResult class and display the marklist.
* Author: Virendra Kumar
* Date:- 26 Dec 2022*/

#include<iostream>
#include<cstring>
using namespace std;
class Student
{
  private: 
   int id;
   char name[20];
  public:
   void setId()
   {
     int i;
     cout<<"\nEnter ID: ";
     cin>>id;
   }
   int getId()
   {
     return id;
   }
   void setName()
   {
     cout<<"\nEnter Name: ";
     cin.ignore();
     fgets(name,20,stdin);
   }
   char* getName()
   {
     return name;
   }
   
};

class StudentExam: public Student
{
  protected:
   int subject1, subject2, subject3, subject4, subject5, subject6;
  public:
   
};

class StudentResult: public StudentExam
{
  private: 
    double percentage;
  public:
    void summitMarks(StudentResult p[], int a, int b)
    {
      cout<<a+1<<" Enter Student Details: "<<endl;
      cout<<"-----------------------------"<<endl;
      p[a].setId();
      p[a].setName();
      cout<<"\nEnter Marks in Math: ";
      cin>>subject1;
      cout<<"\nEnter Marks in English: ";
      cin>>subject2;
      cout<<"\nEnter Marks in Science: ";
      cin>>subject3;
      cout<<"\nEnter Marks in Social-Science: ";
      cin>>subject4;
      cout<<"\nEnter Marks in Hindi: ";
      cin>>subject5;
      cout<<"\nEnter Marks in Sanscrit: ";
      cin>>subject6;
     }
     
     void display(StudentResult p[], int i)
     {
       cout<<i+1<<" Student Result:"<<endl;
       cout<<"----------------------"<<endl;
       cout<<"ID 	 : "<<p[i].getId()<<endl;
       cout<<"Name       : "<<p[i].getName();
       cout<<"Math	    : "<<subject1<<endl;
       cout<<"English	    : "<<subject2<<endl;
       cout<<"Science	    : "<<subject3<<endl;
       cout<<"Social-Science: "<<subject4<<endl;
       cout<<"Hindi	    : "<<subject5<<endl;
       cout<<"Sanscrit	    : "<<subject6<<endl;
       int total=subject1+subject2+subject3+subject4+subject5+subject6;
       percentage=total/6.0;
       cout<<"Percentage : "<<percentage<<"%"<<endl;
     }
  
};

int main()
{
 int n;
 cout<<"\nEnter the number of students, Do you want to show their results: ";  
 cin>>n;
 StudentResult s[n];
 for(int i=0; i<n; i++)
 {
   s[i].summitMarks(s,i,n);
 }
 for(int i=0; i<n; i++)
 {
   s[i].display(s,i);
 }
 return 0;
}

