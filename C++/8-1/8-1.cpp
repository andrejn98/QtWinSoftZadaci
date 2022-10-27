// p08_06.cpp
// Drajver za klasata Complex
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

#include "complex.h"

int main()
{
   Complex x, y( 4.3, 8.2 ), z( 3.3, 1.1 );

   cout<<"Vnesete za x: (R i I): ";
   cin >> x;

   cout << "\n\nx == y:\n";
   if(x == y){
       cout << "x i y se ednakvi\n"<<endl;
   }else if(x!=y){
       cout << "x i y se razlicni\n"<<endl; 
   }

   cout << "x: ";
   cout << x;
   cout << "\ny: ";
   cout << y;
   cout << "\nz: ";
   cout << z;

   x = y + z;
   cout << "\n\nx = y + z:\n";
   cout << x;
   cout << " = ";
   cout << y;
   cout << " + ";
   cout << z;

   x = y - z;
   cout << "\n\nx = y - z:\n";
   cout << x;
   cout << " = ";
   cout << y;
   cout << " - ";
   cout << z;
 
   x = y * z;
   cout << "\n\nx = y * z:\n";
   cout << x;
   cout << " = ";
   cout << y;
   cout << " - ";
   cout << z;

   x = y * 2;
   cout << "\n\nx = y * 2:\n";
   cout << x;
   cout << " = ";
   cout << y;
   cout << " * ";
   cout << "2";

   x = 2 * y;
   cout << "\n\nx = 2 * y:\n";
   cout << x;
   cout << " = ";
   cout << "2";
   cout << " * ";
   cout << y;

   z=x;
   cout << "\n\nx += x:\n";
   x += x;
   cout << x;
   cout << " += ";
   cout << z;
   cout << " * ";
   cout << z;

   return 0;
} // kraj main

