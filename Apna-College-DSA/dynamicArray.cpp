#include <iostream>

using namespace std;

class DynamicArray
{
public:
    int *data;
    int cap;
    int size;
    DynamicArray()
    {
        cap = 4;
        data = new int[cap];
        size = 0;
    }

    void append(int val)
    {
        if (cap == size)
        // resizing required
        {
            cap *= 2;
            int *newArr = new int[cap];
            for (int i = 0; i < size; i++)
            {
                newArr[i] = data[i];
            }
            delete[] data;
            data = newArr;
            data[size++] = val;
        }
        else
        {
            data[size++] = val;
        }
    }
    int &operator[](int index)
    {
        if (abs(index) >= size)
        {
            throw out_of_range("Index out of range!");
        }

        if (index < 0)
        {
            return data[index + size];
        }

        return data[index];
    }
    ~DynamicArray()
    {
        delete[] data;
    }
};

int main()
{
    DynamicArray arr;
    arr.append(5);
    arr.append(6);
    arr.append(7);
    arr.append(8);
    arr.append(9);
    arr.append(10);
    arr.append(1);
    arr.append(2);
    arr.append(3);
    arr.append(4);
    cout << arr[-5];
    for (int i = 0; i < arr.size; i++)
    {
        cout << arr[i] << endl;
    }
}