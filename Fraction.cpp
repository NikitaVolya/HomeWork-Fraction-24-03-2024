#include "Fraction.h"

inline Fraction::Fraction(int numer, int denom)
{
	setNumerator(numer);
	setDenominator(denom);
	autoResize();
}

Fraction::Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator)
{
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
	int first = std::fabs(numerator);
	int second = std::fabs(denominator);

	while (first % second != 0)
	{
		int tmp = first % second;
		first = second;
		second = tmp;
	}

	numerator = numerator / second;
	denominator = denominator / second;
}



Fraction Fraction::operator-() const
{
	return Fraction(-numerator, denominator);
}

Fraction Fraction::operator+(const Fraction& other) const
{
	Fraction res = Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
	res.autoResize();
	return res;
}

Fraction Fraction::operator-(const Fraction& other) const
{
	Fraction res = Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
	res.autoResize();
	return res;
}

Fraction Fraction::operator*(const Fraction& other) const
{
	Fraction res = Fraction(numerator * other.numerator, denominator * other.denominator);
	res.autoResize();
	return res;
}

Fraction Fraction::operator/(const Fraction& other) const
{
	Fraction res = Fraction(numerator * other.denominator, denominator * other.numerator);
	res.autoResize();
	return res;
}

const Fraction& Fraction::getBigger(const Fraction& other) const
{
	if (denominator == other.denominator)
		return numerator > other.numerator ? *this : other;
	else
		return numerator * other.denominator > other.numerator * denominator ? *this : other;
}

void Fraction::print() const
{
	std::cout << numerator << " / " << denominator << std::endl;
}
