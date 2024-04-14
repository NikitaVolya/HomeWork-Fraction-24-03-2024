#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
	Fraction a = Fraction(2, 10);
	Fraction b = Fraction(5, 3);
	Fraction c = b - a;

	c.print();
	(-a).print();
	(c + a).print();
	(a + 0.5f).print();
}