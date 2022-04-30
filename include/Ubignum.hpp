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
    std::string addPositives(UBignum, UBignum) const;
    std::string difPositives(UBignum, UBignum) const;

public:
    UBignum(std::string = "0");
    UBignum(long long int);
    std::string getDigits() const;
    void setDigits(std::string);

    int length() const;
    char operator[](int index) const;

    bool operator<(UBignum) const;
    bool operator>(UBignum) const;
    bool operator==(UBignum) const;
    bool operator!=(UBignum) const;
    bool operator<=(UBignum) const;
    bool operator>=(UBignum) const;

    UBignum operator+(UBignum) const;
    UBignum operator-(UBignum) const;
    UBignum operator*(UBignum) const;
    UBignum operator/(UBignum) const;
    UBignum operator/(long long int) const;
    UBignum operator%(UBignum) const;
    UBignum operator%(long long int) const;

    void printWithDelimiter();
};

#endif