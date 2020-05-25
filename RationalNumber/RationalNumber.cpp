#include "RationalNumber.h"

//inte min funktion
// Greatest common denominator of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


RationalNumber::RationalNumber(int new_numerator, int new_denominator)
{
    // kontrollera i fall negativt.
    if (new_numerator < 0 || new_denominator < 0) {
        if (new_numerator < 0 && new_denominator < 0)
            negative = false;

        else
            negative = true;
    }

    if (new_denominator == 0)
         throw std::invalid_argument("[RationalNumber] Can not create object with 0 as denominator.");

    int reduceWith = gcd(abs(new_numerator), abs(new_denominator));
    this->numerator = (abs(new_numerator) / reduceWith);
    this->denominator = (abs(new_denominator) / reduceWith);
}

float RationalNumber::getValue()
{
    return (float)numerator / (float)denominator;
}

inline void RationalNumber::toggleNegative()
{  
    if (negative == false)
        negative = true;
    else
        negative = false;
}

bool RationalNumber::isNegative()
{
    return negative;
}

void RationalNumber::print()
{
    std::cout << "[" << numerator << "/" << denominator << "]" << std::endl;
}

RationalNumber operator+(RationalNumber first, const RationalNumber& last)
{

    first.numerator = first.numerator * last.denominator + last.numerator * first.denominator;
    first.denominator = first.denominator * last.denominator;


    int reduceWith = gcd(first.numerator, first.denominator);
    first.numerator =   first.numerator / reduceWith;
    first.denominator = first.denominator / reduceWith;

    return first;
}

RationalNumber operator-(RationalNumber first, const RationalNumber& last)
{

    first.numerator = first.numerator * last.denominator - last.numerator * first.denominator;
    first.denominator = first.denominator * last.denominator;


    int reduceWith = gcd(first.numerator, first.denominator);
    first.numerator = first.numerator / reduceWith;
    first.denominator = first.denominator / reduceWith;

    return first;
}

RationalNumber operator*(RationalNumber first, const RationalNumber& last)
{

    // if last is negative, multiply first by -1.
    std::cout << "Last: " << last.negative;
    if (last.negative == true)
        first.toggleNegative();

    first.numerator = first.numerator * last.numerator;
    first.denominator = first.denominator * last.denominator;


    int reduceWith = gcd(first.numerator, first.denominator);
    first.numerator = first.numerator / reduceWith;
    first.denominator = first.denominator / reduceWith;

    return first;
}

RationalNumber operator/(RationalNumber first, const RationalNumber& last)
{
    /*
     a/b / c/d <=> a*d / b*c
    */

    // if last is negative, multiply first by -1.
    if (last.negative == true)
       first.toggleNegative();

    first.numerator = first.numerator * last.denominator;
    first.denominator = first.denominator * last.numerator;

    int reduceWith = gcd(first.numerator, first.denominator);
    first.numerator = first.numerator / reduceWith;
    first.denominator = first.denominator / reduceWith;

    return first;
}

bool operator>(RationalNumber first, RationalNumber last)
{ 
    return first.getValue() > last.getValue();
}

bool operator<(RationalNumber first, RationalNumber last)
{
    return first.getValue() < last.getValue();
}

bool operator==(const RationalNumber first, const RationalNumber last)
{
    if ((first.numerator == last.numerator && first.denominator == last.denominator))
        return true;
    else
        return false;
}


bool operator>=(const RationalNumber first, const RationalNumber last)
{
    if (first > last || first == last)
        return true;
    else
        return false;
}

bool operator<=(const RationalNumber first, const RationalNumber last)
{
    if (first < last || first == last)
        return true;
    else
        return false;
}

bool operator!=(const RationalNumber first, const RationalNumber last)
{
    if (!(first == last))
        return true;
    else
        return false;
}

std::ostream& operator<<(std::ostream& stream, const RationalNumber to_stream)
{
    
    stream << (to_stream.negative == true ? "-" : "") << "[" << to_stream.numerator << "/" << to_stream.denominator << "]";
    return stream;
}


