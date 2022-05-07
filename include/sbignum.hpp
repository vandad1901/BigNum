#ifndef SBIGNUM_H
#define SBIGNUM_H
#include <string>
#include "Ubignum.hpp"

// Unsigned Big Number

class SBignum
{
    friend std::ostream &operator<<(std::ostream &, const SBignum &);
    friend std::istream &operator>>(std::istream &, SBignum &);

private:
    UBignum abs;
    bool isNegative;

public:
    SBignum(std::string = "0");
    SBignum(UBignum, bool = false);
    SBignum(long long int);

    UBignum getAbs() const;
    void setAbs(UBignum);
    bool getIsNegative() const;
    void setIsNegative(bool);
    friend void swap(SBignum &, SBignum &);
    SBignum &operator=(SBignum);
    SBignum operator+() const;
    SBignum operator-() const;
    SBignum &operator+=(const SBignum &);
    SBignum &operator-=(const SBignum &);
    SBignum &operator*=(const SBignum &);
    SBignum &operator/=(const SBignum &);
    SBignum &operator/=(const long long int &);
    SBignum &operator%=(const SBignum &);
    SBignum &operator%=(const long long int &);

    int length() const;
    char operator[](int index) const;

    friend bool operator<(SBignum lhs, const SBignum rhs);
    friend bool operator>(SBignum lhs, const SBignum rhs);
    friend bool operator==(SBignum lhs, const SBignum rhs);
    friend bool operator!=(SBignum lhs, const SBignum rhs);
    friend bool operator<=(SBignum lhs, const SBignum rhs);
    friend bool operator>=(SBignum lhs, const SBignum rhs);

    friend SBignum operator+(SBignum lhs, const SBignum rhs);
    friend SBignum operator-(SBignum lhs, const SBignum rhs);
    friend SBignum operator*(SBignum lhs, const SBignum rhs);
    friend SBignum operator/(SBignum lhs, const SBignum rhs);
    friend SBignum operator/(SBignum lhs, const long long int rhs);
    friend SBignum operator%(SBignum lhs, const SBignum rhs);
    friend SBignum operator%(SBignum lhs, const long long int rhs);

    void printDelimiter();
};

#endif