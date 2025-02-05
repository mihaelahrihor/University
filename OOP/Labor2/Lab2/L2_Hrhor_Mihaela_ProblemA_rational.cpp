#include "L2_Hrihor_Mihaela_ProblemaA_rational.h"
#include <cmath>

Rational:: Rational(int num, int denom):numerator(num),denominator(denom){}

//initializare cu metoda de acces
int Rational::get_numerator() const {
    return numerator;
}

//initializare cu metoda de acces
int Rational::get_denominator() const {
    return denominator;
}

//initializare a cmmdc cu metoda de acces
int Rational::gcd(int a, int b) {
    while (b != 0){
        int aux = b;
        b = a % b;
        a = aux;
    }
    return abs(a);
}

Rational Rational::add(const Rational &other) const {
    int new_num= numerator*other.denominator + other.numerator*denominator;
    int new_denom= denominator*other.denominator;
    return Rational(new_num,new_denom);
}

Rational Rational::subtract(const Rational &other) const {
    int new_num= numerator*other.denominator - other.numerator*denominator;
    int new_denom=denominator*other.denominator;
    return Rational(new_num,new_denom);
}

Rational Rational::multiply(const Rational &other) const {
    int new_num = numerator*other.numerator;
    int new_denom = denominator*other.denominator;
    return Rational(new_num,new_denom);
}

Rational Rational::divide(const Rational &other) const {
    int new_num = numerator*other.denominator;
    int new_denom= denominator*other.numerator;
    return Rational(new_num,new_denom);

}
Rational Rational::reduce() const {
    int new_numarator = numerator / gcd(numerator, denominator);
    int new_numitor = numerator / gcd(numerator, denominator);
    return Rational(new_numarator,new_numitor);
}

Rational Rational::inverse() const {
    return Rational(denominator,numerator);
}

int Rational::compare(const Rational &other) const {
    int this_num=numerator*other.denominator;
    int that_num=other.numerator*denominator;
    if (this_num<that_num)
        return -1;
    else if(this_num>that_num)
        return 1;
    else
        return 0;

}



