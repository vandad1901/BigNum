#ifndef UBIGNUM_H
#define UBIGNUM_H
#include <string>

// Signed Big Number

class UBignum
{
    friend std::ostream &operator<<(std::ostream &, const UBignum &);
    friend std::istream &operator>>(std::istream &, UBignum &);

private:
    std::string digits;

public:
    UBignum(std::string = "0");
    UBignum(long long int);

    std::string getDigits() const;
    void setDigits(std::string);
    friend void swap(UBignum &, UBignum &);
    UBignum &operator=(UBignum);
    UBignum &operator=(int);
    UBignum &operator=(const char *);
    UBignum &operator+=(const UBignum &);
    UBignum &operator-=(const UBignum &);
    UBignum &operator*=(const UBignum &);
    UBignum &operator/=(const UBignum &);
    UBignum &operator%=(const UBignum &);

    int length() const;
    char operator[](int index) const;

    friend bool operator<(UBignum lhs, const UBignum rhs);
    friend bool operator>(UBignum lhs, const UBignum rhs);
    friend bool operator==(UBignum lhs, const UBignum rhs);
    friend bool operator!=(UBignum lhs, const UBignum rhs);
    friend bool operator<=(UBignum lhs, const UBignum rhs);
    friend bool operator>=(UBignum lhs, const UBignum rhs);

    friend UBignum operator+(UBignum lhs, const UBignum rhs);
    friend UBignum operator-(UBignum lhs, const UBignum rhs);
    friend UBignum operator*(UBignum lhs, const UBignum rhs);
    friend UBignum operator/(UBignum lhs, const UBignum rhs);
    friend UBignum operator%(UBignum lhs, const UBignum rhs);

    void printDelimiter();
};

#endif