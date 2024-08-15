// Assignment 02
// Muhammad Azmat
// 23i-2651
// OOP-B

#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

bool compareChars(string main, string find, int k)
{
    int count = 0;
    for (int i = 0; i < find.length(); i++)
    {
        for (int j = 0; j < main.length(); j++)
        {
            if (find[i] == main[j])
                count++;
            if (count == k)
                break;
        }
        if (count < k)
            return false;
        count = 0;
    }
    return true;
}

char *findSubstring(string main, string find, int k, int start = 0, int dist = 1)
{
    if ((start + dist > main.length()) || (dist > main.length()))
    {
        char *rtr = new char[1];
        rtr[0] = '\0';
        return rtr;
    }
    string substr = "";
    for (int i = start; i < start + dist; i++)
        substr += main[i];
    // cout<<substr<<" dist: "<<dist<<endl;
    if (compareChars(substr, find, k))
    {
        return (char *)substr.c_str();
    }
    else
    {
        if (start + dist == main.length() && dist < main.length()) // sizeof(main)/sizeof(char)
            return findSubstring(main, find, k, 0, dist + 1);
        else
            return findSubstring(main, find, k, start + 1, dist);
    }
}

char *smallest_substring_with_k_occurences(const char *main, const char *find, int k)
{
    string str(main);
    string str2(find);
    return findSubstring(main, find, k);
}

int main()
{
    char str1[14] = "adobecodebanc";
    char str2[4] = "abc";
    char str3[14] = "aaaabbbbccccc";
    cout << smallest_substring_with_k_occurences(str1, str2, 2) << endl;
    cout << smallest_substring_with_k_occurences(str3, str2, 2) << endl;
}