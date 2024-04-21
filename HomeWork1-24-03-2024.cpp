#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
	Fraction a = Fraction(2, 10);

	std::cin >> a;

	std::cout << a;
}