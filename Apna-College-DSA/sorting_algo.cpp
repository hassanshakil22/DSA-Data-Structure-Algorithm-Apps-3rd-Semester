// Quick

// | Case        | Time Complexity                                 | Reason                             |
// | ----------- | ----------------------------------------------- | ---------------------------------- |
// | **Best**    | **O(n log n)**                                  | Balanced partitions.               |
// | **Average** | **O(n log n)**                                  | Random pivot works well.           |
// | **Worst**   | **O(n²)**                                       | Already sorted + bad pivot choice. |
// | **Space**   | O(log n) (best) / O(n) (worst) due to recursion |                                    |
// | **Stable**  | ❌                                               |                                    |

// MERGE

// | Case        | Time Complexity |
// | ----------- | --------------- |
// | **Best**    | **O(n log n)**  |
// | **Average** | **O(n log n)**  |
// | **Worst**   | **O(n log n)**  |
// | **Space**   | O(n)            |
// | **Stable**  | ✔               |





#include <iostream>
using namespace std;

// 4,1,5,0,7,9
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
    int sortedIndex = 0;
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
        swap(arr[smallestIdx], arr[sortedIndex]);
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
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int partition(int arr[], int st, int end)
{
    int pivot = arr[end];
    int idx = st - 1;

    for (int j = st; j < end; j++)
    {
        if (arr[j] <= pivot) // if element less than = to pivot then we replace arr[j] to idxth pos element as that keeps track of left side elemetns
        {
            swap(arr[++idx], arr[j]);
        }
    }
    swap(arr[++idx], arr[end]);
    return idx;
}

void quickSort(int arr[], int st, int end)
{
    if (st < end)
    {
        int pivotIdx = partition(arr, st, end);
        quickSort(arr, st, pivotIdx - 1);  // left half
        quickSort(arr, pivotIdx + 1, end); // right half
    }
}

void merge(int arr[], int st, int mid, int end)
{
    int i = st, j = mid + 1;
    int tempIdx = 0;
    int arrSize = (end - st + 1); // if st=3 and end = 7 so array size is 7-3 =4+1 => 5
    int temp[arrSize];
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[tempIdx++] = arr[i++];
        }
        else
        {
            temp[tempIdx++] = arr[j++];
        }
    }
    while (i <= mid)
        temp[tempIdx++] = arr[i++];
    while (j <= end)
        temp[tempIdx++] = arr[j++];

    for (int i = 0; i < arrSize; i++)
    {
        arr[i + st] = temp[i];
    }
}

void mergeSort(int arr[], int st, int end)
{
    if (st < end)
    {

        int mid = st + (end - st) / 2;

        mergeSort(arr, st, mid);      // left
        mergeSort(arr, mid + 1, end); // right

        merge(arr, st, mid, end);
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
    // insertionSort(arr, 8);
    // quickSort(arr, 0, 7);
    mergeSort(arr, 0, 7);

    printArr(arr, 8);

    return 0;
}