#include "Complex.h"
#include <cmath>
#include <iostream>
#include <iomanip>
# define PI 3.14159265358979323846 // pi constant


Complex::Complex() {
	real = 0;
	imaginary = 0;
}

Complex::Complex(double re, double im) {
	real = re;
	imaginary = im;
}


Complex::Complex(double r, double deg, bool b) {
	double rad = deg * PI / 180;
	real = r * cos(rad);
	imaginary = r * sin(rad);
}

Complex::~Complex() {}

double Complex::getReal() {
	return real;
}
double Complex::getImag() {
	return imaginary;
}
double Complex::getRadius() {
	return sqrt(real*real + imaginary*imaginary);
}
double Complex::getAngle() {
	return atan2(imaginary, real) * 180/PI;
}
void Complex::setReal(double re) {
	real = re;
}
void Complex::setImag(double im) {
	imaginary = im;
}

void Complex::print() {
	std::cout << std::fixed << std::setprecision(4);
	std::cout << "Cartesian coordinates:" << std::endl;
	if (imaginary >= 0) {
		std::cout << real << " + " << imaginary << "i" << std::endl;
	}
	else {
		std::cout << real << " - " << abs(imaginary) << "i" << std::endl;
	}
	std::cout << "Polar coordinates:" << std::endl;
	std::cout << "r = " << getRadius() << ", phi = " << getAngle() << std::endl;
}

void Complex::operator+(Complex& other) {
	real += other.getReal();
	imaginary += other.getImag();
}
void Complex::operator-(Complex& other) {
	real -= other.getReal();
	imaginary -= other.getImag();
}
void Complex::operator*(double d) {
	real *= d;
	imaginary *= d;
}
void Complex::operator/(double d) {
	real /= d;
	imaginary /= d;
}
bool Complex::operator==(Complex& other) {
	return abs(real - other.getReal()) < 1e-10 && abs(imaginary - other.getImag()) < 1e-10;
}
