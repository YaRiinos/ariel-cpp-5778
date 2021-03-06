/**
 * A minimal Fraction class for demonstrating
 * type-conversion operators and the ambiguity they cause.
 * 
 * @author Erel Segal-Halevi
 * @since 2018
 */

#include<iostream>
#include<math.h>
using namespace std;


class Fraction {
public:
	int 	nom;
	int 	den;
	Fraction operator+ (const Fraction& other) {
		int nn = nom * other.den +
			den * other.nom;
		int dd = den * other.den;
		return Fraction(nn, dd);
	}
	Fraction(int nn, int dn): nom(nn), den(dn) { }

	// Add "explicit" in one of the lines below to allow compilation of last line.
	// See	https://stackoverflow.com/a/49092822/827927
	Fraction(int nn): Fraction(nn, 1) { }
	operator double() const { return double(nom) / den; }
	//operator char() const { return 'a'; }
};

ostream& operator<<(ostream& os, const Fraction& frac) {
	return os << frac.nom << '/' << frac.den;
}


int main() {
	Fraction f1 {1, 4};
	cout << "f1 = " << f1 << endl;
	double d1 {f1};
	// equivalent to: double d1 = f1;
	cout << "d1 = " << d1 << endl;
	Fraction f2 {2};
	cout << "f2 = " << f2 << endl;
	cout << ((Fraction)2) << endl;
	//cout << "f1+2 = " << (f1 + 2) << endl;   // ambiguous!
	cout << "f1+2 = " << (f1 + Fraction{2}) << endl;   // OK!
	cout << "f1+2 = " << (double{f1} + 2) << endl;    // OK!

	char c = f1;
	cout << c << endl;
	return 0;
}
