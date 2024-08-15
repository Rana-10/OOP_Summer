// Assignment 01
// Muhammad Azmat
// OOP-B

#include <iostream>
using namespace std;

void print_pattern(int x, int count);
void print_pattern2(int x, int count);
void print_stars(int x);
void print_space(int x);

int main()
{
    print_pattern(8, 1);
    print_pattern2(8, 1);
    return 0;
}

void print_pattern(int x, int count)
{
    if (count > x)
    {
        return;
    }
    print_space(x - count);
    print_space(x);
    print_stars(count);
    cout << endl;
    print_pattern(x, count + 1);
}

void print_pattern2(int x, int count)
{
    if (count > x)
    {
        return;
    }
    print_space(x - count);
    print_stars(count);
    print_space(x - count);
    print_space(3);
    print_stars(count);
    cout << endl;
    print_pattern2(x, count + 1);
}

void print_stars(int x)
{
    if (x == 0)
    {
        return;
    }
    cout << " * ";
    print_stars(x - 1);
}

void print_space(int x)
{
    if (x == 0)
    {
        return;
    }
    cout << "  ";
    print_space(x - 1);
}
