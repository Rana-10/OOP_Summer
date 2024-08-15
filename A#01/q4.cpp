// Assignment 01
// Muhammad Azmat
// OOP-B

#include <iostream>
#include <string>

using namespace std;

bool is_balanced(string x, int a, int b);

int main()
{
    string a = "int main() x = 2* (vec[2] + 3)x = (1 + random())";
    cin >> a;
    bool verify = is_balanced(a, 0, a.length() - 1);

    if (verify == true)
    {
        cout << "The string has proper balancing done" << endl;
    }
    else
    {
        cout << "The string is not properly balanced" << endl;
    }

    return 0;
}

bool is_balanced(string x, int a, int b)
{
    if (a > b)
    {
        return true;
    }

    if ((x[a] == '{' && x[b] == '}') || (x[a] == '[' && x[b] == ']') || (x[a] == '(' && x[b] == ')'))
    {
        return is_balanced(x, a + 1, b - 1);
    }
    else
    {
        return false;
    }
}