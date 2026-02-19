#include <iostream>
#include <vector>
using namespace std;

// Merge Sort follows divide and conquer rule.

// Time Complexity = O(n log n)
// Space Complexity = O(n)

// Steps of the logic of merge sort :-
// 1) Divide the array
// 2) Merge parts to create a sorted array.

void merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;

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
}

// 1st Step
void mergeSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid);      // left half
        mergeSort(arr, mid + 1, end); // right half
        // 2nd Step
        merge(arr, st, mid, end);
    }
}

// Quick Sort //

// Time Complexity = O(n log n) (or) worst case = O(n*n)
// Space Complexity = O(1)

// Steps of the logic of quick sort :-
// 1) Pick the pivot
// 2) partition
// 3) Call Quick Sort from left and right halfs

int partition(vector<int> &arr, int st, int end)
{
    int idx = st - 1, pivot = arr[end];
    for (int j = st; j < end; j++)
    {
        if (arr[j] <= pivot) // (arr[j] >= pivot) => descending order
        {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}

void quickSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int pivotIdx = partition(arr, st, end);
        quickSort(arr, st, pivotIdx - 1);  // left half
        quickSort(arr, pivotIdx + 1, end); // right half
    }
}

int main()
{
    vector<int> arr = {12, 31, 35, 8, 32, 17};
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Elements of the Sorted Merge Sort Array : ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    vector<int> arr1 = {1, 2, 29, 87, 67, 3};
    quickSort(arr1, 0, arr1.size() - 1);

    cout << "Elements of the Sorted Quick Sort Array : ";
    for (int val : arr1)
        cout << val << " ";
    cout << endl;

    return 0;
}