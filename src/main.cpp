#include <iostream>
#include "ubignum.hpp"
#include "bignum.hpp"
using namespace std;

int main()
{
    Bignum v1, v2;
    long long int test = 12345;
    cin >> v1;
    cin >> v2;
    cout << "\nCOMPARISONS\n";
    cout << "v1 < v2 = " << (v1 < v2) << endl;
    cout << "v1 > v2 = " << (v1 > v2) << endl;
    cout << "v1 == v2 = " << (v1 == v2) << endl;
    cout << "v1 != v2 = " << (v1 != v2) << endl;
    cout << "v1 <= v2 = " << (v1 <= v2) << endl;
    cout << "v1 >= v2 = " << (v1 >= v2) << endl
         << endl;
    cout << "\nADDITION\n";
    cout << "v1 + 12345 = " << (v1 + test) << endl;
    cout << "12345 + v2 = " << (test + v2) << endl;
    cout << "v1 + v2 = " << (v1 + v2) << endl;
    cout << "\nSUBTRACTION\n";
    cout << "v1 - v2 = " << (v1 - v2) << endl;
    cout << "\nMULTIPLICATION\n";
    cout << "v1 * v2 = " << (v1 * v2) << endl;
    // cout << "v1 / v2 = " << (v1 / v2) << endl; // Bignumber by Bignumber division is O(answer) which can be really slow
    cout << "\nDIVISION\n";
    cout << "v1 / 100 = " << (v1 / 100) << endl;
    cout << "v2 / 2 = " << (v2 / 2) << endl;
    cout << "\nMODULUS\n";
    // cout << "v1 % v2 = " << (v1 % v2) << endl;
    cout << "v1 % 100 = " << (v1 % 100) << endl;
    cout << "v2 % 2 = " << (v2 % 2) << endl
         << endl;
    cout << "\nSUBSCRIPT OPERATOR\n";
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
    cout << "\nv1.printDelimiter()\n";
    v1.printDelimiter();
}