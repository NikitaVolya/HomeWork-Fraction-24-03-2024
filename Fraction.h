#pragma once

#include <iostream>

class Fraction
{
private:
	int numerator, denominator;
public:
	
	Fraction(int numer, int denom);
	Fraction(float number);

	int getNumerator() { return numerator; };
	int getDenominator() { return denominator; };
	float getFloat() { return (float)numerator / denominator; }

	void setNumerator(int number) { numerator = number; };
	void setDenominator(int number) { denominator = number; };

	void autoResize();

	Fraction operator+(Fraction other);
	Fraction operator-(Fraction other);
	Fraction operator*(Fraction other);
	Fraction operator/(Fraction other);

	Fraction operator+(int number);
	Fraction operator-(int number);
	Fraction operator*(int number);
	Fraction operator/(int number);

	Fraction operator+(float number);
	Fraction operator-(float number);
	Fraction operator*(float number);
	Fraction operator/(float number);
};