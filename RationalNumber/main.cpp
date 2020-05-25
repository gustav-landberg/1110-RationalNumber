
#include "RationalNumber.h"



int main() {

	RationalNumber a(1, 3);
	RationalNumber b(1, -3);
	RationalNumber c = a * b; // 1 / 9

	std::cout << "a:" << a << std::endl;
	std::cout << "b:" << b << std::endl;
	std::cout << "c:" << c << std::endl;
	std::cout << "a / c:" <<(c / a) << std::endl;
	std::cout << "a == b?" << ((a == b) ? " Yes" : " No") << std::endl;
	std::cout << "a != b?" << ((a != b) ? " Yes" : " No") << std::endl;
	std::cout << "a > b?" << ((a > b) ? " Yes" : " No") << std::endl;
	std::cout << "a > c?" << ((a > c) ? " Yes" : " No") << std::endl;
	std::cout << "a >= b?" << ((a >= b) ? " Yes" : " No") << std::endl;
	std::cout << "a <= c?" << ((a <= c) ? " Yes" : " No") << std::endl;
}