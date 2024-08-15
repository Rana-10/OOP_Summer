// Assignment 01
// Muhammad Azmat
// OOP-B

#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    ifstream read("dictionary.txt");

    int rows = 5;
    int cols = 5;

    char **array = new char *[rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new char[cols];
    }

    return 0;
}