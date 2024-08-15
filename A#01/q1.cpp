// Assignment 01
// Muhammad Azmat
// OOP-B

#include <iostream>
#include <string>
using namespace std;

// convert into digit
char convert_in_digit(char c)
{
    char result = ' ';
    if (c == 'B' || c == 'F' || c == 'P' || c == 'V' || c == 'b' || c == 'f' || c == 'p' || c == 'v')
        result = '1';
    else if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z' || c == 'c' || c == 'g' || c == 'j' || c == 'k' || c == 'q' || c == 's' || c == 'x' || c == 'z')
        result = '2';
    else if (c == 'D' || c == 'T' || c == 'd' || c == 't')
        result = '3';
    else if (c == 'L' || c == 'l')
        result = '5';
    else if (c == 'M' || c == 'N' || c == 'm' || c == 'n')
        result = '4';
    else if (c == 'R' || c == 'r')
        result = '6';
    // for rest of all "aeiouhwy"
    else
        result = '0';

    return result;
}

// helper
string make_code(const string &name, int index, char a, string code)
{
    if (index == name.length())
        return code;

    char digit = convert_in_digit(name[index]);

    if (digit != a)
    {
        if (digit != '0')
            code += digit;
        return make_code(name, index + 1, digit, code);
    }
    else
    {
        return make_code(name, index + 1, a, code);
    }
}

string removedupliction(string str, int index)
{

    if (str.length() == 0 || str.length() == 1)
        return str;

    if (index == str.length() - 1)
        return string(1, str[index]);

    if (str[index] == str[index + 1])
        return removedupliction(str, index + 1);

    string nextCharacters = removedupliction(str, index + 1);
    return str[index] + nextCharacters;
}

//  function to remove zeros
string removezero(const string &str, int index)
{

    if (index >= str.length())
    {
        return "";
    }

    if (str[index] == '0')
    {
        return removezero(str, index + 1);
    }

    return str[index] + removezero(str, index + 1);
}

string appendzero(string &code, int stop)
{
    if (code.length() >= stop)
        return code;
    else
    {
        code += '0';
        return appendzero(code, stop);
    }
}

string soundex(const string &name)
{
    string code;
    code += name[0];
    code = make_code(name, 1, convert_in_digit(name[0]), code);
    code = removedupliction(code, 0);
    code = removezero(code, 0);
    code = appendzero(code, 4);
    return code;
}

int main()
{
    string name;
    cout << "Enter a name: ";
    cin >> name;

    // capital first letter
    if (name[0] >= 'a' && name[0] <= 'z')
        name[0] = name[0] - ('a' - 'A');
    // make  new string in which we store answe

    string soundcode = soundex(name);

    cout << "Soundex code: " << soundcode << endl;

    return 0;
}
