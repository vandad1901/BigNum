#include <iostream>
#include "ubignum.hpp"
#include "sbignum.hpp"
using namespace std;

int main()
{
    SBignum v1, v2;
    long long int test = 12345;
    cin >> v1;
    cin >> v2;
    cout << "v1 < v2 = " << (v1 < v2) << endl;
    cout << "v1 > v2 = " << (v1 > v2) << endl;
    cout << "v1 == v2 = " << (v1 == v2) << endl;
    cout << "v1 != v2 = " << (v1 != v2) << endl;
    cout << "v1 <= v2 = " << (v1 <= v2) << endl;
    cout << "v1 >= v2 = " << (v1 >= v2) << endl
         << endl;
    cout << "v1 + 12345 = " << (v1 + test) << endl;
    cout << "v1 + v2 = " << (v1 + v2) << endl;
    cout << "v1 - v2 = " << (v1 - v2) << endl;
    cout << "v1 * v2 = " << (v1 * v2) << endl;
    // cout << "v1 / v2 = " << (v1 / v2) << endl; //Bignumber
    cout << "v1 / 100 = " << (v1 / 100) << endl;
    cout << "v2 / 2 = " << (v2 / 2) << endl;
    // cout << "v1 % v2 = " << (v1 % v2) << endl;
    cout << "v1 % 100 = " << (v1 % 100) << endl;
    cout << "v2 % 2 = " << (v2 % 2) << endl
         << endl;

    for (int i = 0; i < v1.length(); i++)
    {
        cout << "v1[" << i << "] = " << v1[i] << endl;
    }
    try
    {
        cout << "v2[" << v2.length() + 1 << "] = ";
        cout << v2[v2.length() + 1] << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
    v1.printWithDelimiter();
}