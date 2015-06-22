/*
Hyungi Kim
025 741 125
OOP244
ASSIGNMENT4 
SpecialOrder.h
*/
#include<iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "Order.h"
     class SpecialOrder : public Order{
  char* inst;
  public:
   SpecialOrder();
   SpecialOrder(const ISBN& isbn, const char* instr);
   SpecialOrder(const SpecialOrder& source);
   bool add(istream& is);
   void display(ostream& os) const;
   SpecialOrder& operator=(const SpecialOrder& source);
   ~SpecialOrder();
};

	 ostream& operator<<(ostream& os, SpecialOrder obj);
