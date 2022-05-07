#include <iostream>
#include "ubignum.hpp"

UBignum::UBignum(std::string str)
{
    setDigits(str);
}
UBignum::UBignum(long long int num)
{
    setDigits(std::to_string(num));
}

std::string UBignum::getDigits() const
{
    return digits;
}
void UBignum::setDigits(std::string str)
{
    int lastLeadingZero = -1;
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] >= '0') && (str[i] <= '9'))
        {
            if (str[i] == '0' && lastLeadingZero == i - 1)
                lastLeadingZero = i;
        }
        else
        {
            throw std::invalid_argument("Digits should only consist of numbers");
        }
    }
    if (lastLeadingZero == str.length() - 1)
        digits = "0";
    else
        digits = str.substr(lastLeadingZero + 1, str.length() - lastLeadingZero - 1);
}
void swap(UBignum &v1, UBignum &v2)
{
    std::swap(v1.digits, v2.digits);
}
UBignum &UBignum::operator=(UBignum v2)
{
    swap(*this, v2);
    return *this;
}
UBignum &UBignum::operator+=(const UBignum &rhs)
{
    UBignum lhs = (*this);
    int adigit, bdigit, carry = 0, alen = lhs.length(), blen = rhs.length();
    std::string ans(std::max(alen, blen) + 1, '0');
    for (int i = 0; i < std::max(alen, blen); i++)
    {
        adigit = i < alen ? (lhs[i] - '0') : 0;
        bdigit = i < blen ? (rhs[i] - '0') : 0;
        ans[ans.length() - i - 1] = ((adigit + bdigit + carry) % 10) + '0';
        carry = (adigit + bdigit + carry) > 9 ? 1 : 0;
    }
    ans[0] = carry + '0';
    UBignum temp = UBignum(ans);
    swap(*this, temp);
    return *this;
}
UBignum &UBignum::operator-=(const UBignum &rhs)
{
    if ((*this) >= rhs)
    {
        UBignum lhs = (*this);
        int adigit, bdigit, carry = 0, alen = lhs.length(), blen = rhs.length();
        std::string ans(std::max(alen, blen) + 1, '0');
        for (int i = 0; i < std::max(alen, blen); i++)
        {
            adigit = i < alen ? (lhs[i] - '0') : 0;
            bdigit = i < blen ? (rhs[i] - '0') : 0;
            ans[ans.length() - i - 1] = ((adigit - bdigit + carry + 10) % 10) + '0';
            carry = (adigit - bdigit + carry) < 0 ? -1 : 0;
        }
        UBignum temp = UBignum(ans);
        swap(*this, temp);
        return *this;
    }
    else
        throw std::invalid_argument("This subtraction results in a negative value");
}
UBignum &UBignum::operator*=(const UBignum &rhs)
{
    UBignum lhs = (*this);
    int carry = 0;
    if (lhs == 0 || rhs == 0)
    {
        UBignum temp = UBignum(0);
        swap(*this, temp);
        return *this;
    }
    std::string ans(lhs.length() + rhs.length(), 0);
    for (int i = 0; i < lhs.length(); i++)
    {
        for (int j = 0; j < rhs.length(); j++)
        {
            carry = (lhs[i] - '0') * (rhs[j] - '0') + ans[lhs.length() + rhs.length() - (i + j + 1)];
            ans[lhs.length() + rhs.length() - (i + j + 1)] = carry % 10;  // v1+v2-1 to 1
            ans[lhs.length() + rhs.length() - (i + j + 2)] += carry / 10; // v1+v2-2 to 0
        }
    }

    for (int i = 0; i < ans.length(); i++)
    {
        ans[i] += '0';
    }
    UBignum temp = UBignum(ans);
    swap(*this, temp);
    return *this;
}
UBignum &UBignum::operator/=(const UBignum &rhs)
{
    if (rhs == 0)
    {
        throw std::invalid_argument("Cannot divide by zero");
    }
    UBignum lhs = *this;
    UBignum ans = 0, i;
    for (i = 0; i < lhs; i = i + rhs)
    {
        ans = ans + 1;
    }
    UBignum temp = UBignum(ans - int(i > lhs));
    swap(*this, temp);
    return *this;
}
UBignum &UBignum::operator/=(const long long int &rhs)
{
    UBignum lhs = (*this);
    std::string ans;
    for (int i = 0, temp = 0; i <= lhs.length(); temp = (temp % rhs) * 10 + lhs[lhs.length() - (i++) - 1] - '0')
        ans += (temp / rhs) + '0';

    UBignum temp = UBignum(ans);
    swap(*this, temp);
    return *this;
}
UBignum &UBignum::operator%=(const UBignum &rhs)
{
    UBignum lhs = *this;
    UBignum temp = UBignum(lhs - (lhs / rhs) * rhs);
    swap(*this, temp);
    return *this;
}
UBignum &UBignum::operator%=(const long long int &rhs)
{
    UBignum lhs = *this;
    UBignum temp = UBignum(lhs - (lhs / rhs) * rhs);
    swap(*this, temp);
    return *this;
}

int UBignum::length() const
{
    return digits.length();
}
char UBignum::operator[](int index) const
{
    if (index < length())
        return getDigits()[length() - index - 1];
    else
        throw std::out_of_range("The index is not in the acceptable range");
}

bool operator<(UBignum lhs, const UBignum rhs)
{
    if (lhs.length() < rhs.length())
        return true;
    if (lhs.length() > rhs.length())
        return false;
    for (int i = 0; i < lhs.length(); i++)
        if (lhs.digits[i] < rhs.digits[i])
            return true;
        else if (lhs.digits[i] > rhs.digits[i])
            return false;

    return false;
}
bool operator>(UBignum lhs, const UBignum rhs)
{
    return rhs < lhs;
}
bool operator==(UBignum lhs, const UBignum rhs)
{
    return !(lhs > rhs) && !(lhs < rhs);
}
bool operator!=(UBignum lhs, const UBignum rhs)
{
    return !(lhs == rhs);
}
bool operator<=(UBignum lhs, const UBignum rhs)
{
    return lhs < rhs || lhs == rhs;
}
bool operator>=(UBignum lhs, const UBignum rhs)
{
    return lhs > rhs || lhs == rhs;
}

UBignum operator+(UBignum lhs, const UBignum rhs)
{
    lhs += rhs;
    return lhs;
}
UBignum operator-(UBignum lhs, const UBignum rhs)
{
    lhs -= rhs;
    return lhs;
}
UBignum operator*(UBignum lhs, const UBignum rhs)
{
    lhs *= rhs;
    return lhs;
}
UBignum operator/(UBignum lhs, const UBignum rhs)
{
    lhs /= rhs;
    return lhs;
}
UBignum operator/(UBignum lhs, const long long int rhs)
{
    lhs /= rhs;
    return lhs;
}
UBignum operator%(UBignum lhs, const UBignum rhs)
{
    lhs %= rhs;
    return lhs;
}
UBignum operator%(UBignum lhs, const long long int rhs)
{
    lhs %= rhs;
    return lhs;
}

void UBignum::printDelimiter()
{
    for (int i = length() - 1; i >= 0; i--)
    {
        std::cout << (*this)[i];
        if (i % 3 == 0 && i > 0)
            std::cout << ",";
    }
    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &output, const UBignum &v)
{
    output << v.digits;
    return output;
}
std::istream &operator>>(std::istream &input, UBignum &v)
{
    std::string temp;
    input >> temp;
    v = UBignum(temp);
    return input;
}
