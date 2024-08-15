// Assignment 02
// Muhammad Azmat
// 23i-2651
// OOP-B

#include <iostream>
#include <string>

using namespace std;

void helper_1(int x, char y);
void helper_2(int x);
void helper_3(int x);

int main()
{
    helper_2(1);

    helper_1(9, ' ');
    helper_1(1, '/');
    helper_1(1, '.');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, '1');
    helper_1(1, '2');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, '.');
    helper_1(1, ' ');
    helper_1(1, '\\');
    cout << endl;

    helper_1(8, ' ');
    helper_1(1, '/');
    helper_1(1, '/');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, '\\');
    helper_1(1, '\\');
    cout << endl;

    helper_1(7, ' ');
    helper_1(1, '|');
    helper_1(1, '|');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, '/');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, '|');
    helper_1(1, '|');
    cout << endl;

    helper_1(7, ' ');
    helper_1(1, '|');
    helper_1(1, '|');
    helper_1(1, '9');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, '.');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, '3');
    helper_1(1, '|');
    helper_1(1, '|');
    cout << endl;

    helper_1(7, ' ');
    helper_1(1, '|');
    helper_1(1, '|');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, '/');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, '|');
    helper_1(1, '|');
    cout << endl;

    helper_1(8, ' ');
    helper_1(1, '\\');
    helper_1(1, '\\');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, '/');
    helper_1(1, '/');
    cout << endl;

    helper_1(9, ' ');
    helper_1(1, '\\');
    helper_1(1, '.');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, '6');
    helper_1(1, ' ');
    helper_1(1, ' ');
    helper_1(1, '.');
    helper_1(1, ' ');
    helper_1(1, '/');
    cout << endl;

    helper_3(1);

    return 0;
}

void helper_1(int x, char y)
{
    if (x == 0)
    {
        return;
    }
    cout << y << " ";
    helper_1(x - 1, y);
}

void helper_2(int x)
{
    if (x == 0)
    {
        return;
    }
    helper_1(10, ' ');
    helper_1(1, '|');
    helper_1(1, ':');
    helper_1(5, ' ');
    helper_1(1, ':');
    helper_1(1, '|');
    cout << endl;

    helper_1(10, ' ');
    helper_1(1, '|');
    helper_1(1, ':');
    helper_1(5, ' ');
    helper_1(1, ':');
    helper_1(1, '|');
    cout << endl;

    helper_1(10, ' ');
    helper_1(1, '|');
    helper_1(1, ':');
    helper_1(5, '_');
    helper_1(1, ':');
    helper_1(1, '|');
    cout << endl;

    helper_1(10, ' ');
    helper_1(1, '(');
    helper_1(1, '=');
    helper_1(5, '_');
    helper_1(1, '=');
    helper_1(1, ')');
    cout << endl;

    helper_2(x - 1);
}

void helper_3(int x)
{
    if (x == 0)
    {
        return;
    }
    helper_1(10, ' ');
    helper_1(1, '(');
    helper_1(1, '=');
    helper_1(5, '_');
    helper_1(1, '=');
    helper_1(1, ')');
    cout << endl;

    helper_1(10, ' ');
    helper_1(1, '|');
    helper_1(1, ':');
    helper_1(5, '_');
    helper_1(1, ':');
    helper_1(1, '|');
    cout << endl;

    helper_1(10, ' ');
    helper_1(1, '|');
    helper_1(1, ':');
    helper_1(5, ' ');
    helper_1(1, ':');
    helper_1(1, '|');
    cout << endl;

    helper_1(10, ' ');
    helper_1(1, '|');
    helper_1(1, ':');
    helper_1(5, ' ');
    helper_1(1, ':');
    helper_1(1, '|');
    cout << endl;

    helper_3(x - 1);
}