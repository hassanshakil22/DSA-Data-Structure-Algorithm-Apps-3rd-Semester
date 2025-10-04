#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    int ans = fibonacci(n - 1) + fibonacci(n - 2);
    return ans;
}

bool isSorted(vector<int> arr, int n)
{
    if (n == 0 || n == 1)
        return true;

    return arr[n - 1] >= arr[n - 2] && isSorted(arr, n - 1);
}

int binarySearch(vector<int> arr, int target, int start, int end)
{
    int mid = start + (end - start) / 2;
    if (target == arr[mid])
        return mid;
    if (start >= end)
        return -1;

    if (target >  arr[mid])
    {
        return binarySearch(arr, target, mid + 1, end);
    }
    else
    {
        return binarySearch(arr, target, start, mid-1);
    }
}

int main()
{
    vector<int> abc = {1, 2, 6, 9, 15};
    cout << binarySearch(abc, 1, 0, abc.size()-1) << endl;
    cout << isSorted(abc, abc.size()) << endl;
    cout << fibonacci(7) << endl;
    ;
    return 0;
}