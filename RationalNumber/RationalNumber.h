#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>
class RationalNumber {
public:
	RationalNumber(int numerator, int denominator);
	// print the number in form [a/b]
	void print();
	float getValue();
	void toggleNegative();
	bool isNegative();
	
private:
	int numerator;
	int denominator;
	bool negative;



public:
	// operator overloading
	friend RationalNumber operator+(RationalNumber first, const RationalNumber& last);
	friend RationalNumber operator-(RationalNumber first, const RationalNumber& last);
	friend RationalNumber operator*(RationalNumber first, const RationalNumber& last);
	friend RationalNumber operator/(RationalNumber first, const RationalNumber& last);

	//relational operators
	friend bool operator>(RationalNumber first, RationalNumber last);
	friend bool operator<(RationalNumber first, RationalNumber last);
	friend bool operator==(const RationalNumber first, const RationalNumber last);
	friend bool operator>=(const RationalNumber first, const RationalNumber last);
	friend bool operator<=(const RationalNumber first, const RationalNumber last);
	friend bool operator!=(const RationalNumber first, const RationalNumber last);
	
	friend std::ostream& operator<<(std::ostream &stream, const RationalNumber to_stream);
};



#endif