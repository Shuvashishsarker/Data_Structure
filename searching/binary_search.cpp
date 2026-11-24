// Binary Search in C++ (Requires a sorted array)
// Time Complexity: O(log n) | Space Complexity: O(1) iterative, O(log n) recursive

#include <bits/stdc++.h>
using namespace std;

// 1. Standard Iterative Binary Search (returns index, or -1 if not found)
int binarySearch(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

// 2. Recursive Binary Search
int binarySearchRecursive(vector<int> &arr, int target, int low, int high)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;
    if (arr[mid] < target)
    {
        return binarySearchRecursive(arr, target, mid + 1, high);
    }
    return binarySearchRecursive(arr, target, low, mid - 1);
}

// 3. Find First Occurrence (useful when duplicate elements exist)
int firstOccurrence(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            ans = mid; // record index and keep searching left
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

// 4. Find Last Occurrence
int lastOccurrence(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{

    vector<int> arr = {5, 10, 10, 10, 24, 32, 45, 67, 88};
    int target = 10;
    int n = arr.size();

    cout << "Index (Iterative): " << binarySearch(arr, target) << endl;
    cout << "Index (Recursive): " << binarySearchRecursive(arr, target, 0, n - 1) << endl;
    cout << "First Occurrence:  " << firstOccurrence(arr, target) << endl;
    cout << "Last Occurrence:   " << lastOccurrence(arr, target) << endl;

    return 0;
}