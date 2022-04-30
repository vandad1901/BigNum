#ifndef SBIGNUM_H
#define SBIGNUM_H
#include <string>
#include "Ubignum.hpp"

//Unsigned Big Number

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

    int length() const;
    char operator[](int index) const;

    bool operator<(SBignum) const;
    bool operator>(SBignum) const;
    bool operator==(SBignum) const;
    bool operator!=(SBignum) const;
    bool operator<=(SBignum) const;
    bool operator>=(SBignum) const;

    SBignum operator+(SBignum) const;
    SBignum operator-() const;
    SBignum operator-(SBignum) const;
    SBignum operator*(SBignum) const;
    SBignum operator/(SBignum) const;
    SBignum operator/(long long int) const;
    SBignum operator%(SBignum) const;
    SBignum operator%(long long int) const;

    void printWithDelimiter();
};

#endif