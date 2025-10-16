

#include <iostream>
using namespace std;


void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int lastSorted = i - 1;

        while (lastSorted >= 0 && arr[lastSorted] > current)
        {
            arr[lastSorted + 1] = arr[lastSorted];
            lastSorted--;
        }

        arr[lastSorted + 1] = current;
    }
}
void selectionSort(int arr[], int n)
{
    // 1 2 4 5 6 10 861 82
    int sortedIndex = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int smallestIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallestIdx])
            {
                smallestIdx = j;
            }
        }
        swap(arr[smallestIdx], arr[sortedIndex + 1]);
        sortedIndex++;
    }
}

// time complexity is n^2
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            int temp;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 4, 5, 6, 2, 10, 861, 82};
    printArr(arr, 8);

    // bubbleSort(arr, 8);
    // selectionSort(arr, 8);
    insertionSort(arr, 8);
    printArr(arr, 8);

    return 0;
}