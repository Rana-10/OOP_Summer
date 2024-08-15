// Assignment 01
// Muhammad Azmat
// OOP-B

#include <iostream>
#include <string>
using namespace std;

string findLastSubstring(string str)
{
    int len = str.length();
    if (len == 0)
        return str;

    int maxIndex = 0;
    int i = 1;

    while (i < len)
    {
        int j = 0;

        while (maxIndex + j < len && i + j < len && str[maxIndex + j] == str[i + j])
        {
            j++;
        }
        if (i + j >= len || (maxIndex + j < len && str[i + j] > str[maxIndex + j]))
        {
            maxIndex = i;
            i++;
        }
        else
        {
            i += j + 1;
        }
    }

    string result;
    for (int k = maxIndex; k < len; ++k)
    {
        result += str[k];
    }

    return result;
}

int main()
{
    string str1 = "abab";
    string str2 = "Programmersz";

    cout << "Input: " << str1 << " => Output: " << findLastSubstring(str1) << endl;
    cout << "Input: " << str2 << " => Output: " << findLastSubstring(str2) << endl;

    return 0;
}
