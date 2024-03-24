#include "Fraction.h"

inline Fraction::Fraction(int numer, int denom)
{
	setNumerator(numer);
	setDenominator(denom);
	autoResize();
}

inline Fraction::Fraction(float number)
{
	if (number < 0)
		throw std::invalid_argument("received negative value");

	int denom = 10;
	while (int(number * denom) % 10 != 0)
		denom *= 10;
	denom /= 10;

	numerator = int(number * denom);
	denominator = denom;
	autoResize();
}

void Fraction::autoResize()
{
	int first = numerator;
	int second = denominator;

	while (first % second != 0)
	{
		int tmp = first % second;
		first = second;
		second = tmp;
	}

	numerator = numerator / second;
	denominator = denominator / second;
}



Fraction Fraction::operator+(Fraction other)
{
	Fraction res = Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
	res.autoResize();
	return res;
}

Fraction Fraction::operator-(Fraction other)
{
	Fraction res = Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
	res.autoResize();
	return res;
}

Fraction Fraction::operator*(Fraction other)
{
	Fraction res = Fraction(numerator * other.numerator, denominator * other.denominator);
	res.autoResize();
	return res;
}

Fraction Fraction::operator/(Fraction other)
{
	Fraction res = Fraction(numerator * other.denominator, denominator * other.numerator);
	res.autoResize();
	return res;
}



Fraction Fraction::operator+(int number)
{
	Fraction res = Fraction(numerator + number * denominator, denominator);
	res.autoResize();
	return res;
}

Fraction Fraction::operator-(int number)
{
	Fraction res = Fraction(numerator - number * denominator, denominator);
	res.autoResize();
	return res;
}

Fraction Fraction::operator*(int number)
{
	Fraction res = Fraction(numerator * number, denominator);
	res.autoResize();
	return res;
}

Fraction Fraction::operator/(int number)
{
	Fraction res = Fraction(numerator, denominator * number);
	res.autoResize();
	return res;
}



Fraction Fraction::operator+(float number)
{
	return *this + Fraction(number);
}

Fraction Fraction::operator-(float number)
{
	return *this - Fraction(number);
}

Fraction Fraction::operator*(float number)
{
	return *this * Fraction(number);
}

Fraction Fraction::operator/(float number)
{
	return *this / Fraction(number);
}
