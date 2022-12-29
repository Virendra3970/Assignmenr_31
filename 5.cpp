/*Assignment_31
*
* Question:-
*
* Write a C++ program to define a base class Item (item-no, name, price). Derive a class Discounted-Item (discount-percentage).  A customer purchases 'n' items. Display the item-wise bill and total     												amount using appropriate formate.
*
*Author: Virendra Kumar*/

#include<iostream>
#include<cstring>
using namespace std;
class Item		  //Item class
{
  private:		 //private members
   int itemNo;
   char name[50];
   double price;

  public:		//public members
   void setItemName()	//this is used to set name of Item object
   {
     cout<<"\nItem Name: ";
     cin.ignore();		//this is used for empty the input buffer
     fgets(name,50,stdin);
     
     for(int i=0; i<strlen(name)-1; i++)	//Exception handling in Item Name
     {
       try
       {
          if(name[i]>=65 && name[i]<=90 || name[i]>=97 && name[i]<=122 || name[i]==' ')
            continue;
          else
            throw 101;
       }
       catch(int a)
       {
          cout<<"Please, enter a valid Item name....Error"<<a<<endl;
          exit(0);
       }
       catch(...)
       {
          cout<<"Unexpected error.."<<endl;
          exit(0);
       }
     }
   }
   
   char* getItemName()			//this function will return the address of Item name
   {
     return name;
   }
   
   void setItemNo()			//this will set Item Id 
   {
      cout<<"\nItem Id: ";
      cin>>itemNo;
      try				//Exception Handling of Item Id
      {
        if(itemNo<=0)
          throw 201;
      }
      catch(int a)
      {
        cout<<"Please, Enter a valid Item id...Error"<<a<<endl;
        exit(0);
      }
      catch(...)
      {
        cout<<"Unexpected Error"<<endl;
        exit(0);
      }
   }
   
   int getItemNo()			//this will return the itemNo
   {
     return itemNo;
   }
   
   void setPrice()			//this will set the Item price
   {
     cout<<"\nItem Price: ";
     cin>>price;
     try				//Exception Handling for Item Price
     {
       if(price<0)
         throw 202;
     }
     catch(int a)
     {
       cout<<"Please, Enter a valid price...Error"<<a<<endl;
     }
     catch(...)
     {
       cout<<"Unexpected error"<<endl;
       exit(0);
     }
   }
   
   double getPrice()			//this will return the price of Item
   {
     return price;
   }
};

class Discounted_Item: public Item		//Derived Discounted_Item class inherites the Item class properties and methods
{
  private:				//private members of Discounted_Item
   double perDiscount;
  protected:
   //double total=0, td=0;
  public:				//public members of Discounted_Item
    void itemList(Discounted_Item i[], int k)		//this function will set itemId, itemName, price and %-discount
    {
      i[k].setItemNo();
      i[k].setItemName();
      i[k].setPrice();
      cout<<"\nEnter item %. discount: ";
      cin>>perDiscount;
      try				//Exception Handling for %-discount
      {
        if(perDiscount<0)
          throw 202;
      }
      catch(int a)
      {
        cout<<"Please, Enter a valid %. discount...Error"<<a<<endl;
      }
      catch(...)
      {
        cout<<"Unexpected error"<<endl;
        exit(0);
      }
    }
  
   void display(Discounted_Item i[], int k)		//this will display the Item details
   {
     cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
     cout<<"\nItem No              : "<<i[k].getItemNo()<<endl;
     cout<<"\nItem Name            : "<<i[k].getItemName();
     cout<<"\nItem Price           : "<<i[k].getPrice()<<"Rs/-"<<endl;
     cout<<"\nPercentage Discount  : "<<perDiscount<<"%"<<endl;
   }
   
   void calculator(Discounted_Item i[], int j, int k)		//this will calculate the total bill
   {
     double total=total+i[j].getPrice();
     double td=td+(i[j].getPrice()*perDiscount)/100;
     if((j+1)==k)
     {
       cout<<"\nBill Details: "<<endl;
       cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
       cout<<"\nTotal amount(without discount): "<<total<<"Rs/-"<<endl;
       cout<<"\nTotal Discount: "<<td<<"Rs/-"<<endl;
       cout<<"\nTotal amout(with discount): "<<total-td<<"Rs/-"<<endl;
     }
   } 
};

int main()
{
 int a;			
 cout<<"\nEnter no of Item, Do you want to buy? ";		//no of total Items
 cin>>a;
 Discounted_Item d[a]; 
 for(int i=0; i<a; i++)
 {
   cout<<"\nEnter "<<i+1<<" item details: "<<endl;
   d[i].itemList(d,i);
 }
 for(int j=0; j<a; j++)
 {
  cout<<"\n"<<j+1<<" item details: "<<endl<<endl;
  d[j].display(d,j);
 }
 for(int i=0; i<a; i++)
 {
   d[i].calculator(d,i,a);
 }
 return 0;
}
