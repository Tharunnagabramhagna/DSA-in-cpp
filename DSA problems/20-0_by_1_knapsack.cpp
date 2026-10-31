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
{ // O(n * w) for time complexity and space complexity is O(n * w) + O(n)
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
int knapSack_01_DPTable(vector<vector<int>> &items, int W, int n)
{ // Both time and space complexity is O(n * w)
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            int val = items[i - 1][0];
            int wt = items[i - 1][1];
            // case-1
            if (wt <= j)
                dp[i][j] = max(val + dp[i - 1][j - wt], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][W];
}



int main()
{
    vector<vector<int>> items = {
        {20, 2},
        {30, 3},
        {50, 4},
        {60, 5},
        {100, 9}}; // {val, wt

    int W = 10, n = items.size();

    cout << "The Minimal Knapsack Weight (Recursion) : ";
    cout << knapSack_01_Rec(items, W, n) << endl;

    // Initialize whole dp memo with infinities (or) -1
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    cout << "\nThe Minimal KnapSack Weight (Dp memo table) : ";
    cout << knapSack_01_DPMemo(items, W, n, dp) << endl;

    cout << "\nThe Minimal KnapSack Weight (Dp table) : ";
    cout << knapSack_01_DPTable(items, W, n);

    return 0;
}