#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }
        if (isSwapped == false)
        {
            return;
        }
    }
}

int main()
{
    int arr[] = {4, 2, 1, 7, 9, 2};
    cout << "[";
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;

    bubbleSort(arr, 6);

    cout << "[";
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
    return 0;
}