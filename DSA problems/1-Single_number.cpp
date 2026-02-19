#include <iostream>
#include <vector>
using namespace std;

int singleNumberBruteForce(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        int num = nums[i];
        int count = 0;

        // Check the entire array for matches
        for (int j = 0; j < n; j++) {
            if (nums[j] == num)
                count++;
        }

        // If the element appeared only once, it's the answer
        if (count == 1) {
            return num;
        }
    }
    return -1; // Should not reach here based on problem constraints
}

int singleNumber(vector<int> &vec)
{
    int ans = 0;
    for (int val : vec)
        ans ^= val;
    return ans;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}

int main()
{
    /* Single Number */
    // Leet code => problem-(136)

    // 1) Brute Force Approach //
    int n;
    cout << "Enter the number of elements needed = ";
    cin >> n;
    vector<int> nums(n);
    // input
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i << " index element = ";
        cin >> nums[i];
    }
    // Ex:- nums = {1,2,2,1,4}
    cout << "Unique element = " << singleNumber(nums) << endl;

    // 2) Optimal Approach //
    int n1;
    cout << "\nSINGLE NUMBER\n"
         << endl;
    cout << "Enter the number of elements needed = ";
    cin >> n1;
    vector<int> nums1(n1);
    // input
    for (int i = 0; i < n1; i++)
    {
        cout << "Enter " << i << " index element = ";
        cin >> nums1[i];
    }
    // Ex:- nums = {1,2,2,1,4}
    cout << "Unique element = " << singleNumber(nums1) << endl;

    /* Two Sums */
    // Leet code => problem-(1)

    // 1) Brute Force Approach //
    int N, target;
    // input N
    cout << "\nEnter the number of elements needed = ";
    cin >> N;
    vector<int> Nums(N);
    // input Nums
    for (int i = 0; i < N; i++)
    {
        cout << "Enter " << i << " index element = ";
        cin >> Nums[i];
    }
    // input target
    cout << "Enter the required number = ";
    cin >> target;
    // output
    vector<int> result = twoSum(Nums, target);
    cout << "Indices of Sum = ";
    if (result.empty())
        cout << "[]" << endl;
    else
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}