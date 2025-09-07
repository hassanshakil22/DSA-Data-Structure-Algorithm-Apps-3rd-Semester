
#include <iostream>

using namespace std;

int main()
{
    int rows, cols;
    cout << "Enter the rows" << endl;
    cin >> rows;
    cout << "Enter the cols" << endl;
    cin >> cols;


    int **arr2d = new int *[rows];
    for (int  i = 0; i < rows; i++)
    {
        // int* arr[i] = new int[cols];
    }
    

        int arr2d[3][3] = {
            {2, 3, 5},
            {4, 7, 9},
            {0, 1, 8},
        };
    // int arrflat[9];
    int *arrflat = new int[sizeof(arr2d) / sizeof(arr2d[0][0])];

    int k = 0;
    for (int row = 0; row < 3; row++)
    { // 3
        for (int col = 0; col < 3; col++)
        {
            arrflat[k] = arr2d[col][row];
            k++;
        }
    }

    cout << "flattedned Array : [";

    for (int i = 0; i < sizeof(arr2d) / sizeof(arr2d[0][0]); i++)
    {

        cout << arrflat[i] << " ";
    }

    cout << "]" << endl;
    return 0;
}