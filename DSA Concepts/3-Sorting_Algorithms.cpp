#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> &arr)
{
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

void bubbleSort(vector<int> &nums)
{
    // Time Complexity = O(n^2)
    // Space Complexity = O(1)
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false; // optimization
        for (int j = 0; j < n - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
            return;
        // !true = false
        // if(false) => doesn't execute
        // (or)
        // !false = true
        // if(true) => executes "return"
    }
}

void BubbleSort(vector<int> &nums)
{
    // Time Complexity = O(n^2)
    // Space Complexity = O(1)
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwap = false; // optimization
        for (int j = 0; j < n - i - 1; j++)
        {
            if (nums[j] < nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
            return;
        // !true = false
        // if(false) => doesn't execute
        // (or)
        // !false = true
        // if(true) => executes "return"
    }
}

void selectionSort(vector<int> &arr)
{
    // Time Complexity = O(n^2)
    // Space Complexity = O(1)
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        // unsorted part starting idx
        int smallIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallIdx])
                smallIdx = j;
        }
        swap(arr[i], arr[smallIdx]);
    }
}

void SelectionSort(vector<int> &arr)
{
    // Time Complexity = O(n^2)
    // Space Complexity = O(1)
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        // unsorted part starting idx
        int largeIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[largeIdx])
                largeIdx = j;
        }
        swap(arr[i], arr[largeIdx]);
    }
}

void insertionSort(vector<int> &arr)
{
    // Time Complexity = O(n^2)
    // Space Complexity = O(1)
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1; // prev => previous el
        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr; // correct position
    }
}

void InsertionSort(vector<int> &arr)
{
    // Time Complexity = O(n^2)
    // Space Complexity = O(1)
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1; // prev => previous el
        while (prev >= 0 && arr[prev] < curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr; // correct position
    }
}

int main()
{
    /* Sorting Algorithms */

    // 1) Bubble Sort
    cout << "__ Bubble Sort __\n";
    int n;
    // input size
    cout << "Enter the Size of the Array = ";
    cin >> n;
    // input bubbleVec
    vector<int> bubbleVec(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the elements at index " << i << " = ";
        cin >> bubbleVec[i];
    }
    // output
    cout << "\nArray Before Sorting : \n";
    printArr(bubbleVec);

    cout << "\nArray After Sorting(ascending order) : \n";
    bubbleSort(bubbleVec); // sorted by function
    printArr(bubbleVec);

    cout << "\nArray After Sorting(descending order) : \n";
    BubbleSort(bubbleVec); // sorted by function
    printArr(bubbleVec);

    // 2) Selection Sort
    cout << "\n__ Selection Sort __\n";
    int N;
    // input size
    cout << "Enter the Size of the Array = ";
    cin >> N;
    // input secArr
    vector<int> secArr(N);
    for (int i = 0; i < N; i++)
    {
        cout << "Enter the elements at index " << i << " = ";
        cin >> secArr[i];
    }
    // output
    cout << "\nArray Before Sorting : \n";
    printArr(secArr);

    cout << "\nArray After Sorting(ascending order) : \n";
    selectionSort(secArr); // sorted by function
    printArr(secArr);

    cout << "\nArray After Sorting(descending order) : \n";
    SelectionSort(secArr); // sorted by function
    printArr(secArr);

    // 3) Insertion Sort
    cout << "\n__ Insertion Sort __\n";
    int n1;
    // input size
    cout << "Enter the Size of the Array = ";
    cin >> n1;
    // input secArr
    vector<int> intArr(n1);
    for (int i = 0; i < n1; i++)
    {
        cout << "Enter the elements at index " << i << " = ";
        cin >> intArr[i];
    }
    // output
    cout << "\nArray After Sorting(ascending order) : \n";
    insertionSort(intArr);
    printArr(intArr);

    cout << "\nArray After Sorting(descending order) : \n";
    InsertionSort(intArr);
    printArr(intArr);

    return 0;
}