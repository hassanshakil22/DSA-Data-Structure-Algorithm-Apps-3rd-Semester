
#include <iostream>

using namespace std;

// question : 1
// int main()
// {
//     int rows, cols;
//     cout << "Enter the rows" << endl;
//     cin >> rows;
//     cout << "Enter the cols" << endl;
//     cin >> cols;

//     int **arr2d = new int *[rows];
//     for (int i = 0; i < rows; i++)
//     {
//         arr2d[i] = new int[cols];
//     }
//     for (int row = 0; row < rows; row++)
//     {
//         for (int col = 0; col < cols; col++)
//         {
//             cout << "Enter value for row : " << row + 1 << " Col : " << col + 1 << "--> ";
//             cin >> arr2d[row][col]; // or by pointer arithmetic  *(*(arr2d + row) + col)
//         }
//     }

//     // int arr2d[3][3] = {
//     //     {2, 3, 5},
//     //     {4, 7, 9},
//     //     {0, 1, 8},
//     // };
//     // int arrflat[9];
//     int *arrflat = new int[rows * cols];

//     int k = 0;
//     for (int row = 0; row < 3; row++)
//     { // 3
//         for (int col = 0; col < 3; col++)
//         {
//             arrflat[k] = arr2d[col][row];
//             k++;
//         }
//     }

//     cout << "flattedned Array : [";

//     for (int i = 0; i < rows * cols; i++)
//     {

//         cout << arrflat[i] << " ";
//     }

//     cout << "]" << endl;
//     cout << "deleting memory" << endl;
//     for (int row = 0; row < rows; row++)
//     {
//         delete[] arr2d[row];
//     }
//     delete[] arr2d;
//     delete[] arrflat;
//     return 0;
// }

// ---------------------------------------


// // question 2
// int main()
// {

//     int no_of_students, no_of_subs;
//     cout << "Enter the number of students " << endl;
//     cin >> no_of_students;
//     cout << "Enter the number of subjects" << endl;
//     cin >> no_of_subs;

//     string *students = new string[no_of_students];
//     string *subjects = new string[no_of_subs];
//     int *studentGpa = new int[no_of_students];

//     for (int i = 0; i < no_of_subs; i++)
//     {
//         cout << "Enter " << i + 1 << " subject : ";
//         cin >> subjects[i];
//     }

//     for (int i = 0; i < no_of_students; i++)
//     {
//         cout << "Enter " << i + 1 << " student : ";
//         cin >> students[i];
//     }

//     int **arr2d = new int *[no_of_students];
//     for (int i = 0; i < no_of_students; i++)
//     {
//         arr2d[i] = new int[no_of_subs];
//     }
//     for (int row = 0; row < no_of_students; row++)
//     {
//         for (int col = 0; col < no_of_subs; col++)
//         {
//             cout << "Enter marks for Student: " << students[row] << "  --  subject: " << subjects[col] << "--> ";
//             cin >> arr2d[row][col]; // or by pointer arithmetic  *(*(arr2d + row) + col)
//         }
//     }

//     for (int i = 0; i < no_of_students; i++)
//     {
//         int gpa = 0;
//         for (int j = 0; j < no_of_subs; j++)
//         {
//             gpa += arr2d[i][j];
//             studentGpa[i] = gpa/no_of_subs;
//         }

//     }
//     cout << "For Subjects " ;
//        for (int j = 0; j < no_of_subs; j++)
//         {
//             cout << subjects[j] << " " ;
//         }
//             cout <<endl ;

//     for (int i = 0; i < no_of_students; i++)
//     {
//         cout << "Student Name : " << students[i] << "has gpa of" << studentGpa[i] << endl;
//     }

//     cout << "deleting memory" << endl;
//     for (int row = 0; row < no_of_students; row++)
//     {
//         delete[] arr2d[row];
//     }
//     delete[] arr2d;
//     return 0;
// }

// ---------------------------------------


// question : 3

// #include <vector>
// #include <algorithm>

// using namespace std;

// class MedianFinder {
// private:
//     vector<int> nums;
// public:
//     MedianFinder() {
//     }

//     void addNum(int num) {
//         // Find the position to insert using lower_bound
//         auto it = lower_bound(nums.begin(), nums.end(), num);
//         nums.insert(it, num);
//     }

//     double findMedian() {
//         int n = nums.size();
//         if (n % 2 == 1) {
//             //if odd
//             return nums[n/2];
//         } else {
//             //if even
//             return (nums[n/2 - 1] + nums[n/2]) / 2.0;
//         }
//     }
// };
// int main(){
//     MedianFinder mdf ;
//     mdf.addNum(4);
//     mdf.addNum(1);
//     mdf.addNum(2);
//     mdf.addNum(3);
//     cout <<  mdf.findMedian();
//     return 0;
// }


// ---------------------------------------

// // quesiton 4

// int binarySearch(int *arr, int size, int target)
// {
//     int low, high;
//     low = 0;        //{-1, 0, 3, 5, 9, 12} target = 2
//     high = size - 1; // h3 //l1 //h2
//     int mid ;
//     while (high >= low)
//     {
//             mid = low + (high-low) / 2;
//         if (arr[mid] == target)
//         {
//             return mid;
//         }
//         if (target > arr[mid])
//         {
//             low = mid + 1;

//         }
//         if (target < arr[mid])
//         {
//             high = mid-1;

//         }
//     }
//     return -1;
// }

// int main()
// {
//     int arr[] = {-1, 0, 3, 5, 9, 12};

//     cout << binarySearch(arr,sizeof(arr)/sizeof(arr[0]) , 2);
//     return 0;
// }

// ---------------------------------------



// // quesiton 5
// bool matrixbinarySearch(int matrix[][4], int rows, int cols, int target)
// {
//     int top = 0, bottom = rows - 1;
//     int row = -1;
//     while (top <= bottom)
//     {
//         int mid = top + (bottom - top) / 2;

//         if (matrix[mid][0] <= target && target <= matrix[mid][cols - 1]) // first case where i directly find the row
//         {
//             row = mid;
//             break;
//         }
//         else if (target > matrix[mid][cols - 1]) // if
//         {
//             top = mid + 1;
//         }
//         else
//         {
//             bottom = mid - 1;
//         }
//     }

//     if (row == -1){
//         cout << "Row not found"    << endl  ; 
//         return false; // target not in any row
//     }
//     else 
//         cout << "Row  found" << row   << endl  ; 
//     // for each array iteration
//     int low, high;
//     low = 0;        //{-1, 0, 3, 5, 9, 12} target = 2
//     high = cols - 1; 
//     while (high >= low)
//     {
//         int mid = low + (high-low) / 2;
//         if (matrix[row][mid] == target)
//         {
//             return true;
//         }
//         if (target > matrix[row][mid])
//         {
//             low = mid + 1;
//         }
//         if (target < matrix[row][mid])
//         {
//             high = mid - 1;
//         }
//     }
//     return false;
// }

// int main()
// {
//     int matrix[][4] = {{1, 3, 5, 6}, {10, 11, 16, 20}, {23, 30, 34, 60}};
//     cout <<   "element found  --> "<< matrixbinarySearch(matrix , 3,4,60);
//     return 0;
// }