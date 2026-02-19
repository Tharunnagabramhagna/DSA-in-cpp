#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target)
{
    int st = 0, end = nums.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[st] <= nums[mid])
        {
            // Left Sorted
            if (nums[st] <= target && target <= nums[mid])
                end = mid - 1; // found case
            else
                st = mid + 1; // not found case
        }
        else
        {
            // Right Sorted
            if (nums[mid] <= target && target <= nums[end])
                st = mid + 1; // found case
            else
                end = mid - 1; // not found case
        }
    }
    return -1;
}

int BruteForcePeakArr(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return i;
    }
    return -1;
}

int peakElement(vector<int> &nums)
{
    int st = 1, end = nums.size() - 2;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
            return mid;
        if (nums[mid - 1] < nums[mid]) // search in right half
            st = mid + 1;
        else // search in left half
            end = mid - 1;
    }
    return -1;
}

int peakIndexInMountainArray(vector<int> &arr)
{
    int st = 0, end = arr.size() - 1;

    while (st < end)
    {
        int mid = st + (end - st) / 2;

        if (arr[mid] < arr[mid + 1])
            // You are on the left slope, peak must be to the right
            st = mid + 1;
        else
            // You are on the right slope or at the peak
            end = mid;
    }
    // At the end, st == end, pointing to the peak
    return st; // answer
}

int bruteForceSE(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] != arr[i + 1])
            return arr[i];
    }
    return -1;
}

int singleElement(vector<int> &nums)
{
    int n = nums.size();
    int st = 0, end = n - 1;
    // Edge Case
    if (n == 1)
        return nums[0];
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        // Edge Cases
        if (mid == 0 && nums[0] != nums[1])
            return nums[mid];
        if (mid == n - 1 && nums[n - 1] != nums[n - 2])
            return nums[mid];
        // Final answer
        if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
            return nums[mid];
        // Even Case
        if (mid % 2 == 0)
        {
            if (nums[mid - 1] == nums[mid])
                end = mid - 1; // left searching
            else
                st = mid + 1; // right searching
        }
        else
        { // Odd Case
            if (nums[mid - 1] == nums[mid])
                st = mid + 1; // right searching
            else
                end = mid - 1; // left searching
        }
    }
    return -1;
}

bool isValidate(vector<int> &arr, int days, int maxCapacity)
{
    int perDay = 1, loadPerDay = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > maxCapacity)
            return -1;
        if ((loadPerDay + arr[i]) <= maxCapacity)
            loadPerDay += arr[i];
        else
        {
            perDay++;
            loadPerDay = arr[i];
        }
    }
    return perDay <= days;
    // valid => true ; not valid => false
}

int shipWithinDays(vector<int> &weights, int days)
{
    int n = weights.size();
    int st = 0, end = 0, ans = -1;
    for (int w : weights)
    {
        st = max(st, w); // max package
        end += w;        // sum of packages
    }
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isValidate(weights, days, mid))
        { // Left half search
            ans = mid;
            end = mid - 1;
        }
        else // Right half search
            st = mid + 1;
    }
    return ans;
}

bool canAchieve(vector<int> &arr, int k, int targetGap)
{
    int candy = 1, maxTaste = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if ((arr[i] - maxTaste) >= targetGap)
        {
            candy++;
            maxTaste = arr[i];
        }
        if (candy == k)
            return true;
    }
    return false;
}

int maximumTasteiness(vector<int> &price, int k)
{
    sort(price.begin(), price.end());
    int st = 1, ans = 0, end = (price[price.size() - 1] - price[0]) / (k - 1);
    while (st <= end) // end => minimized search space
    {
        int mid = st + (end - st) / 2;
        if (canAchieve(price, k, mid))
        { // right search
            ans = mid;
            st = mid + 1;
        }
        else // left search
            end = mid - 1;
    }
    return ans;
}

bool canRun(int n, vector<int> &batteries, long long targetTime)
{
    long long allPowerNeeded = (long long)n * targetTime;
    long long powerPool = 0;
    // cap => capacity of each battery
    for (int cap : batteries)
    {
        powerPool += min((long long)cap, targetTime);
        if (powerPool >= allPowerNeeded)
            return true;
    }
    return false;
}

