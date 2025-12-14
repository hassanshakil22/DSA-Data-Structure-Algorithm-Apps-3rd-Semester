#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
private:
    vector<int> heap;

            // Helper functions to get parent and children indices
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    // Helper method to heapify up (for insertion)
    void heapifyUp(int index)
    {
        while (index > 0 && heap[parent(index)] < heap[index])
        {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    // Helper method to heapify down (for deletion)
    void heapifyDown(int index)
    {
        int size = heap.size();
        while (leftChild(index) < size) // while there is a left child
        {
            int largest = index;
            int left = leftChild(index);
            int right = rightChild(index);

            if (heap[left] > heap[largest]) // first we check left child of the newly added root
                largest = left;
            // check right < size as right can be inexistent also
            if (right < size && heap[right] > heap[largest]) // we check the right child of newly added root
                largest = right;

            if (largest != index)
            {
                swap(heap[index], heap[largest]);
                index = largest;
            }
            else
            {
                break; // heap property satisfied
            }
        }
    }

public:
    // Insert a new value into the heap
    void insert(int value)
    {
        heap.push_back(value);      // Add value at the end
        heapifyUp(heap.size() - 1); // Restore heap property
    }

    // Remove the maximum element (the root)
    int extractMax()
    {
        if (heap.empty())
        {
            throw out_of_range("Heap is empty");
        }
        int maxValue = heap[0];
        heap[0] = heap.back(); // Move last element to root

        heap.pop_back(); // Remove the last element
        heapifyDown(0);  //  Restore heap property
        return maxValue;
    }

    // Get the maximum element without removing it
    int getMax() const
    {
        if (heap.empty())
        {
            throw out_of_range("Heap is empty");
        }
        return heap[0];
    }

    // Check if the heap is empty
    bool isEmpty() const
    {
        return heap.empty();
    }

    void buildHeap(vector<int>& inputArr) {
        heap = inputArr; // Copy data into our internal vector
        int n = heap.size();

        // Start from the last non-leaf node and move up to root
        // Last non-leaf node index is always (n/2) - 1
        for (int i = (n / 2) - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    void heapSort(vector<int> &arr)
    {
        heap.clear(); // CLEAR PREVIOUS STATE
        buildHeap(arr);
        // for (auto &&i : arr)
        //     insert(i);

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            arr[i] = extractMax();
        }
    }
};
class MinHeap
{
private:
    vector<int> heap;
    // Helper functions to get parent and children indices
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    // Helper method to heapify up (for insertion)
    void heapifyUp(int index)
    {
        while (index > 0 && heap[parent(index)] > heap[index])
        {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    // Helper method to heapify down (for deletion)
    void heapifyDown(int index)
    {
        int size = heap.size();
        while (leftChild(index) < size) // while there is a left child
        {
            int smallest = index;
            int left = leftChild(index);
            int right = rightChild(index);

            if (heap[left] < heap[smallest])
                smallest = left;

            if (right < size && heap[right] < heap[smallest])
                smallest = right;

            if (smallest != index)
            {
                swap(heap[index], heap[smallest]);
                index = smallest;
            }
            else
            {
                break; // heap property satisfied
            }
        }
    }

public:
    // Insert a new value into the heap
    void insert(int value)
    {
        heap.push_back(value);      // Add value at the end
        heapifyUp(heap.size() - 1); // Restore heap property
    }

    // Remove the maximum element (the root)
    int extractMin()
    {
        if (heap.empty())
        {
            throw out_of_range("Heap is empty");
        }
        int minValue = heap[0];
        heap[0] = heap.back(); // Move last element to root
        heap.pop_back();       // Remove the last element
        heapifyDown(0);
        return minValue; //  Restore heap property
    }

    // Get the maximum element without removing it
    int getMin() const
    {
        if (heap.empty())
        {
            throw out_of_range("Heap is empty");
        }
        return heap[0];
    }

    // Check if the heap is empty
    bool isEmpty() const
    {
        return heap.empty();
    }
};

// Main function to demonstrate the MaxHeap class

int main()
{
    MaxHeap heap;
    heap.insert(20);
    heap.insert(15);
    heap.insert(30);
    heap.insert(40);
    heap.insert(10);
    cout << "Max element: " << heap.getMax() << endl;
    vector<int> a = {4, 3, 132, 67, 4, 3, 1};
    heap.heapSort(a);
    for (auto &&i : a)
    {
        cout << i << endl;
    }
    return 0;
}
