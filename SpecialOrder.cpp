/*
Hyungi Kim
025 741 125
OOP244
ASSIGNMENT4 
SpecialOrder.cpp
*/

#include<iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "SpecialOrder.h"


  SpecialOrder::SpecialOrder(){
	  inst = NULL;
	}
  /*declair variables in this objective to empty state*/
   SpecialOrder::SpecialOrder(const ISBN& isbn, const char* str):Order(isbn){
	  if(str != NULL){
       inst= new char[strlen(str) + 1];
       strcpy(inst, str);
    }
    else
       inst= NULL;
   }
   /*a constructor creates  object from a reference to an ISBN and the address of 
   string containing the special instructions*/
   SpecialOrder::SpecialOrder(const SpecialOrder& str):Order(str){
	   *this = str;
   }
   /*Copy constructor*/
   bool SpecialOrder::add(istream& is){
	    char specialInstr[100 + 1];
    specialInstr[0]= '\0';
    bool status= false;
 
   if(Order::add(is) == true){
       cout << "Instructions : ";
       is.getline(specialInstr, 100, '\n');
       status= true;
    }
    if(status){
       if(inst != NULL)
          delete [] inst;
 
      inst= new char[strlen(specialInstr) + 1];
       strcpy(inst, specialInstr);
    }
 
   return status;
   }
   /* modifier that receives istream and adds orders and instructions to the current object*/
   void SpecialOrder::display(ostream& os) const{
	   if(inst != NULL){
			os<<" "<<inst;
	   }
	   else{
		   cout<<"ERROR";
	   }
   }
   /* a query receive reference from ostream object and display class*/
   SpecialOrder& SpecialOrder::operator=(const SpecialOrder& str){
	   Order *temp=this;
	   const Order *temp2=&str;
	   *temp=*temp2;
	   inst = new char [ strlen(str.inst) +1];
	   strcpy(inst,str.inst);
	   return *this;
   }
   /*an operator copies data in between classes*/
   SpecialOrder::~SpecialOrder(){
	   if( inst != NULL){
		   delete [] inst;
	   }
   }
   /* if inst is not empty state and delete memory allocation assignmed to star variable */
