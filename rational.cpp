#include <iostream>
#include <cstdlib>
#include "rational.h"
#include <cmath>
#include <cstdbool>
using namespace std;

unsigned gcd(int a, int b) {
    unsigned gcd_ = 1;
    a = abs(a);
    b = abs(b);
    for (int i = 2; i <= a; ++i) {
        if (!(a % i) && !(b % i)) {
            gcd_ = i;
        }
    }
    return gcd_;
}

unsigned lcm(int a, int b) {
    unsigned lcm_;
    a = abs(a);
    b = abs(b);
    for (int i = a; i <= a * b; ++i) {
        if (!(i % a) && !(i % b)) {
            lcm_ = i;
            break;
        }
    }
    return lcm_;
}

Rational Rational::operator + (const Rational& r) {
    return sum(r);
}

Rational Rational::operator - (const Rational& r) {
    return sub(r);
}

Rational Rational::operator * (const Rational& r) {
    return mul(r);
}

Rational Rational::operator / (const Rational& r) {
    return div(r);
}

bool Rational::operator == (const Rational& r) {
    return eq(r);
}

bool Rational::operator != (const Rational& r) {
    return neq(r);
}

bool Rational::operator < (const Rational& r) {
    return l(r);
}

bool Rational::operator <= (const Rational& r) {
    return leq(r);
}

bool Rational::operator > (const Rational& r) {
    return g(r);
}

bool Rational::operator >= (const Rational& r) {
    return geq(r);
}

Rational Rational::reduce() const {
    int d = gcd(numerator, denumerator);
    return Rational(numerator / d, denumerator / d);
}

Rational Rational::neg() const {
    return Rational((-1) * numerator, denumerator);
}

Rational Rational::inv() const {
    if (nan) {
        return Rational(1, 0);
    }
    if (numerator < 0) {
        return Rational(-denumerator, -numerator);
    }
    return Rational(denumerator, numerator);
}

Rational Rational::sum(Rational r) const {
    if (nan || r.nan) {
        return Rational(1, 0);
    }
    int d = lcm(denumerator, r.denumerator);
    return Rational(numerator * d / denumerator +
                    r.numerator * d / r.denumerator, d);
}

Rational Rational::sub(Rational r) const {
    return sum(r.neg());
}

Rational Rational::mul(Rational r) const {
    if (nan || r.nan) {
        return Rational(1, 0);
    }
    return Rational(numerator * r.numerator,
                    denumerator * r.denumerator);
}

Rational Rational::div(Rational r) const {
    return mul(r.inv());
}

bool Rational::eq(Rational r) const {
    int d = lcm(denumerator, r.denumerator);
    return numerator * d / denumerator == r.numerator * d / r.denumerator;
}

bool Rational::neq(Rational r) const {
    return !eq(r);
}

bool Rational::l(Rational r) const {
    int d = lcm(denumerator, r.denumerator);
    return (numerator * d / denumerator <
             r.numerator * d / r.denumerator) ? true : false;
}

bool Rational::leq(Rational r) const {
    return l(r) || eq(r);

}

bool Rational::g(Rational r) const {
    return !leq(r);
}

bool Rational::geq(Rational r) const {
    return !l(r);
}

void Rational::print() const {
    if(nan) {
        cout << "<NAN>\n";
    }
    else {
        Rational r = reduce();
        cout << r.numerator << "/" << r.denumerator << endl;
    }
}

void Rational::scan() {
    cin >> numerator >> denumerator;
    nan = (denumerator == 0);
}
