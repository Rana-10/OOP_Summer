// Assignment 02
// Muhammad Azmat
// 23i-2651
// OOP-B

#include <iostream>
using namespace std;

int stock_profit(int *prices, int s);

int main()
{
    int size = 6;
    int stock_prices[size]{3, 6, 0, 0, 0, 0};

    int answer = stock_profit(stock_prices, size - 1);
    cout << "The maximum profit is: " << answer << endl;

    return 0;
}

int stock_profit(int *prices, int s)
{

    int highest_num = prices[s];
    int smallest_num = prices[0];

    if (s < 0)
    {
        return 0;
    }

    if (prices[s] > highest_num)
    {
        highest_num = prices[s];
    }

    if (prices[s] < smallest_num)
    {
        smallest_num = prices[s];
    }

    int current_profit = stock_profit(prices, --s);
    int maximum_profit = max(current_profit, highest_num - smallest_num);

    return maximum_profit;
}
