#include <iostream>
#include <climits>
#include <vector>
#include <algorithm> // for sort
using namespace std;

int maxSubArray(vector<int> &arr)
{
    int currSum = 0;
    int maxSum = INT_MIN;

    for (int val : arr)
    {
        currSum += val;
        maxSum = max(currSum, maxSum);
        if (currSum < 0)
            currSum = 0;
        // currSum = (currSum < 0) ? 0 : currSum;
    }

    return maxSum;
}

vector<int> pairSum(vector<int> &nums, int target)
{
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

vector<int> PairSum(vector<int> &nums, int target)
{
    vector<int> ans;
    int n = nums.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        int pairSum = nums[i] + nums[j];
        if (pairSum > target)
            j--;
        else if (pairSum < target)
            i++;
        else
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}

int bruteMajority(vector<int> &nums)
{
    int n = nums.size();
    for (int val : nums)
    {
        int freq = 0;
        for (int el : nums)
        {
            if (val == el)
                freq++;
        }
        if (freq > n / 2)
            return val;
    }
    return -1;
}

int optimizedMajority(vector<int> &nums)
{
    int n = nums.size();

    // sort
    sort(nums.begin(), nums.end());

    // freq count
    int freq = 1, ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
            freq++;
        else
        {
            freq = 1;
            ans = nums[i];
        }
        // condition checking
        if (freq == n / 2)
            return ans;
    }
    return ans;
}

int MajorityElement(vector<int> &nums)
{
    int n = nums.size();
    int freq = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (freq == 0)
            ans = nums[i];
        if (ans == nums[i])
            freq++;
        else
            freq--;
    }
    // result (if any variation given)
    // varaiation => even check for non possible arrays
    int count = 0;
    for (int val : nums)
    {
        if (val == ans)
            count++;
    }
    if (count > n / 2)
        return ans;
    else
        return -1;

    // result (without any variation)
    // return ans;
}

int main()
{
    /* Maximum Subarray Sum */
    // LeetCode = (53)

    // 1) Logic for subarray printing
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};

    for (int st = 0; st < n; st++)
    {
        for (int end = st; end < n; end++)
        {
            for (int i = st; i <= end; i++)
                cout << arr[i];
            cout << " ";
        }
        cout << endl;
    }

    // 2) Brute-force Approach
    n = 7;
    int Arr[n] = {3, -4, 5, 4, -1, 7, -8};

    int maxSum = INT_MIN;

    for (int st = 0; st < n; st++)
    {
        int currSum = 0;
        for (int end = st; end < n; end++)
        {
            currSum += Arr[end];
            maxSum = max(currSum, maxSum);
        }
    }

    cout << "Max sum of array = " << maxSum << endl;

    // 3) Kadane's Algorithm
    // most-optimised approach
    int N;
    // input N
    cout << "\nKadane's Algorithm\n"
         << endl;
    cout << "Enter number of elements needed = ";
    cin >> N;
    vector<int> nums(N);
    // input nums
    for (int i = 0; i < N; i++)
    {
        cout << "Enter " << i << " index element = ";
        cin >> nums[i];
    }
    // output
    cout << "Max Sum of nums = " << maxSubArray(nums) << endl;

    /* Pair Sum */

    // 1) Brute-Force Approach
    cout << "\nPair Sum (brute force)\n";
    vector<int> nums1 = {1, 23, 4, 5, 6};
    int Target = 5;
    vector<int> ans = pairSum(nums1, Target);
    cout << "Sum = ";
    if (ans.empty())
        cout << "[]" << endl;
    else
        cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    // 2) Optimized Approach
    int n1, target;
    // input n1
    cout << "\nPair sum (optimized)"
         << endl;
    cout << "\nEnter the number of elements needed = ";
    cin >> n1;
    vector<int> Nums(n1);
    // input Nums
    // Ex :- {2,3,7,11}
    for (int i = 0; i < n1; i++)
    {
        cout << "Enter " << i << " index element = ";
        cin >> Nums[i];
    }
    // input target
    cout << "Enter the required number = ";
    cin >> target;
    // output
    vector<int> result = PairSum(Nums, target);
    cout << "Indices of Sum = ";
    if (result.empty())
        cout << "[]" << endl;
    else
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    /* Majority Element */
    // Leet code => Problem-(169)

    // 1) Brute Force Approach
    int n2;
    cout << "\nEnter the number of elements needed = ";
    cin >> n2;
    vector<int> mjbrVec(n2);
    // input mjVec
    for (int i = 0; i < n2; i++)
    {
        cout << "Enter " << i << " index element = ";
        cin >> mjbrVec[i];
    }
    // output
    cout << "\nMajority Element in mjVec = " << bruteMajority(mjbrVec) << endl;

    // 2) Optimized Approach
    int n3;
    cout << "\nEnter the number of elements needed = ";
    cin >> n3;
    vector<int> opMjVec(n3);
    // input opMjVec
    for (int i = 0; i < n3; i++)
    {
        cout << "Enter " << i << " index element = ";
        cin >> opMjVec[i];
    }
    // output
    cout << "\nMajority Element in opMjVec = " << optimizedMajority(opMjVec) << endl;

    // 3) Moore's Voting Algorithm
    // (Best Approach)
    int n4;
    cout << "\nEnter the number of elements needed = ";
    cin >> n4;
    vector<int> majVec(n4);
    // input majVec
    for (int i = 0; i < n4; i++)
    {
        cout << "Enter " << i << " index element = ";
        cin >> majVec[i];
    }
    // output
    cout << "\nMajority Element = " << MajorityElement(majVec) << endl;

    return 0;
}