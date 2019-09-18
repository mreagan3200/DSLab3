#include "Complex.h"
#include <iostream>
#include <string>

using namespace std;

void getScalarInput(double &s) {
	cout << "Enter value for scalar: ";
	cin >> s;
}

void getComplexInput(double &re, double &im) {
	cout << "Enter value for the real component: ";
	cin >> re;
	cout << "Enter value for the imaginary component: ";
	cin >> im;
}
void getOperation(char& op) {
	while (1) {
		cout << "Enter which operation you would like to perform.\nAccepted operations (+,-,*,/,=)\n";
		cin >> op;
		switch (op) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '=':
			return;
		default:
			cout << "Invalid operation: " << op << endl;
			break;
		}
	}
}

int main() {
	string input;
	double re1, im1, re2, im2, s;
	bool eq;
	char op;
	getComplexInput(re1, im1);
	Complex c1(re1, im1), c2;
	do {
		getOperation(op);
		switch (op) {
		case '+':
		case '-':
		case '=':
			getComplexInput(re2, im2);
			c2.setReal(re2);
			c2.setImag(im2);
			break;
		case '*':
		case '/':
			getScalarInput(s);
			break;
		}
		switch (op) {
		case '+':
			c1 + c2;
			break;
		case '-':
			c1 - c2;
			break;
		case '*':
			c1 * s;
			break;
		case '/':
			c1 / s;
			break;
		case '=':
			eq = (c1 == c2);
			break;
		}
		cout << "Result of operation: " << endl;
		if (op == '=') {
			if (eq) {
				cout << "The two complex inputs are equal" << endl;
			}
			else cout << "The two complex inputs are not equal" << endl;
		}
		else {
			c1.print();
			cout << "\n";
		}
		cout << "Do another operation (y/n)? ";
		cin >> input;
	} while (input == "y" || input == "Y");
	return 0;
}