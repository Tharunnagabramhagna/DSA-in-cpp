#include <iostream>
#include <vector>
using namespace std;

/* Recursive Solution */
int knapSack_01_Rec(vector<vector<int>> &items, int W, int n)
{ // O(2 ^ n)
    // Base Case
    if (n == 0 || W == 0)
        return 0;

    int val = items[n - 1][0];
    int wt = items[n - 1][1];

    // Recursive Cases
    if (wt <= W)
    {
        int include = val + knapSack_01_Rec(items, W - wt, n - 1);
        int exclude = knapSack_01_Rec(items, W, n - 1);
        return max(include, exclude);
    }
    else
        return knapSack_01_Rec(items, W, n - 1);
}

/* Memorization DP */
int knapSack_01_DPMemo(vector<vector<int>> &items, int W, int n, vector<vector<int>> &dp)
{ // O(n * w) in both time and space complexity
    // Base Case
    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W]; // found the answer in the start

    int val = items[n - 1][0];
    int wt = items[n - 1][1];

    // Recursive Cases
    if (wt <= W)
    {
        int include = val + knapSack_01_DPMemo(items, W - wt, n - 1, dp);
        int exclude = knapSack_01_DPMemo(items, W, n - 1, dp);
        return dp[n][W] = max(include, exclude);
    }
    else
        return dp[n][W] = knapSack_01_DPMemo(items, W, n - 1, dp);
}

/* Tabulation DP */


int main()
{
    vector<vector<int>> items = {
        {20, 2},
        {30, 3},
        {50, 4},
        {60, 5},
        {100, 9}}; // {val, wt

    int W = 10;

    cout << "The Minimal Knapsack Weight (Recursion) : ";
    cout << knapSack_01_Rec(items, W, items.size());

    // Initialize whole dp memo with infinities (or) -1
    vector<vector<int>> dp(items.size() + 1, vector<int>(W + 1, -1));

    cout << "\nThe Minimal KnapSack Weight (Dp memo table) : ";
    cout << knapSack_01_DPMemo(items, W, items.size(), dp);

    return 0;
}