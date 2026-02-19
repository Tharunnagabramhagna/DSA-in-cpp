#include <iostream>
#include <vector>
using namespace std;

// Logic for inversion pair => i < j && arr[i] > arr[j]

// 1) Brute Force Approach
int countInvBrute(vector<int> &arr)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
                count++;
        }
    }
    return count;
}

// 2) Optimal Approach (use => Merge Sort)
int merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1, invCount = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++)
        arr[idx + st] = temp[idx];

    return invCount;
}

int mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;

        int leftCount = mergeSort(arr, st, mid);
        int rightCount = mergeSort(arr, mid + 1, end);

        int invCount = merge(arr, st, mid, end);

        return leftCount + rightCount + invCount;
    }
    return 0;
}

int main()
{
    vector<int> arr = {6, 3, 5, 2, 7};
    vector<int> arr1 = {1, 3, 5, 10, 2, 6, 8, 9};
    // Time Complexity = O(n*n)
    // Space Complexity = O(1)
    cout << "Inversion count of arr : " << countInvBrute(arr) << endl;
    // Time Complexity = O(n logn)
    // Space Complexity = O(1)
    cout << "Inversion count of arr1 : " << mergeSort(arr1, 0, arr1.size() - 1) << endl;

    return 0;
}