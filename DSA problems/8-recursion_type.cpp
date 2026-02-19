#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// to generate all permutations
void backtrack(vector<int> &nums, set<vector<int>> &all_perms, int start)
{
    if (start == nums.size())
    {
        all_perms.insert(nums);
        return;
    }
    for (int i = start; i < nums.size(); ++i)
    {
        swap(nums[start], nums[i]);
        backtrack(nums, all_perms, start + 1);
        swap(nums[start], nums[i]); // Backtrack (swap back)
    }
}

/////// "todo" => learn during recursion /////////
void BFnext(std::vector<int> &nums)
{
    vector<int> original = nums;
    set<vector<int>> all_perms;

    // 1. Generate all unique permutations
    backtrack(nums, all_perms, 0);

    // 2. Find the current permutation in the sorted set
    auto it = all_perms.find(original);

    // 3. Get the next one
    auto next_it = std::next(it);

    if (next_it == all_perms.end())
        // If it's the last one, the next is the first one (circular)
        nums = *all_perms.begin();
    else
        nums = *next_it;
}

void printArr(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    // 1) Find Pivot
    int pivot = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            pivot = i;
            break;
        }
    }
    if (pivot == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    // 2) Swap Pivot with smallest right side el
    for (int i = n - 1; i > pivot; i--)
    {
        if (nums[i] > nums[pivot])
        {
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    // 3) Reversing the rest of the el
    reverse(nums.begin() + pivot + 1, nums.end());
    // (or)
    int i = pivot + 1, j = n - 1;
    while (i <= j)
        swap(nums[i++], nums[j--]);
}

void nxtPermutation(vector<int> &nums)
{
    int n = nums.size();

    // 1) Find Pivot
    int i = n - 2, j;
    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;

    // 2) Swap Pivot with smallest right side el
    if (i >= 0)
    {
        j = n - 1;
        while (nums[j] <= nums[i])
            j--;
        swap(nums[j], nums[i]);
    }

    // 3) Reversing the rest of the el
    reverse(nums.begin() + i + 1, nums.end());
}

int main()
{
    /* Next Permutation */
    // LeetCode Problem 31
    // Medium level Problem

    // 1)  Brute Force Approach

    // logic => Finding all permutaions and printing the next permutation element.

    cout << "__ Brute Force Approach __\n"
         << endl;
    vector<int> arr = {1, 2, 3};
    cout << "Array  = ";
    printArr(arr);
    BFnext(arr); // found by this function
    cout << "Next Permuatation Elements : ";
    printArr(arr);

    // 2) Optimized Approach

    // General Points :-

    // 1) Time complexity = O(n+n+n) = O(3n) = O(n).
    // 2) Space complexity = O(1).
    // 3) Logic is of 3 steps.
    // 4) Step-1 is to find pivot element.
    // 5) Step-2 is to swap pivot with smallest right side element.
    // 6) step-3 is to swap the rest of the unsorted part.

    cout << "\n__ Optimal Approach __\n"
         << endl;
    int n;
    // input size
    cout << "Enter the size of array = ";
    cin >> n;
    // input permArr => (permutation Array)
    vector<int> premArr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element at index " << i << " = ";
        cin >> premArr[i];
    }
    // output
    cout << "Original Array  = ";
    printArr(premArr);
    nxtPermutation(premArr); // found by this function
    cout << "Next Lexicographic ordered Array : ";
    printArr(premArr);

    return 0;
}