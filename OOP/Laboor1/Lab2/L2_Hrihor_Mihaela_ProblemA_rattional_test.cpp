#include <iostream>
#include "L2_Hrihor_Mihaela_ProblemaA_rational.h"

int main() {
    //Testen der klasse Rational
    Rational r1(1, 3) ;
    Rational r2(6, 4);

    std::cout << "r1: " << r1.get_numerator() << "/" << r1.get_denominator()<<std::endl;
    std::cout << "r2: " << r2.get_numerator() << "/" << r2.get_denominator()<<std::endl;

    Rational sum = r1.add(r2);
    std::cout << "Summe ist: " << sum.get_numerator() << "/" << sum.get_denominator() << std::endl;

    Rational dif = r1.subtract(r2);
    std::cout << "Differenz ist: " << dif.get_numerator() << "/" << dif.get_denominator() << std::endl;

    Rational mul = r1.multiply(r2);
    std::cout << "Produkt ist: " << mul.get_numerator() << "/" << mul.get_denominator() << std::endl;

    Rational quotient = r1.divide(r2);
    std::cout << "Quotient ist: " << quotient.get_numerator() << "/" << quotient.get_denominator() << std::endl;

    Rational inverse_r1 = r1.inverse();
    std::cout << "Inverse von r1 ist: " << inverse_r1.get_numerator() << "/" << inverse_r1.get_denominator()
              << std::endl;

    Rational inverse_r2 = r2.inverse();
    std::cout << "Inverse von r2 ist: " << inverse_r2.get_numerator() << "/" << inverse_r2.get_denominator()
              << std::endl;

    Rational rezultat=r1.reduce();
    std::cout<<"fractia redusa este "<<rezultat.get_numerator()<<"/"<<rezultat.get_denominator()<<std::endl;

    int comparasion = r1.compare(r2);
    if (comparasion < 0)
        std::cout << "r1 ist kleiner als r2" << std::endl;
    else if (comparasion > 0)
        std::cout << "r1 ist grosser als r2" << std::endl;
    else
        std::cout << "r1 ist gleich r2" << std::endl;

    const int array_size  = 3;
    Rational fractions[array_size]{
        Rational(1,2),
        Rational(4,5),
        Rational(2,4)
    };
    //calculam totalul fractiilor din array
    //creem o instanta a clasei Rational si initializam variabila total cu val. 0
    //(numarator=0, numitor= 0)
    Rational total(0,1);
    for(int i=0;i<array_size;i++){
        total=total.add(fractions[i]);
    }
    //afisam Total
    std::cout<<"totalul seriilor este : "<<total.get_numerator()<<"/"<<total.get_denominator()<<std::endl;

    return 0;
}























































































