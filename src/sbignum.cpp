#include <iostream>
#include "sbignum.hpp"
#include "ubignum.hpp"

SBignum::SBignum(std::string str)
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
SBignum::SBignum(long long int num)
{
    setAbs(num);
    setIsNegative(num < 0);
}
SBignum::SBignum(UBignum num, bool val)
{
    setAbs(num);
    setIsNegative(val);
}

UBignum SBignum::getAbs() const
{
    return abs;
}
void SBignum::setAbs(UBignum str)
{
    abs = str;
}
bool SBignum::getIsNegative() const
{
    return isNegative;
}
void SBignum::setIsNegative(bool val)
{
    isNegative = val;
}
void swap(SBignum &v1, SBignum &v2)
{
    std::swap(v1.abs, v2.abs);
    std::swap(v1.isNegative, v2.isNegative);
}
SBignum &SBignum::operator=(SBignum v2)
{
    swap(*this, v2);
    return *this;
}
SBignum SBignum::operator+() const
{
    return *this;
}
SBignum SBignum::operator-() const
{
    SBignum temp = *this;
    temp.setIsNegative(!getIsNegative());
    return temp;
}
SBignum &SBignum::operator+=(const SBignum &rhs)
{
    SBignum lhs = *this, ans;
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
SBignum &SBignum::operator-=(const SBignum &rhs)
{
    SBignum ans = SBignum((*this) + (-rhs));
    swap(*this, ans);
    return *this;
}
SBignum &SBignum::operator*=(const SBignum &rhs)
{

    SBignum ans = (*this).abs * rhs.abs;
    ans.setIsNegative((*this).getIsNegative() ^ rhs.getIsNegative());
    swap(*this, ans);
    return *this;
}
SBignum &SBignum::operator/=(const SBignum &rhs)
{
    SBignum ans = (*this).abs / rhs.abs;
    ans.setIsNegative((*this).getIsNegative() ^ rhs.getIsNegative());
    swap(*this, ans);
    return *this;
}
SBignum &SBignum::operator/=(const long long int &rhs)
{
    SBignum ans = (*this).abs / rhs;
    ans.setIsNegative((*this).getIsNegative() ^ (rhs < 0));
    swap(*this, ans);
    return *this;
}
SBignum &SBignum::operator%=(const SBignum &rhs)
{
    SBignum ans = (*this).abs % rhs.abs;
    ans.setIsNegative((*this).getIsNegative());
    swap(*this, ans);
    return *this;
}
SBignum &SBignum::operator%=(const long long int &rhs)
{
    SBignum ans = (*this).abs % rhs;
    ans.setIsNegative((*this).getIsNegative());
    swap(*this, ans);
    return *this;
}

int SBignum::length() const
{
    return getAbs().length();
}
char SBignum::operator[](int index) const
{
    return getAbs()[index];
}

bool operator<(SBignum lhs, const SBignum rhs)
{
    if (lhs.getIsNegative() == rhs.getIsNegative())
    {
        return (lhs.getAbs() < rhs.getAbs()) ^ lhs.getIsNegative();
    }
    return lhs.getIsNegative();
}
bool operator>(SBignum lhs, const SBignum rhs)
{
    return rhs < lhs;
}
bool operator==(SBignum lhs, const SBignum rhs)
{
    return !(lhs > rhs) && !(lhs < rhs);
}
bool operator!=(SBignum lhs, const SBignum rhs)
{
    return !(lhs == rhs);
}
bool operator<=(SBignum lhs, const SBignum rhs)
{
    return lhs < rhs || lhs == rhs;
}
bool operator>=(SBignum lhs, const SBignum rhs)
{
    return lhs > rhs || lhs == rhs;
}

SBignum operator+(SBignum lhs, const SBignum rhs)
{
    lhs += rhs;
    return lhs;
}
SBignum operator-(SBignum lhs, const SBignum rhs)
{
    lhs -= rhs;
    return lhs;
}
SBignum operator*(SBignum lhs, const SBignum rhs)
{
    lhs *= rhs;
    return lhs;
}
SBignum operator/(SBignum lhs, const SBignum rhs)
{
    lhs /= rhs;
    return lhs;
}
SBignum operator/(SBignum lhs, const long long int rhs)
{
    lhs /= rhs;
    return lhs;
}
SBignum operator%(SBignum lhs, const SBignum rhs)
{
    lhs %= rhs;
    return lhs;
}
SBignum operator%(SBignum lhs, const long long int rhs)
{
    lhs %= rhs;
    return lhs;
}

void SBignum::printWithDelimiter()
{
    if (getIsNegative())
        std::cout << "-";
    getAbs().printWithDelimiter();
}

std::ostream &operator<<(std::ostream &output, const SBignum &v)
{
    if (v.getIsNegative())
        output << '-';
    output << v.abs;
    return output;
}
std::istream &operator>>(std::istream &input, SBignum &v)
{
    std::string temp;
    input >> temp;
    v = SBignum(temp);
    return input;
}
