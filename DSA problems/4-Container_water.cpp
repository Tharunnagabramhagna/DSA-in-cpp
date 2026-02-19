#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int waterContainer(vector<int> &height)
{
    int maxWater = 0;
    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            int width = j - i;
            int ht = min(height[i], height[j]);
            int currWater = ht * width; // Area
            maxWater = max(currWater, maxWater);
        }
    }
    return maxWater;
}

int maxArea(vector<int> &height)
{
    int maxWater = 0;
    // st => left ; end => right
    int st = 0, end = height.size() - 1;
    while (st < end)
    {
        int width = end - st;
        int ht = min(height[st], height[end]);
        int currWater = ht * width;
        maxWater = max(currWater, maxWater);
        height[st] < height[end] ? st++ : end--;
    }
    return maxWater;
}

vector<int> productArr(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 1); // result
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                ans[i] *= nums[j];
        }
    }
    return ans;
}

vector<int> prodArr(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 1); // results
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);

    // prefix
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] * nums[i - 1];

    // suffix
    for (int i = n - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] * nums[i + 1];

    // answer
    for (int i = 0; i < n; i++)
        ans[i] = prefix[i] * suffix[i];

    return ans;
}

vector<int> productExpectSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 1);

    // Prefix => ans
    for (int i = 0; i < n; i++)
        ans[i] = ans[i - 1] * nums[i - 1];

    // suffix
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] *= suffix;
        suffix *= nums[i];
    }

    // answer
    return ans;
}

int main()
{
    /* Container with most water */
    // LeetCode Problem 11

    // 1) Brute Force Approach
    // General Points :-
    // i) We need to find all possible containers.
    /* ii) Based on containers we can measure the
    max water storage.
    iii) In order to find those we need to take left
    and right boundary variables.
    iv) Left boundary increases for each iteration.
    v) Right boundary increases from i+1 to n-1.
    vi) i => left boundary; j => right boundary.
    vii) i = 0; j = i+1.
    viii) Width is always equal to j-i.
    ix) Height is the minimum of height[i], height[j].
    x) Area = width * height.*/
    // Time complexity = O(n^2);
    int n;
    // input n
    cout << "Enter the size of vector = ";
    cin >> n;
    vector<int> heightVec(n);
    // input height
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << " index element = ";
        cin >> heightVec[i];
    }
    // output
    cout << "Maximum Water = " << waterContainer(heightVec) << endl;

    // 2) Optimal Approach (2-pointers approach)
    // Time complexity = O(n)
    int n1;
    cout << "\n2-Pointer Approach\n"
         << endl;
    // input n
    cout << "Enter the size of vector = ";
    cin >> n1;
    vector<int> height(n1);
    // input height
    for (int i = 0; i < n1; i++)
    {
        cout << "Enter " << i << " index element = ";
        cin >> height[i];
    }
    // output
    cout << "Maximum Amount of Water = " << maxArea(height) << endl;

    /* Product of Array except itself */
    // LeetCode Problem 238

    // 1) Brute Force Approach
    // Steps:
    /* Taking the product of the whole array and dividing by
    the array element at its index is not possible. So, we can
    calculate the product of the array except the index
    element using the above function logic. */
    // Time complexity = O(n^2)
    int n2;
    cout << "Enter the size of Vector = ";
    cin >> n2;
    vector<int> prodVec(n2);
    // input prodVec
    for (int i = 0; i < n2; i++)
    {
        cout << "Enter " << i << " index element = ";
        cin >> prodVec[i];
    }
    // output
    vector<int> result = productArr(prodVec);
    cout << "Resulted Array : ";
    for (int i = 0; i < n2; i++)
        cout << result[i] << " ";
    cout << endl;

    // 2) Optimal Approach
    // Time complexity = O(n)
    // Space complexity = O(n)
    // Steps:
    /* Taking the elements from left and right
    like prefix and suffix and multiplying them
    in the final answer is the optimal approach. */
    // Left side product => prefix
    // Right side product => suffix
    int n3;
    cout << "\nEnter the size of Vector = ";
    cin >> n3;
    vector<int> prodVec1(n3);
    // input prodVec
    for (int i = 0; i < n3; i++)
    {
        cout << "Enter " << i << " index element = ";
        cin >> prodVec1[i];
    }
    // output
    vector<int> result1 = prodArr(prodVec1);
    cout << "Resulted Array : ";
    for (int i = 0; i < n3; i++)
        cout << result1[i] << " ";
    cout << endl;

    // 3) Best Approach
    // Time complexity = O(n)
    // Space complexity = O(1)
    // Steps:
    /* We are just modifying the above optimized code
    by removing prefix and suffix vectors and replacing
    them with a suffix variable to bring the code to O(1)
    space complexity.*/
    int n4;
    cout << "\nEnter the size of Vector = ";
    cin >> n4;
    vector<int> productVector(n4);
    // input prodVec
    for (int i = 0; i < n4; i++)
    {
        cout << "Enter " << i << " index element = ";
        cin >> productVector[i];
    }
    // output
    vector<int> answer = prodArr(productVector);
    cout << "Resulted Vector : ";
    for (int i = 0; i < n4; i++)
        cout << answer[i] << " ";
    cout << endl;

    return 0;
}