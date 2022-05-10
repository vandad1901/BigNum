#include <iostream>
#include "ubignum.hpp"
#include "bignum.hpp"
using namespace std;

int main()
{
    Bignum v1, v2, v3;
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
    cout << "v1 < 5 = " << (v1 < 5) << endl;
    cout << "5 < v1 = " << (5 < v1) << endl;
    cout << "\nADDITION\n";
    cout << "v1 + 12345 = " << (v1 + test) << endl;
    cout << "12345 + v2 = " << (test + v2) << endl;
    cout << "v1 + v2 = " << (v1 + v2) << endl;
    cout << "\nSUBTRACTION\n";
    cout << "v1 - 12345 = " << (v1 - test) << endl;
    cout << "12345 - v2 = " << (test - v2) << endl;
    cout << "v1 - v2 = " << (v1 - v2) << endl;
    cout << "\nMULTIPLICATION\n";
    cout << "v1 * 2000 = " << (v1 * 2000) << endl;
    cout << "2000 * v2 = " << (2000 * v2) << endl;
    cout << "v1 * v2 = " << (v1 * v2) << endl;
    cout << "\nDIVISION\n";
    cout << "v1 / v2 = " << (v1 / v2) << endl;
    cout << "v1 / 100 = " << (v1 / 100) << endl;
    cout << "v2 / 2 = " << (v2 / 2) << endl;
    cout << "\nMODULUS\n";
    cout << "v1 % v2 = " << (v1 % v2) << endl;
    cout << "v1 % 100 = " << (v1 % 100) << endl;
    cout << "v2 % 2 = " << (v2 % 2) << endl;
    cout << "\nASSIGNMENT AND CONVERSION\n";
    cout << "v3 = 400\ncout << v3 --> ";
    v3 = 400;
    cout << v3 << endl;
    cout << "v3 = \"500\"\ncout << v3 --> ";
    v3 = "500";
    cout << v3 << endl;
    cout << "v3 += 150\ncout << v3 --> ";
    v3 += 150;
    cout << v3 << endl;

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
        cout << e.what() << "(Exception thrown)" << endl;
    }
    cout << "\nv1.printDelimiter()\n";
    v1.printDelimiter();
    return 0;
}