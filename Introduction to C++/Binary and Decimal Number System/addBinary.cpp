#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b)
{
    string result = "";
    int carry = 0;
    int i = a.length() - 1, j = b.length() - 1;

    while (i >= 0 || j >= 0)
    {
        int sum = carry;
        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';
        result = to_string(sum % 2) + result;
        carry = sum / 2;
    }

    if (carry)
        result = "1" + result;
    return result;
}

int main()
{
    string a, b;
    cout << "Enter first binary number: ";
    cin >> a;
    cout << "Enter second binary number: ";
    cin >> b;

    cout << "Sum of binary numbers: " << addBinary(a, b) << endl;
    return 0;
}
