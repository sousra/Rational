#ifndef RATIONAL_H_INCLUDED
#define RATIONAL_H_INCLUDED

using namespace std;

class Rational {
public:

    explicit Rational(int x = 1, int y = 1) :  numerator(x), denumerator(y) {
        if (!denumerator) {
            cout << endl << "<NAN>" << endl;
            exit(EXIT_FAILURE);
        }
    }

    Rational operator + (const Rational&);
    Rational operator - (const Rational&);
    Rational operator * (const Rational&);
    Rational operator / (const Rational&);
    bool operator == (const Rational&);
    bool operator != (const Rational&);
    bool operator < (const Rational&);
    bool operator <= (const Rational&);
    bool operator > (const Rational&);
    bool operator >= (const Rational&);

    // ����������
    Rational reduce() const;

    // *-1
    Rational neg() const;
    // ^-1
    Rational inv() const;

    Rational sum(Rational) const;
    Rational sub(Rational) const;
    Rational mul(Rational) const;
    Rational div(Rational) const;

    // ==
    bool eq(Rational) const;
    // !=
    bool neq(Rational) const;
    // less than
    // <
    bool l(Rational) const;
    // less or equal than
    // <=
    bool leq(Rational) const;
    // greater than
    // >
    bool g(Rational) const;
    // greater or equal than
    // >=
    bool geq(Rational) const;

    // ������� �� �����
    void print() const;
    // ������� � ����������
    void scan();
private:

    bool nan;
    int numerator;
    int denumerator;

};

#endif // RATIONAL_H_INCLUDED
