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

bool UBignum::operator<(UBignum v2) const
{
    UBignum v1 = *this;
    if (length() < v2.length())
        return true;
    if (length() > v2.length())
        return false;
    for (int i = 0; i < length(); i++)
        if ((*this).digits[i] < v2.digits[i])
            return true;
        else if ((*this).digits[i] > v2.digits[i])
            return false;

    return false;
}
bool UBignum::operator>(UBignum v2) const
{
    return v2 < (*this);
}
bool UBignum::operator==(UBignum v2) const
{
    return !((*this) > v2) && !((*this) < v2);
}
bool UBignum::operator!=(UBignum v2) const
{
    return !((*this) == v2);
}
bool UBignum::operator<=(UBignum v2) const
{
    return (*this) < v2 || (*this) == v2;
}
bool UBignum::operator>=(UBignum v2) const
{
    return (*this) > v2 || (*this) == v2;
}

UBignum UBignum::operator+(UBignum v2) const
{
    UBignum v1 = (*this);
    int adigit, bdigit, carry = 0, alen = v1.length(), blen = v2.length();
    std::string ans(std::max(alen, blen) + 1, '0');
    for (int i = 0; i < std::max(alen, blen); i++)
    {
        adigit = i < alen ? (v1[i] - '0') : 0;
        bdigit = i < blen ? (v2[i] - '0') : 0;
        ans[ans.length() - i - 1] = ((adigit + bdigit + carry) % 10) + '0';
        carry = (adigit + bdigit + carry) > 9 ? 1 : 0;
    }
    ans[0] = carry + '0';
    return ans;
}
UBignum UBignum::operator-(UBignum v2) const
{
    if ((*this) >= v2)
    {
        UBignum v1 = (*this);
        int adigit, bdigit, carry = 0, alen = v1.length(), blen = v2.length();
        std::string ans(std::max(alen, blen) + 1, '0');
        for (int i = 0; i < std::max(alen, blen); i++)
        {
            adigit = i < alen ? (v1[i] - '0') : 0;
            bdigit = i < blen ? (v2[i] - '0') : 0;
            ans[ans.length() - i - 1] = ((adigit - bdigit + carry + 10) % 10) + '0';
            carry = (adigit - bdigit + carry) < 0 ? -1 : 0;
        }
        return ans;
    }
    else
        throw std::invalid_argument("This subtraction results in a negative value");
}
UBignum UBignum::operator*(UBignum v2) const
{
    UBignum v1 = (*this).getDigits();
    int carry = 0;
    if (v1 == 0 || v2 == 0)
        return 0;
    std::string ans(v1.length() + v2.length(), 0);
    for (int i = 0; i < v1.length(); i++)
    {
        for (int j = 0; j < v2.length(); j++)
        {
            carry = (v1[i] - '0') * (v2[j] - '0') + ans[v1.length() + v2.length() - (i + j + 1)];
            ans[v1.length() + v2.length() - (i + j + 1)] = carry % 10;  // v1+v2-1 to 1
            ans[v1.length() + v2.length() - (i + j + 2)] += carry / 10; // v1+v2-2 to 0
        }
    }

    for (int i = 0; i < ans.length(); i++)
    {
        ans[i] += '0';
    }
    return ans;
}
UBignum UBignum::operator/(UBignum v2) const
{
    if (v2 == 0)
    {
        throw std::invalid_argument("Cannot divide by zero");
    }
    UBignum v1 = (*this).getDigits();
    UBignum temp = 0, i;
    for (i = 0; i < v1; i = i + v2)
    {
        temp = temp + 1;
    }
    return temp - int(i > v1);
}
UBignum UBignum::operator/(long long int v2) const
{
    UBignum v1 = (*this).getDigits();
    std::string ans;
    for (int i = 0, temp = 0; i <= v1.length(); temp = (temp % v2) * 10 + v1[v1.length() - (i++) - 1] - '0')
        ans += (temp / v2) + '0';
    return ans;
}
UBignum UBignum::operator%(UBignum v2) const
{
    UBignum v1 = (*this).getDigits();
    return v1 - (v1 / v2) * v2;
}
UBignum UBignum::operator%(long long int v2) const
{
    UBignum v1 = (*this).getDigits();
    return v1 - (v1 / v2) * v2;
}

void UBignum::printWithDelimiter()
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
