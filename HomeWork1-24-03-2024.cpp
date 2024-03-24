#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
	Fraction a = Fraction(1, 10);
	Fraction c = a + 0.4f;

	cout << c.getNumerator() << " | " << c.getDenominator() << endl;
}