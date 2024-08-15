// Assignment 02
// Muhammad Azmat
// 23i-2651
// OOP-B

#include <iostream>
#include <string>
using namespace std;

class big
{
private:
    string number_string;

public:
    big() {}

    big(string a)
    {
        number_string = a;
    }

    string getstring()
    {
        return number_string;
    }

    big operator+(big &other)
    {
        string num1 = this->number_string;
        string num2 = other.number_string;
        string result;

        if (num1.length() < num2.length())
        {
            swap(num1, num2);
        }

        int n1 = num1.length();
        int n2 = num2.length();
        string padded_num2 = string(n1 - n2, '0') + num2;

        int carry = 0;
        for (int i = n1 - 1; i >= 0; i--)
        {
            int digit1 = num1[i] - '0';
            int digit2 = padded_num2[i] - '0';
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result = char((sum % 10) + '0') + result;
        }

        if (carry > 0)
        {
            result = char(carry + '0') + result;
        }

        return big(result);
    }

    big operator-(big &other)
    {
        string a = this->number_string;
        string b = other.number_string;
        bool negative_result = false;

        if (a < b)
        {
            swap(a, b);
            negative_result = true;
        }

        int carry = 0;
        string result = "";
        int length1 = a.size();
        int length2 = b.size();

        for (int i = 0; i < length1; ++i)
        {
            int digit1 = a[length1 - 1 - i] - '0';
            int digit2 = i < length2 ? b[length2 - 1 - i] - '0' : 0;
            int diff = digit1 - digit2 - carry;

            if (diff < 0)
            {
                diff += 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            result += diff + '0';
        }

        while (result.size() > 1 && result[result.size() - 1] == '0')
        {
            result = result.substr(0, result.size() - 1);
        }

        if (negative_result)
        {
            result += '-';
        }

        string reversed_result(result.rbegin(), result.rend());
        return big(reversed_result);
    }

    big operator*(big &other)
    {
        string num1 = this->number_string;
        string num2 = other.number_string;
        int length1 = num1.size();
        int length2 = num2.size();
        string result(length1 + length2, '0');

        for (int i = length1 - 1; i >= 0; --i)
        {
            int carry = 0;
            for (int j = length2 - 1; j >= 0; --j)
            {
                int temp = (result[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                result[i + j + 1] = temp % 10 + '0';
                carry = temp / 10;
            }
            result[i] += carry;
        }

        int starting_position = 0;
        while (starting_position < result.size() && result[starting_position] == '0')
        {
            ++starting_position;
        }

        if (starting_position != string::npos)
        {
            return big(result.substr(starting_position));
        }
        return big("0");
    }

    big operator/(big &other)
    {
        if (other.number_string == "0")
        {
            cout << "You are trying to do division by zero. ERROR **" << endl;
            return big("0");
        }

        string dividend = this->number_string;
        string divisor = other.number_string;
        string quotient = "";
        string remainder = "";

        for (char digit : dividend)
        {
            remainder += digit;
            int quotient_digit = 0;
            while (remainder.size() > 1 && remainder[0] == '0')
            {
                remainder = remainder.substr(1);
            }
            while (remainder.size() >= divisor.size() && remainder >= divisor)
            {
                remainder = (this->operator-(other)).getstring();
                ++quotient_digit;
            }
            quotient += to_string(quotient_digit);
        }

        while (quotient.size() > 1 && quotient[0] == '0')
        {
            quotient = quotient.substr(1);
        }

        return big(quotient.empty() ? "0" : quotient);
    }
    big operator^(big &other)
    {
        big result("1");
        big base = *this;
        big exponent = other;

        while (exponent.number_string != "0")
        {
            if ((exponent.number_string[exponent.number_string.size() - 1] - '0') % 2 == 1)
            {
                result = result * base;
            }
            base = base * base;
            exponent = exponent / other;
        }

        return result;
    }
};

int main()
{
    big number1("12345678901234567890");
    big number2("98765432109876543210");
    big power("2");
    big addition_result = number1 + number2;
    cout << "After adding number 1 and 2:" << endl
         << addition_result.getstring() << endl;

    big subtraction_result = number1 - number2;
    cout << "After subtracting number 1 and 2:" << endl
         << subtraction_result.getstring() << endl;

    big multiplication_result = number1 * number2;
    cout << "After multiplying number 1 and 2:" << endl
         << multiplication_result.getstring() << endl;

    big division_result = number1 / number2;
    cout << "After dividing number 1 by number 2:" << endl
         << division_result.getstring() << endl;
    big exp = number1 ^ power;
    cout << "Power: " << exp.getstring() << endl;
    return 0;
}
