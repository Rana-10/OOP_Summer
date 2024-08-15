// Assignment 01
// Muhammad Azmat
// OOP-B

#include <iostream>
using namespace std;

void print(int n, char c)
{
    if (n == 0)
        return;
    cout << c;
    print(n - 1, c);
}

void print_shape(int b, int n, int i, int lines = 0)
{
    if (i >= b)
        return;
    if (lines < n)
    {
        int spaces;
        if (i < n / 2 + 1)
        {
            spaces = n * i;
        }
        else
        {
            spaces = n * (b - i - 1);
        }

        print(spaces, ' ');
        print(n, '*');
        cout << endl;

        print_shape(b, n, i, lines + 1);
    }
    else
    {
        print_shape(b, n, i + 1);
    }
}

int main()
{
    int n;
    cout << "Enter an odd value : ";
    cin >> n;
    if (n % 2 == 0)
    {
        cout << "enter odd number! " << endl;
        exit(0);
    }
    else
    {
        print_shape(n, n, 0);
    }
    return 0;
}