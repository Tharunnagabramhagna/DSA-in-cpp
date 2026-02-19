#include <iostream>
#include <vector>
using namespace std;

double Pow(double x, int n)
{
    // Base Cases
    if (x == 0)
        return 0.0;
    if ((n == 0) || (x == 1) || (x == -1 && n % 2 == 0))
        return 1.0;
    if (x == -1 && n % 2 != 0)
        return -1.0;

    long binForm = n;
    if (n < 0)
    {
        x = 1 / x;
        binForm = -binForm;
    }
    double ans = 1;

    while (binForm > 0) // O(n)
    {
        if (binForm % 2 == 1)
            ans *= x;
        x *= x;
        binForm /= 2;
    }

    return ans;
}

int maxProfit(vector<int> &prices)
{
    int maxProfit = 0, bestBuy = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > bestBuy)
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        bestBuy = min(bestBuy, prices[i]);
    }

    return maxProfit;
}

int main()
{
    // 1) Compute x^n (binary Exponentiation) //
    // Pow(x,n)
    // LeetCode => 50 question
    /* power is found using binary code.
    // Time complexity = O(n)
    // Space complexity = O(1)
    Ex:- 3^5 => 5 --> 101 => (3^4)*(3^1) => 3^5 .*/

    int expo;
    double base;
    cout << "\nPow(x,n)\n"
         << endl;
    // input
    cout << "Enter base and exponent = ";
    cin >> base >> expo;
    // output
    cout << base << " to the power of " << expo << " = " << Pow(base, expo) << endl;

    // 2) Stock Buy and Sell //
    // Leet Code => 121 Problem
    // Time complexity = 0(n)
    // Space complexity = O(1)

    cout << "\nStock-Buy and Sell\n"
         << endl;
    int n;
    // input n
    cout << "Enter the number of elements needed = ";
    cin >> n;
    vector<int> priceVec(n);
    // input priceVec
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << " index element = ";
        cin >> priceVec[i];
    }
    // output
    cout << "\nMaximum Profit of Stock = " << maxProfit(priceVec) << endl;

    return 0;
}