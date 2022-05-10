#ifndef SBIGNUM_H
#define SBIGNUM_H
#include <string>
#include "Ubignum.hpp"

// Unsigned Big Number

class Bignum
{
    friend std::ostream &operator<<(std::ostream &, const Bignum &);
    friend std::istream &operator>>(std::istream &, Bignum &);

private:
    UBignum abs;
    bool isNegative;

public:
    Bignum(std::string = "0");
    Bignum(UBignum, bool = false);
    Bignum(long long int);

    UBignum getAbs() const;
    void setAbs(UBignum);
    bool getIsNegative() const;
    void setIsNegative(bool);
    friend void swap(Bignum &, Bignum &);
    Bignum &operator=(Bignum);
    Bignum operator+() const;
    Bignum operator-() const;
    Bignum &operator+=(const Bignum &);
    Bignum &operator-=(const Bignum &);
    Bignum &operator*=(const Bignum &);
    Bignum &operator/=(const Bignum &);
    Bignum &operator/=(const long long int &);
    Bignum &operator%=(const Bignum &);
    Bignum &operator%=(const long long int &);

    int length() const;
    char operator[](int index) const;

    friend bool operator<(Bignum lhs, const Bignum rhs);
    friend bool operator>(Bignum lhs, const Bignum rhs);
    friend bool operator==(Bignum lhs, const Bignum rhs);
    friend bool operator!=(Bignum lhs, const Bignum rhs);
    friend bool operator<=(Bignum lhs, const Bignum rhs);
    friend bool operator>=(Bignum lhs, const Bignum rhs);

    friend Bignum operator+(Bignum lhs, const Bignum rhs);
    friend Bignum operator-(Bignum lhs, const Bignum rhs);
    friend Bignum operator*(Bignum lhs, const Bignum rhs);
    friend Bignum operator/(Bignum lhs, const Bignum rhs);
    friend Bignum operator/(Bignum lhs, const long long int rhs);
    friend Bignum operator%(Bignum lhs, const Bignum rhs);
    friend Bignum operator%(Bignum lhs, const long long int rhs);

    void printDelimiter();
};

#endif