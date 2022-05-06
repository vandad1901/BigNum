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

int SBignum::length() const
{
    return getAbs().length();
}
char SBignum::operator[](int index) const
{
    return getAbs()[index];
}

bool SBignum::operator<(SBignum v2) const
{
    SBignum v1 = (*this);
    if (v1.getIsNegative() == v2.getIsNegative())
    {
        return (v1.getAbs() < v2.getAbs()) ^ v1.getIsNegative();
    }
    return v1.getIsNegative();
}
bool SBignum::operator>(SBignum v2) const
{
    return v2 < (*this);
}
bool SBignum::operator==(SBignum v2) const
{
    return !((*this) > v2) && !((*this) < v2);
}
bool SBignum::operator!=(SBignum v2) const
{
    return !((*this) == v2);
}
bool SBignum::operator<=(SBignum v2) const
{
    return (*this) < v2 || (*this) == v2;
}
bool SBignum::operator>=(SBignum v2) const
{
    return (*this) > v2 || (*this) == v2;
}

SBignum SBignum::operator+(SBignum v2) const
{
    SBignum v1 = (*this).abs, ans;
    if (v1.getIsNegative() == v2.getIsNegative())
    {
        ans.setAbs(v1.getAbs() + v2.getAbs());
        ans.setIsNegative(v1.getIsNegative());
        return ans;
    }

    ans = std::max(v1.getAbs(), v2.getAbs()) - std::min(v1.getAbs(), v2.getAbs());
    ans.setIsNegative((v1.getAbs() >= v2.getAbs()) ^ v2.getIsNegative());
    return ans;
}
SBignum SBignum::operator-() const
{
    SBignum temp = (*this).abs;
    temp.setIsNegative(!getIsNegative());
    return temp;
}
SBignum SBignum::operator-(SBignum v2) const
{
    return (*this) + (-v2);
}
SBignum SBignum::operator*(SBignum v2) const
{
    SBignum temp = (*this).abs * v2.abs;
    temp.setIsNegative((*this).getIsNegative() ^ v2.getIsNegative());
    return temp;
}
SBignum SBignum::operator/(SBignum v2) const
{
    SBignum temp = (*this).abs / v2.abs;
    temp.setIsNegative((*this).getIsNegative() ^ v2.getIsNegative());
    return temp;
}
SBignum SBignum::operator/(long long int v2) const
{
    SBignum temp = (*this).abs / v2;
    temp.setIsNegative((*this).getIsNegative() ^ v2 < 0);
    return temp;
}
SBignum SBignum::operator%(SBignum v2) const
{
    SBignum temp = (*this).abs % v2.abs;
    temp.setIsNegative((*this).getIsNegative());
    return temp;
}
SBignum SBignum::operator%(long long int v2) const
{
    SBignum temp = (*this).abs % v2;
    temp.setIsNegative((*this).getIsNegative());
    return temp;
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
