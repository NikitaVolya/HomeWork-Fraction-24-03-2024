#pragma once

#include <iostream>

class Fraction
{
private:
	int numerator, denominator;
	void autoResize();
public:
	
	Fraction(const Fraction& other);
	Fraction(float number);
	Fraction(int numer, int denom);

	int getNumerator() const { return numerator; };
	int getDenominator() const { return denominator; };
	float getFloat() const { return (float)numerator / denominator; }

	void setNumerator(int number) { numerator = number; };
	void setDenominator(int number) { denominator = number; };

	Fraction operator-() const;

	Fraction operator+(const Fraction& other) const;
	Fraction operator-(const Fraction& other) const;
	Fraction operator*(const Fraction& other) const;
	Fraction operator/(const Fraction& other) const;

	const Fraction& getBigger(const Fraction& other) const;

	friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
	friend void operator>>(std::istream& in, Fraction& fraction);

	void print() const;
};