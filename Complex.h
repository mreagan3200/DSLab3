#pragma once
class Complex
{
private:
	double real;
	double imaginary;
public:
	Complex();
	Complex(double, double); // complex plane form
	Complex(double, double, bool); // polar form
	~Complex();
	double getReal();
	double getImag();
	double getRadius();
	double getAngle();
	void setReal(double);
	void setImag(double);
	void print();

	void operator +(Complex&);
	void operator -(Complex&);
	void operator *(double);
	void operator /(double);
	bool operator ==(Complex&);
};