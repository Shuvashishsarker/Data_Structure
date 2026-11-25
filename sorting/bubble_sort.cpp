// Bubble Sort in C++
// Time Complexity: O(n^2) worst/average, O(n) best (optimized) | Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

// 1. Standard Bubble Sort
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 2. Optimized Bubble Sort (stops early if array is already sorted)
void optimizedBubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr1);
    cout << "Standard Bubble Sort:  ";
    printArray(arr1);

    vector<int> arr2 = {10, 20, 30, 40, 50};
    optimizedBubbleSort(arr2);
    cout << "Optimized Bubble Sort: ";
    printArray(arr2);
    return 0;
}