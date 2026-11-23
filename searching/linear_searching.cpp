// Shuvashish Sarker
// Linear Search in C++
// Time Complexity: O(n) | Space Complexity: O(1) (O(n) for recursive)

#include <iostream>
#include <vector>
using namespace std;

// 1. Basic Linear Search (returns first index, or -1 if not found)
int linearSearch(vector<int> &arr, int target)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

// 2. Find All Occurrences (returns all matching indices)
vector<int> findAll(vector<int> &arr, int target)
{
    vector<int> indices;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            indices.push_back(i);
        }
    }
    return indices;
}

// 3. Recursive Linear Search
int linearSearchRecursive(vector<int> &arr, int target, int i = 0)
{
    if (i == arr.size())
        return -1;
    if (arr[i] == target)
        return i;
    return linearSearchRecursive(arr, target, i + 1);
}

int main()
{
    vector<int> arr = {24, 10, 45, 10, 88, 32, 10, 67};
    int target = 10;

    cout << "First index (Iterative): " << linearSearch(arr, target) << endl;

    vector<int> all = findAll(arr, target);
    cout << "All indices: ";
    for (int idx : all)
    {
        cout << idx << " ";
    }
    cout << endl;

    cout << "First index (Recursive): " << linearSearchRecursive(arr, target) << endl;

    return 0;
}