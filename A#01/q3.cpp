// Assignment 01
// Muhammad Azmat
// OOP-B

#include <iostream>
using namespace std;

void printa(int n, char c)
{
    if (n <= 0)
        return;
    else
    {
        cout << c;
        printa(n - 1, c);
    }
}

void printb(int n, int i, char ch, char c, char start)
{
    if (i > n)
        return;
    else
    {
        if (i == n || i == 1)
        {
            cout << start;
        }

        else if (i == n / 2 + 1)
        {
            cout << c;
        }
        else
        {
            cout << ch;
        }

        printb(n, i + 1, ch, c, start);
    }
}
void printd(int n, int i, char c)

{
    if (i > n)
        return;
    else
    {
        printb(5, 1, ' ', ' ', '|');
        printb(5, 1, ' ', c, '|');
        printb(5, 1, ' ', ' ', '|');
        printb(5, 1, ' ', ' ', '|');
        printb(5, 1, ' ', ' ', '|');
        printa(13, ' ');

        printb(5, 1, ' ', ' ', '|');
        printb(5, 1, ' ', ' ', '|');
        printb(5, 1, ' ', ' ', '|');
        printb(5, 1, ' ', ' ', '|');
        printb(5, 1, ' ', c, '|');
        cout << endl;
        printd(n, i + 1, c);
    }
}
void printc(int n, int i, bool a)
{
    if (i > n)
        return;
    else
    {

        if (a == true)
        {

            if (i == 0 || i == n)
            {
                printa(63, '-');
                cout << endl;
            }
            cout << "|";
            if (i == 2 || i == 4 || i == 8 || i == 10)
            {
                printa(3, '/');
                printa(5, '-');
                printa(7, '/');
                printa(5, '-');
                printa(3, '/');
            }
            else
            {
                printa(23, '/');
            }
            if (i == 4)
            {
                printb(5, 1, ' ', 'X', '|');
            }
            else
            {
                printb(5, 1, ' ', ' ', '|');
            }
            printb(5, 1, ' ', ' ', '|');
            if (i == 2)
            {
                printb(5, 1, ' ', 'X', '|');
            }
            else
            {
                printb(5, 1, ' ', ' ', '|');
            }
            if (i == 2 || i == 4 || i == 8 || i == 10)
            {
                printa(3, '/');
                printa(5, '-');
                printa(7, '/');
                printa(5, '-');
                printa(3, '/');
            }
            else
            {
                printa(23, '/');
            }
            cout << "|";
            a = false;
        }
        else
        {
            cout << "|";
            if (i == 3 || i == 9)
            {
                printa(3, '/');
                printa(5, ' ');
                printa(7, '/');
                printa(5, ' ');
                printa(3, '/');
            }
            else
            {
                printa(23, '/');
            }
            printb(5, 1, '-', '-', '|');
            printb(5, 1, '-', '-', '|');
            printb(5, 1, '-', '-', '|');
            if (i == 3 || i == 9)
            {
                printa(3, '/');
                printa(5, ' ');
                printa(7, '/');
                printa(5, ' ');
                printa(3, '/');
            }
            else
            {
                printa(23, '/');
            }
            cout << "|";
            a = true;
        }

        cout << endl;
    }

    printc(n, i + 1, a);

    i--;
    if (i == 10)
    {

        printa(63, '-');
        cout << endl;
        printd(0, 0, 'X');

        printb(25, 1, '-', '-', '|');
        printb(13, 1, ' ', ' ', ' ');
        printb(25, 1, '-', '-', '|');

        cout
            << endl;
        printd(0, 0, ' ');
        printb(25, 1, '-', '-', '|');
        printb(13, 1, ' ', ' ', ' ');
        printb(25, 1, '-', '-', '|');

        cout
            << endl;
        printd(0, 0, 'X');
        printb(25, 1, '-', '-', '|');
        printb(13, 1, ' ', ' ', ' ');
        printb(25, 1, '-', '-', '|');

        cout
            << endl;
        printa(63, '-');
        cout
            << endl;
    }

    if (a == true)
    {
        if (i == 1)
        {
            printa(63, '-');
            cout << endl;
        }
        cout << "|";
        if (i == 2 || i == 4 || i == 8 || i == 10)
        {
            printa(3, '/');
            printa(5, '-');
            printa(7, '/');
            printa(5, '-');
            printa(3, '/');
        }
        else
        {
            printa(23, '/');
        }
        if (i == 4)
        {
            printb(5, 1, ' ', 'X', '|');
        }
        else
        {
            printb(5, 1, ' ', ' ', '|');
        }
        printb(5, 1, ' ', ' ', '|');
        if (i == 2)
        {
            printb(5, 1, ' ', 'X', '|');
        }
        else
        {
            printb(5, 1, ' ', ' ', '|');
        }
        if (i == 2 || i == 4 || i == 8 || i == 10)
        {
            printa(3, '/');
            printa(5, '-');
            printa(7, '/');
            printa(5, '-');
            printa(3, '/');
        }
        else
        {
            printa(23, '/');
        }
        cout << "|";
        a = false;
    }
    else
    {
        cout << "|";
        if (i == 3 || i == 9)
        {
            printa(3, '/');
            printb(5, 1, ' ', 'R', ' ');
            printa(7, '/');
            printb(5, 1, ' ', 'R', ' ');
            printa(3, '/');
        }
        else
        {
            printa(23, '/');
        }
        printb(5, 1, '-', '-', '|');
        printb(5, 1, '-', '-', '|');
        printb(5, 1, '-', '-', '|');
        if (i == 3 || i == 9)
        {
            printa(3, '/');
            printa(5, ' ');
            printa(7, '/');
            printa(5, ' ');
            printa(3, '/');
        }
        else
        {
            printa(23, '/');
        }
        cout << "|";
        a = true;
    }

    cout << endl;
}

int main()
{
    cout << "Printing the Grid:" << endl;
    printc(11, 0, true);
    return 0;
}