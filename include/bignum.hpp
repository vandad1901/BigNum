#ifndef BIGNUM_H
#define BIGNUM_H
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
    Bignum &operator=(int);
    Bignum &operator=(const char *);
    Bignum operator+() const;
    Bignum operator-() const;
    Bignum &operator+=(const Bignum &);
    Bignum &operator-=(const Bignum &);
    Bignum &operator*=(const Bignum &);
    Bignum &operator/=(const Bignum &);
    Bignum &operator%=(const Bignum &);
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
    friend Bignum operator%(Bignum lhs, const Bignum rhs);

    void printDelimiter();
};

#endif