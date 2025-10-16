#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class MyCircularDeque
{
private:
    int *arr;
    int front, rear, size, capacity;

public:
    MyCircularDeque(int k)
    {
        capacity = k;
        arr = new int[k];
        front = -1;
        rear = -1;
        size = 0;
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            front = (front - 1 + capacity) % capacity;
        }
        arr[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
        size++;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % capacity;
        }
        size--;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            rear = (rear - 1 + capacity) % capacity;
        }
        size--;
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }
};
// =========== ans 2 =======================
int findTheWinner(int n, int k)
{
    int winner = 0;
    for (int i = 1; i <= n; i++)
    {
        winner = (winner + k) % i;
    }
    return winner + 1;
}

// =========== ans 3 =======================

class Call
{
public:
    int callID;
    int arrivalTime;
    string customerName;

    Call(int id, int time, string name)
    {
        callID = id;
        arrivalTime = time;
        customerName = name;
    }
};

class CallCenter
{
private:
    queue<Call> callQueue;
    int numCSRs;
    vector<bool> csrAvailable;

public:
    CallCenter(int csrs)
    {
        numCSRs = csrs;
        csrAvailable = vector<bool>(numCSRs, true);
    }
    void addCall(const Call &newCall)
    {
        callQueue.push(newCall);
        cout << "New call added -> ID: " << newCall.callID
             << ", Name: " << newCall.customerName << endl;
    }

    void processCalls()
    {
        while (!callQueue.empty())
        {
            for (int i = 0; i < numCSRs; i++)
            {
                if (csrAvailable[i] && !callQueue.empty())
                {
                    Call current = callQueue.front();
                    callQueue.pop();

                    csrAvailable[i] = false;
                    cout << "CSR " << i + 1 << " answering call "
                         << current.callID << " (" << current.customerName << ")" << endl;
                    cout << "CSR " << i + 1 << " completed call "
                         << current.callID << endl;

                    csrAvailable[i] = true;
                }
            }
        }
        cout << "All calls processed!" << endl;
    }
};

// =========== ans 4 =======================

class ProductOfNumbers
{
    vector<int> nums;

public:
    void addNum(int n)
    {
        nums.push_back(n);
        cout << "Pushed N= " << n << " in Stream " << endl;
        print();
    }
    int getProduct(int n)
    {
        if (n > nums.size())
            n = nums.size();
        int product = 1;
        for (int i = 1; i <= n; i++)
        {
            cout << product << "x" << nums[nums.size() - i] << endl;
            product *= nums[nums.size() - i];
        }
        return product;
    }
    void print()
    {
        cout << "Stream -> ";
        for (int &i : nums)
        {
            cout << i << " ";
        }

        cout << endl;
    }
};

// =========== ans 5 =======================
class DataStream
{
    stack<int> nums;
    int noOftermsToCheck;
    int value;

public:
    DataStream(int val, int k)
    {
        noOftermsToCheck = k;
        value = val;
    }
    bool consec(int n)
    {
        nums.push(n);
        if (nums.size() < noOftermsToCheck)
            return false;

        stack<int> temp = nums;
        for (int i = 0; i < noOftermsToCheck; i++)
        {
            if (nums.top() != n)
                return false;
            nums.pop();
        }
        return true;
    }
};

int main()
{
    // ans 1
    // MyCircularDeque myCircularDeque(3);
    // cout << myCircularDeque.insertLast(1) << endl;
    // cout << myCircularDeque.insertLast(2) << endl;
    // cout << myCircularDeque.insertFront(3) << endl;
    // cout << myCircularDeque.insertFront(4) << endl;
    // cout << myCircularDeque.getRear() << endl;
    // cout << myCircularDeque.isFull() << endl;
    // cout << myCircularDeque.deleteLast() << endl;
    // cout << myCircularDeque.insertFront(4) << endl;
    // cout << myCircularDeque.getFront() << endl;

    // ans 2
    // cout << findTheWinner(5, 2) << endl;
    // return 0;

    // ans 3
    // CallCenter center(3);
    // center.addCall(Call(1, 0, "Ali"));
    // center.addCall(Call(2, 1, "Burhan"));
    // center.addCall(Call(3, 2, "Careem"));
    // center.addCall(Call(4, 3, "Muhammad"));
    // center.addCall(Call(5, 4, "Hassan"));

    // center.processCalls();

    // ans 4
    // ProductOfNumbers p;
    // p.addNum(3);
    // p.addNum(4);
    // p.addNum(5);
    // p.addNum(6);
    // p.addNum(7);
    // p.addNum(8);
    // cout << "product=" << p.getProduct(9);

    // ans 5
    // DataStream d = DataStream(4, 3);
    // cout <<  d.consec(4) << endl;
    // cout <<  d.consec(4) << endl;
    // cout <<  d.consec(4) << endl;
    // cout <<  d.consec(3) << endl;
}