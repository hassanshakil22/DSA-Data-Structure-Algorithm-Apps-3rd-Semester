#include <iostream>

using namespace std;

bool isPalindrome(int arr[5], int size)
{

    // int arr_size = sizeof(arr) / sizeof(arr[0]);
    int arr_size = size;
    for (int i = 0; i < arr_size / 2; i++)
    {
        if (arr[i] != (arr[arr_size - 1 - i]))
        {
            cout << "checking " << arr[i] << " VS " << arr[arr_size - 1 - i] << endl;
            cout << "[LOG] : Not equal" << endl;
            return false;
        }
        else
        {
            cout << "checked " << arr[i] << " VS " << arr[arr_size - i - 1] << "equal " << endl;
        }
    }
    cout << "[LOG] : Array equal " << endl;

    return true;
}

int *findLeaders(int *arr, int arr_size)
{
    int *leaders;
    // int curr_val;
    for (int i = 0; i < arr_size - 1; i++)
    {
        for (int j = i + 1; j < arr_size - 1 - i; j++)
        {
            if (arr[i] < arr[j])
            {
                arr[i] = -1;
            }
        }
    }
    return arr;
}

int main()
{
    // int arr[] = {1, 2, 0, 2, 1, 5};

    // int arr[] = {1, 3, 0, 10, 19};
    // int arr[] = {1, 3, 0, 10, 19};
    // int max = arr[0];
    // int sec_max;

    // for (int i = 1; i < 5; i++)
    // {
    //     if (arr[i] > max)
    //     {
    //         sec_max = max;
    //         max = arr[i];
    //     }
    // }

    // cout << max << endl;
    // cout << sec_max << endl;
    // for (int i = 1; i < 5; i++)
    // {
    //     if (arr[i] > sec_max && arr[i] != max)
    //     {
    //         sec_max = arr[i];
    //     }
    // }

    // string ispal = isPalindrome(arr, sizeof(arr) / sizeof(arr[0])) == 0 ? "False" : "True";
    // cout << ispal;

    int arr[] = {5, 2, 10, 3, 1};
    int *leaders = findLeaders(arr, sizeof(arr) / sizeof(arr[0]));
    cout << leaders << endl;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << leaders[i] << " " ;
    }

    return 0;
}
