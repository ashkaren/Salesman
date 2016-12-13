/****************************************************************************************** 
Program Name: Salesman.cpp
Programmer: Gennady Evtodiev
Class: CS 3335 A 
HW: 05   
Problem: 01
Date: 12/1/2016
******************************************************************************************/ 

#include <iostream>
#include <cstring>
using namespace std;

const int MAX_NAME = 20;
const int MAX_SALESMAN = 5;
const int NOT_FOUND = -1;

struct Seller
{
   float sales;               //running total of money he collected
   float time;                //running total of time, in hours
   char name[MAX_NAME + 1];   //name of the salesman
};

struct ListOfSalesman
{
   int num;                   //number of salesmen in the list
   Seller salesman[MAX_SALESMAN];
};

void InitSeller(Seller & s, const char name[]);
// Initializes the Salesman's name to name.
// Initializes the Salesman's sales and time to 0.0;

void UpdateSales(Seller & s, float sales, float time);
// Adds the money and time to the salesman's accumulated sales and time.

bool SellerHasName(const Seller & s, const char name[]);
// Returns true if the salesman's name is the same as name; false otherwise.

float SalesValue(Seller & s);
// Returns sales per hour for the salesman.
// Returns 0.0 if the salesman's time is 0.0
// It also zeroes the salesman's sales & time when done calculating

int FindSeller(ListOfSalesman & list, const char name[]);
//Find name in the list of salesman if it exists and returns index
//Otherwise, it will return -1 for not found


int main()
{
   ListOfSalesman mainList;
   int count = 0;
   char command = 'B';
   char par1[MAX_NAME + 1];
   float par2;
   float par3;
   
   while(command != 'Q')
   {
      cin >> command >> par1;
      if(command == 'U')
         cin >> par2 >> par3;
    
      //Add Command
     
      if(command == 'A')
      {
         if(count < 5 && FindSeller(mainList, par1) == -1)
         {
            InitSeller(mainList.salesman[count], par1);
            count++;
            cout  << par1 << " is salesman "<< count  << endl;
         }
         else if(count >= 5 && FindSeller(mainList, par1) == -1)
            cout << par1 << " is not added. List is full" << endl;

         else
            cout << par1 << " is already in the list" << endl;
      }
      
      //Output Command
      
      else if(command == 'O')
      {
         if(FindSeller(mainList, par1) != -1)
            cout << par1 << ": $" << SalesValue(mainList.salesman[FindSeller(mainList, par1)]) << " per hour" << endl;
         else
            cout << par1 << " is not in the list." << endl;
      }
      
      //Update Command
     
      else if(command == 'U')
      {
         if(FindSeller(mainList, par1) != NOT_FOUND)
         {
            UpdateSales(mainList.salesman[FindSeller(mainList, par1)], par2, par3);
            cout << par1 << " sold for $" << par2 << " of toys in " << par3 << " hours" << endl;
         }   
            
         else
            cout << par1 << " not found." << endl;
      }
   }//end while 
       return 0;   
}

//InitSeller

void InitSeller(Seller & s, const char name[])
{
   strcpy(s.name, name);
   s.sales = 0.0;
   s.time = 0.0;
}

//UpdateSales

void UpdateSales(Seller & s, float sales, float time)
{
   s.sales += sales;
   s.time += time;
}

//SellerHasName

bool SellerHasName(const Seller & s, const char name[])
{
   if(strcmp(s.name, name) != 0)
      return false;
   else
      return true;
}

//SalesValue

float SalesValue(Seller & s)
{
   float salesPerHour = 0.0;
   if(s.time != 0.0)
      salesPerHour = s.sales / s.time;
   else
      salesPerHour = 0.0;
   s.sales = 0;
   s.time = 0;   
      
   return salesPerHour;
}

//FindSeller
int FindSeller(ListOfSalesman & list, const char name[])
{
   int i;
   int result = NOT_FOUND; //initalized to not found and updated if found
   for(i = 0; i < MAX_SALESMAN; i++)
   {
      if(strcmp(list.salesman[i].name, name) == 0)
         result = i;
   }
   return result;
}
     
