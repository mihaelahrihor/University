#ifndef L2_Hrihor_Mihaela_ProblemA_rational_H
#define L2_Hrihor_Mihaela_ProblemA_rational_H

class Rational {
private:
    int numerator;
    int denominator;



public:
    Rational(int num, int denom); // Konstruktor
    int get_numerator() const; // Zugriffsmethode für den Zähler
    int get_denominator() const; // Zugriffsmethode für den Nenner
    static int gcd(int a, int b); // Hilfsfunktion zur Berechnung des größten gemeinsamen Teilers
    Rational add(const Rational& other) const; // Addition
    Rational subtract(const Rational& other) const; // Subtraktion
    Rational multiply(const Rational& other) const; // Multiplikation
    Rational divide(const Rational& other) const; // Division
    Rational reduce() const; // Reduziert die Bruchform
    Rational inverse() const; // Berechnet die Umkehrung der rationalen Zahl
    int compare(const Rational& other) const; // Vergleicht zwei rationale Zahlen
};

#endif
