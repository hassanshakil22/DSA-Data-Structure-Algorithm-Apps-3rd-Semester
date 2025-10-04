#include <iostream>

using namespace std;

class Dequeue
{
public:
    int *arr;
    int capacity;
    int size;
    int front;
    int rear;

    Dequeue(int cap) : capacity(cap)
    {
        arr = new int[capacity];
        size = 0;
        front = -1;
        rear = 0;
    }
    bool isfull()
    {
        return size == capacity;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void insertFront(int x)
    {
        if (isfull())
        {
            cout << "Dequeue is full ";
            return;
        }
        if (isEmpty())
            front = rear = 0;
        else if (front == 0)
            front = capacity - 1;
        else
            front--;
        arr[front] = x;
        size++;
    }
    void insertRear(int x)
    {
        if (isfull())
        {
            cout << "Dequeue is full ";
            return;
        }
        if (isEmpty())
            front = rear = 0;
        else if (rear == capacity - 1)
            rear = 0;
        else
            rear++;
        arr[rear] = x;
        size++;
    }

    void remove_front()
    {
        if (isEmpty())
        {
            cout << "Already Empty" << endl;
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = 0;
        }
        else if (front == capacity - 1)
            front = 0;
        else
            front++;
        size--;
    }

    void remove_rear()
    {
        if (isEmpty())
        {
            cout << "Already Empty" << endl;
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = 0;
        }
        else if (rear == 0)
            rear = capacity - 1;
        else
            rear--;
        size--;
    }

    void display()
    {
        if(isEmpty()) {
            cout << "deQueue Empty" << endl;
            return;
        }

        int temp = front;
        for (int i = 0; i < size; i++)
        {
            cout << arr[temp] << " ";
            temp= (temp+1) % capacity ;
        }
        cout << endl;
    }
};

int main()
{
    Dequeue q1(10); 
    q1.insertFront(10);
    q1.insertRear(5);
    q1.insertRear(1);
    q1.insertRear(3);
    q1.insertRear(2);
    q1.insertFront(12);
    q1.display();
    cout << q1.front ; 
    
    return 0;
}