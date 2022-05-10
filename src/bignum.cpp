#include <iostream>
#include "bignum.hpp"
#include "ubignum.hpp"

Bignum::Bignum(std::string str)
{
    if (str[0] == '-' || str[0] == '+')
    {
        setIsNegative(str[0] == '-');
        str = str.substr(1, str.length() - 1);
    }
    else
    {
        setIsNegative(false);
    }
    setAbs(str);
}
Bignum::Bignum(long long int num)
{
    setAbs(num);
    setIsNegative(num < 0);
}
Bignum::Bignum(UBignum num, bool val)
{
    setAbs(num);
    setIsNegative(val);
}

UBignum Bignum::getAbs() const
{
    return abs;
}
void Bignum::setAbs(UBignum str)
{
    abs = str;
}
bool Bignum::getIsNegative() const
{
    return isNegative;
}
void Bignum::setIsNegative(bool val)
{
    isNegative = val;
}
void swap(Bignum &v1, Bignum &v2)
{
    std::swap(v1.abs, v2.abs);
    std::swap(v1.isNegative, v2.isNegative);
}
Bignum &Bignum::operator=(Bignum v2)
{
    swap(*this, v2);
    return *this;
}
Bignum &Bignum::operator=(int rhs)
{
    Bignum temp = Bignum(rhs);
    swap(*this, temp);
    return *this;
}
Bignum &Bignum::operator=(const char *rhs)
{
    Bignum temp = Bignum(rhs);
    swap(*this, temp);
    return *this;
}
Bignum Bignum::operator+() const
{
    return *this;
}
Bignum Bignum::operator-() const
{
    Bignum temp = *this;
    temp.setIsNegative(!getIsNegative());
    return temp;
}
Bignum &Bignum::operator+=(const Bignum &rhs)
{
    Bignum lhs = *this, ans;
    if (lhs.getIsNegative() == rhs.getIsNegative())
    {
        ans.setAbs(lhs.getAbs() + rhs.getAbs());
        ans.setIsNegative(lhs.getIsNegative());
    }
    else
    {
        ans = std::max(lhs.getAbs(), rhs.getAbs()) - std::min(lhs.getAbs(), rhs.getAbs());
        ans.setIsNegative((lhs.getAbs() >= rhs.getAbs()) ^ rhs.getIsNegative());
    }
    swap(*this, ans);
    return *this;
}
Bignum &Bignum::operator-=(const Bignum &rhs)
{
    Bignum ans = Bignum((*this) + (-rhs));
    swap(*this, ans);
    return *this;
}
Bignum &Bignum::operator*=(const Bignum &rhs)
{

    Bignum ans = (*this).abs * rhs.abs;
    ans.setIsNegative((*this).getIsNegative() ^ rhs.getIsNegative());
    swap(*this, ans);
    return *this;
}
Bignum &Bignum::operator/=(const Bignum &rhs)
{
    Bignum ans = (*this).abs / rhs.abs;
    ans.setIsNegative((*this).getIsNegative() ^ (rhs.getIsNegative()));
    swap(*this, ans);
    return *this;
}
Bignum &Bignum::operator%=(const Bignum &rhs)
{
    Bignum ans = (*this).abs % rhs.abs;
    ans.setIsNegative((*this).getIsNegative());
    swap(*this, ans);
    return *this;
}

int Bignum::length() const
{
    return getAbs().length();
}
char Bignum::operator[](int index) const
{
    return getAbs()[index];
}

bool operator<(Bignum lhs, const Bignum rhs)
{
    if (lhs.getIsNegative() == rhs.getIsNegative())
    {
        return (lhs.getAbs() < rhs.getAbs()) ^ lhs.getIsNegative();
    }
    return lhs.getIsNegative();
}
bool operator>(Bignum lhs, const Bignum rhs)
{
    return rhs < lhs;
}
bool operator==(Bignum lhs, const Bignum rhs)
{
    return !(lhs > rhs) && !(lhs < rhs);
}
bool operator!=(Bignum lhs, const Bignum rhs)
{
    return !(lhs == rhs);
}
bool operator<=(Bignum lhs, const Bignum rhs)
{
    return lhs < rhs || lhs == rhs;
}
bool operator>=(Bignum lhs, const Bignum rhs)
{
    return lhs > rhs || lhs == rhs;
}

Bignum operator+(Bignum lhs, const Bignum rhs)
{
    lhs += rhs;
    return lhs;
}
Bignum operator-(Bignum lhs, const Bignum rhs)
{
    lhs -= rhs;
    return lhs;
}
Bignum operator*(Bignum lhs, const Bignum rhs)
{
    lhs *= rhs;
    return lhs;
}
Bignum operator/(Bignum lhs, const Bignum rhs)
{
    lhs /= rhs;
    return lhs;
}
Bignum operator%(Bignum lhs, const Bignum rhs)
{
    lhs %= rhs;
    return lhs;
}

void Bignum::printDelimiter()
{
    if (getIsNegative())
        std::cout << "-";
    getAbs().printDelimiter();
}

std::ostream &operator<<(std::ostream &output, const Bignum &v)
{
    if (v.getIsNegative())
        output << '-';
    output << v.abs;
    return output;
}
std::istream &operator>>(std::istream &input, Bignum &v)
{
    std::string temp;
    input >> temp;
    v = Bignum(temp);
    return input;
}
