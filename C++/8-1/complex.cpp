// complex1.cpp
// Definicii na funkciite chlenki na klasata Complex
#include <iostream>

using std::cout;
using std::ostream;
using std::istream;

#include "complex.h"

// Konstruktor
Complex::Complex( double r, double i ) 
   : real( r ), imaginary( i ) { }

// Preklopi operator za sobiranje
Complex Complex::operator+( const Complex &operand2 ) const
{
   return Complex( real + operand2.real, 
                   imaginary + operand2.imaginary );
} // kraj na funkcijata operator+ 

// Preklopi operator za odzemanje
Complex Complex::operator-( const Complex &operand2 ) const
{
   return Complex( real - operand2.real, 
                   imaginary - operand2.imaginary );
} // kraj na funkcijata operator- 

// Preklopi operator = 
const Complex& Complex::operator=( const Complex &right )
{
   real = right.real;
   imaginary = right.imaginary;
   return *this;   // ovozmozhuva kaskadiranje
} // ekraj na funkcijata operator= 

ostream& operator<<(ostream &o, const Complex &c)
{
   cout << '(' << c.real << ", " << c.imaginary << ')';
   return o;
}

istream &operator>>( istream &input, Complex &c )
{
   input >> c.real >> c.imaginary;

   return input;
}

Complex operator*(Complex c1, Complex c2){
    return Complex( c1.real * c2.real, 
                   c1.imaginary * c2.imaginary );
}

Complex operator*(Complex c, int broj){
    return Complex( c.real * broj, 
                   c.imaginary * broj );
}

Complex operator*(int broj, Complex c){
    return Complex( broj * c.real, 
                   broj * c.imaginary );
}

bool Complex::operator==(const Complex &c1){
    if(real==c1.real && imaginary==c1.imaginary)
        return true;
    else 
        return false;
}

bool Complex::operator!=(const Complex &c1){
    if(real!=c1.real || imaginary!=c1.imaginary)
        return true;
    else 
        return false;
}

Complex Complex::operator+=( const Complex &operand2 ){
   return Complex( real += operand2.real, 
                   imaginary += operand2.imaginary );
}

Complex Complex::operator-=( const Complex &operand2 ){
   return Complex( real -= operand2.real, 
                   imaginary -= operand2.imaginary );
}