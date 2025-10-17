#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>

using namespace std;

void printArray(int arr[], int n)
{
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

// ans 1 ==========================
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
// ans 2 ==========================
int maxNoOfToys(int arr[], int n, int k)
{
    bubbleSort(arr, n);
    printArray(arr, n);
    int ammount = 0;
    int i = 0;
    while ((ammount + arr[i]) < k)
    {
        ammount += arr[i];
        cout << "ammount  at " << arr[i] << " step " << ammount << endl;
        i++;
    }
    return i;
}
// ans 3 ==========================

class Sort
{
    int *arr;
    int n;
    struct swapComp
    {
        int swaps = 0;
        int comprisions = 0;
    };

public:
    Sort(int *arr, int size)
    {
        this->arr = arr;
        n = size;
    }
    void sortArr()
    {
        string technique;
        cout << "Select the technique you want to sort your array from \n(1) insertion \n(2) selection \n(3) bubble " << endl;
        cin >> technique;

        switch (toupper(technique[0]))
        {
        case 'I':
            cout << " Sorting from insertion sort " << endl;
            insertionSort(arr, n);
            cout << "Sorted Array" << endl;
            printArray(arr, n);
            break;
        case 'S':
            cout << " Sorting from Selection sort " << endl;
            selectionSort(arr, n);
            cout << "Sorted Array" << endl;
            printArray(arr, n);
            break;
        case 'B':
            cout << " Sorting from Bubble sort " << endl;
            bubbleSort(arr, n);
            cout << "Sorted Array" << endl;
            printArray(arr, n);
            break;

        default:
            cout << "Please selected a valid technique " << endl;
            break;
        }
    }
    void copyArray(int *orignalarr, int *newArray, int n)
    {
        for (int i = 0; i < n; i++)
        {
            newArray[i] = orignalarr[i];
        }
    }
    void analyzeSorting(int n)
    {
        srand(time(0));
        int minVal = 1, maxVal = 100;
        int arr[n];

        // Generate random array
        for (int i = 0; i < n; i++)
        {
            arr[i] = minVal + rand() % (maxVal - minVal + 1);
        }

        cout << "Randomly generated array: ";
        printArray(arr, n);

        // Arrays for different tests
        int tempArr[n], bestArr[n], worstArr[n];

        copyArray(arr, tempArr, n);
        insertionSort(tempArr, n);
        copyArray(tempArr, bestArr, n);
        for (int i = 0; i < n; i++)
            worstArr[i] = tempArr[n - 1 - i];

        cout << "\n======= ANALYSIS =======" << endl;

        // Insertion Sort
        copyArray(bestArr, tempArr, n);
        swapComp bestIns = insertionSort(tempArr, n);
        copyArray(worstArr, tempArr, n);
        swapComp worstIns = insertionSort(tempArr, n);

        cout << "\nInsertion Sort:" << endl;
        cout << "  Best Case (Sorted)     -> Comparisons: " << bestIns.comprisions << ", Swaps: " << bestIns.swaps << endl;
        cout << "  Worst Case (Reversed)  -> Comparisons: " << worstIns.comprisions << ", Swaps: " << worstIns.swaps << endl;

        // Selection Sort
        copyArray(bestArr, tempArr, n);
        swapComp bestSel = selectionSort(tempArr, n);

        copyArray(worstArr, tempArr, n);
        swapComp worstSel = selectionSort(tempArr, n);

        cout << "\nSelection Sort:" << endl;
        cout << "  Best Case (Sorted)     -> Comparisons: " << bestSel.comprisions << ", Swaps: " << bestSel.swaps << endl;
        cout << "  Worst Case (Reversed)  -> Comparisons: " << worstSel.comprisions << ", Swaps: " << worstSel.swaps << endl;

        // Bubble Sort
        copyArray(bestArr, tempArr, n);
        swapComp bestBub = bubbleSort(tempArr, n);

        copyArray(worstArr, tempArr, n);
        swapComp worstBub = bubbleSort(tempArr, n);

        cout << "\nBubble Sort:" << endl;
        cout << "  Best Case (Sorted)     -> Comparisons: " << bestBub.comprisions << ", Swaps: " << bestBub.swaps << endl;
        cout << "  Worst Case (Reversed)  -> Comparisons: " << worstBub.comprisions << ", Swaps: " << worstBub.swaps << endl;
    }
    swapComp insertionSort(int arr[], int n)
    {
        swapComp s;
        for (int i = 1; i < n; i++)
        {
            int current = arr[i];
            int lastSorted = i - 1;
            while (lastSorted >= 0 && arr[lastSorted] > current)
            {
                arr[lastSorted + 1] = arr[lastSorted];
                s.comprisions++;
                lastSorted--;
            }
            if (lastSorted >= 0)
                s.comprisions++;
            arr[lastSorted + 1] = current;
            s.swaps++;
        }
        return s;
    }

    swapComp selectionSort(int arr[], int n)
    {
        swapComp s;
        // 1 2 4 5 6 10 861 82
        int sortedIndex = -1;
        for (int i = 0; i < n - 1; i++)
        {
            int smallestIdx = i;
            for (int j = i + 1; j < n; j++)
            {
                s.comprisions++;

                if (arr[j] < arr[smallestIdx])
                {
                    smallestIdx = j;
                }
            }
            swap(arr[smallestIdx], arr[sortedIndex + 1]);
            s.swaps++;
            sortedIndex++;
        }
        return s;
    }
    swapComp bubbleSort(int arr[], int n)
    {
        swapComp s;
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
                    s.swaps++;
                }
                s.comprisions++;
            }
        }
        return s;
    }
};

// ans 4 ==========================
void copyArray(int *orignalarr, int *newArray, int n)
{
    for (int i = 0; i < n; i++)
    {
        newArray[i] = orignalarr[i];
    }
}
void pancakeFlip(int arr[], int n, int k)
{
    if (k > n)
        k = n;
    int temparr[k];
    for (int i = k - 1, j = 0; i >= 0; i--, j++)
    {
        temparr[j] = arr[i];
    }
    for (int i = 0; i < k; i++)
    {
        arr[i] = temparr[i];
    }
}

int main()
{
    // ans 1 =========================
    // int arr[] = {4, 2, 1, 7, 9, 2};
    // printArray(arr, 6);
    // bubbleSort(arr, 6);
    // printArray(arr, 6);
    // ans 2 =========================
    // int arr1[] = {1, 12, 5, 111, 200, 1000, 10};
    // cout << maxNoOfToys(arr1, 7, 50);

    // ans 3 =========================
    // int arr[] = {4, 2, 1, 7, 9, 2};
    // Sort s(arr, 6);
    // s.analyzeSorting(8);
    // s.sortArr();

    // ans 4 =========================
    // int arr[] = {3, 2, 4, 1};
    // printArray(arr, 4);
    // pancakeFlip(arr, 4, 4);
    // printArray(arr, 4);
    // pancakeFlip(arr, 4, 2);
    // printArray(arr, 4);
    // pancakeFlip(arr, 4, 4);
    // printArray(arr, 4);
    // pancakeFlip(arr, 4, 3);
    // printArray(arr, 4);

    // ans 5 =========================
    int arr[] = {2,0,2,1,1,0};
    printArray(arr,6);
    bubbleSort(arr,6);
    printArray(arr,6);


    return 0;
}