long long maxRunTime(int n, vector<int> &batteries)
{
    // n => No. of computers
    long long sum = 0;
    for (int val : batteries)
        sum += val;
    long long st = 0, end = sum / n, ans = 0;
    while (st <= end)
    {
        long long mid = st + (end - st) / 2;
        if (canRun(n, batteries, mid))
        {
            ans = mid;
            st = mid + 1; // search in right half
        }
        else // search in left half
            end = mid - 1;
    }
    return ans; // Final Result (default => 0)
}

int main()
{
    /* Search in Rotated Sorted Array */
    // LeetCode Problem 33

    /* General Points:
     1) This problem is based on binary search
     algorithm.
     2) Normal Binary Search fails to solve this,
     so we need a more optimal way of solving.
     3) Rotated Sorted Array has at least one side of
     array as sorted.
     4) The basic logic is to apply a binary search
     to the sorted half of the array to check for the
     target. If the target is not found there, you proceed
     to search the unsorted half.
     5) Note: This code only works for a rotated sorted array.
    */

    // Code :-
    int n, tar;
    // input size
    cout << "Enter the size of the rotated sorted array = ";
    cin >> n;
    // input arr
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element at index " << i << " = ";
        cin >> arr[i];
    }
    // input target
    cout << "Enter the required number = ";
    cin >> tar;
    // output
    int ans = search(arr, tar);
    if (ans != -1)
        cout << "Target is found at index " << ans << "." << endl;
    else
        cout << "Target not found.\n";

    /* Peak Index in a Mountain Array */
    // LeetCode Problem 852

    // 1) Brute Force Approach
    // We used linear search algorithm in brute force.

    vector<int> nums = {0, 3, 8, 9, 5, 2}; // <= mountain array (e.g.)
    // output
    cout << "Peak element found at index " << BruteForcePeakArr(nums) << ".\n";

    // 2) Optimal Approach
    int n1;
    // input size
    cout << "\nPeak Index in a Mountain Array\n"
         << endl;
    cout << "Enter the size of mountain array = ";
    cin >> n1;
    // input vec
    vector<int> vec(n1);
    for (int i = 0; i < n1; i++)
    {
        cout << "Enter element at index " << i << " = ";
        cin >> vec[i];
    }
    // output
    int result = peakElement(vec);
    if (result != -1)
        cout << "Peak element found at index " << result << ".\n";
    else
        cout << "Peak element not found.\n";

    /* Single Element in a Sorted Array */
    // LeetCode Problem 540

    cout << "\nSingle Element in a Sorted Array\n"
         << endl;

    // 1) Brute Force Approach

    // General Points :-
    // This is based on Linear search algorithm.
    // Time Complexity = O(n)
    // Space Complexity = O(1)

    cout << "\nBrute Force Approach\n"
         << endl;
    vector<int> Vec = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "Single Element = " << bruteForceSE(Vec) << endl;

    // 2) Optimized Approach

    // General Points :-
    /* 1) Check if the middle element is the answer.
       2) If yes, then return the answer; otherwise, proceed to the next cases.
       3) Check the left and right sides of the middle element.
       4)If the left and right halves have an even number of elements,
       there are two conditions to check for the element.
       5) If the left and right halves have an odd number of elements,
       there are also two conditions to check for the element.
       6) Even case:
          - Left → if arr[mid - 1] == arr[mid], then end = mid - 1.
          - Right → if arr[mid] == arr[mid + 1], then st = mid + 1.
       7) Odd case:
          - Left → if arr[mid - 1] == arr[mid], then st = mid + 1.
          - Right → if arr[mid] == arr[mid + 1], then end = mid - 1.
       8) After this, check edge cases such as when mid == st or mid == end,
       and also the case where only one element exists in the array.
       9) The code for the program is given below.  */

    int n2;
    cout << "\nThe Optimized Approach\n"
         << endl;
    // input size
    cout << "Enter the size of the array = ";
    cin >> n2;
    // input singleArr
    vector<int> singleArr(n2);
    for (int i = 0; i < n2; i++)
    {
        cout << "Enter element at index " << i << " = ";
        cin >> singleArr[i];
    }
    // output
    int answer = singleElement(singleArr);
    if (answer != -1)
        cout << "Unique Element in Sorted Array = " << answer << endl;
    else
        cout << "Unique Element doesn't exist.\n";

    /* Capacity To Ship Packages Within D Days */
    // LeetCode Problem 1011

    // General Points :-

    // 1) This problem is also based on Book Allocation problem.
    // 2) This problem is also based on binary search algorithm.
    // 3) The logic is to start from max package to sum of packages.
    // 4) Later verifying that is mid valid or not.
    // 5) If mid is valid search in left half or else in right half.
    // 6) left half => end = mid - 1 , right half => st = mid + 1.
    // 7) Finally return the answer.

    cout << "\nCapacity To Ship Packages Within D Days\n"
         << endl;
    int n3, days;
    // input size
    cout << "Enter the size of the array = ";
    cin >> n3;
    // input weights
    vector<int> weights(n3);
    for (int i = 0; i < n3; i++)
    {
        cout << "Enter the element at index " << i << " = ";
        cin >> weights[i];
    }
    // input days
    cout << "Enter the number of days required to ship = ";
    cin >> days;
    // output
    cout << "Minimum Capacity of Ship = " << shipWithinDays(weights, days) << endl;

    /* Maximum Tasteiness of Candy Basket */
    // LeetCode Problem 2517

    // General Points :-

    // 1) This problem is also based on Aggressive cows problem.
    // 2) This problem is also based on binary search algorithm.
    // 3) The logic is to start from 1 to (maxVal - minVal) / (k-1).
    // 4) Later verifying that is mid valid or not.
    // 5) If mid is valid search in right half or else in left half.
    // 6) left half => end = mid - 1 , right half => st = mid + 1.
    // 7) Finally return the answer.

    cout << "\nMaximum Tasteiness of Candy Basket\n"
         << endl;
    int n4, k; // k => distinct candies in store
    // Input size
    cout << "Enter the size of the array = ";
    cin >> n4;
    // Input price
    vector<int> price(n);
    for (int i = 0; i < n4; i++)
    {
        cout << "Enter the elements at index " << i << " = ";
        cin >> price[i];
    }
    // Input k
    cout << "Enter the required number of candies = ";
    cin >> k;
    // output
    cout << "Maximium Tasteiness of candies = ";

    /* Maximum Running Time of N Computers */
    // LeetCode Problem 2141
    // Hard Level Problem

    // General Points :-

    // 1) This problem is mixture of both Aggressive cows and book allocation problem.
    // 2) This problem is also based on binary search algorithm.
    // 3) canRun function is purely based on Aggressive cows problem.
    // 4) main logic function is based on both the problems.
    // 5) The logic is to start from 0 to sum of array / n.
    // 6) Later verifying that is mid valid or not.
    // 7) If mid is valid search in right half or else in left half.
    // 8) right half => st = mid + 1 ,left half => end = mid - 1.
    // 9) Finally return the answer.

    long long size, n;
    // Input size
    cout << "Enter the size of array = ";
    cin >> size;
    // Input batteries
    vector<int> batteries(size); // E.g. [1,1,1,1] n = 2, [3,3,3] n = 2
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element at index " << i << " = ";
        cin >> batteries[i];
    }
    // Input n
    cout << "Enter the number of Computers = ";
    cin >> n;
    // Output
    cout << "Max Run Time of Batteries = " << maxRunTime(n, batteries) << endl;

    // Test Cases :-

    // 1) n = 3 ,[10,10,5,3] => o/p = 8
    // 2) n = 4 ,[8, 1, 4, 8] => o/p = 1
    // 3) n = 2 , [31,87,85,44,47,25] => o/p = 159
    // 4) n = 12 , [11,89,16,32,70,67,35,35,31,24,41,29,6,53,78,83] => o/p = 43

    return 0;
}