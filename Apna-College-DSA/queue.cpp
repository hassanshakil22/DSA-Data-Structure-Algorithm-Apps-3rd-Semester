#include <iostream>
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

// class Queue
// {
// public:
//     Node *front;
//     Node *rear;

//     Queue()
//     {
//         front = rear = nullptr;
//     }
//     bool isEmpty()
//     {
//         return front == nullptr;
//     }

//     void enQueue(int val)
//     {
//         Node *newNode = new Node(val);
//         if (isEmpty())
//         {
//             front = rear = newNode;
//             return;
//         }
//         rear->next = newNode;
//         rear = newNode;
//         rear->next = nullptr;
//     }

//     void deQueue()
//     {
//         if (isEmpty())
//         {
//             cout << "Queue is empty" << endl;
//             return;
//         }
//         Node *deleteNode = front;
//         front = front->next;
//         delete deleteNode;
//     }
//     int peak()
//     {
//         if (isEmpty())
//         {
//             cout << "Queue is empty" << endl;
//             return -1;
//         }
//         return front->data;
//     }
//     void printQueue()
//     {
//         Node *temp = front;
//         while (temp!= nullptr)
//         {
//             cout << "-" << temp->data << "-";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
// };
//  ======================================================================================== ========================================================================================

// class Deque
// {
// public:
//     Node *front;
//     Node *rear;

//     Deque()
//     {
//         front = rear = nullptr;
//     }
//     bool isEmpty()
//     {
//         return front == nullptr;
//     }

//     void insertRear(int val)
//     {
//         Node *newNode = new Node(val);
//         if (isEmpty())
//         {
//             front = rear = newNode;
//             return;
//         }
//         rear->next = newNode;
//         rear = newNode;
//         rear->next = nullptr;
//     }
//     void insertFront(int val)
//     {
//         Node *newNode = new Node(val);
//         if (isEmpty())
//         {
//             front = rear = newNode;
//             return;
//         }
//         newNode->next = front;
//         front = newNode;
//     }

//     void popFront()
//     {
//         if (isEmpty())
//         {
//             cout << "Queue is empty" << endl;
//             return;
//         }
//         Node *deleteNode = front;
//         front = front->next;
//         delete deleteNode;
//     }

//     void popBack()
//     {
//         if (isEmpty())
//         {
//             cout << "Queue is empty" << endl;
//             return;
//         }
//         if(rear == front){
//             delete front;
//             delete rear;
//             return;
//         }
//         Node *temp = front;
//         while (temp->next != rear)
//         {
//             temp = temp->next;
//         }
//         delete rear;
//         rear = temp;
//         rear->next = nullptr;
//     }

//     int peak()
//     {
//         if (isEmpty())
//         {
//             cout << "Queue is empty" << endl;
//             return -1;
//         }
//         return front->data;
//     }
//     void printQueue()
//     {
//         Node *temp = front;
//         while (temp)
//         {
//             cout << "<-" << temp->data ;
//             temp = temp->next;
//         }
//         cout << "<- NULLPTR";
//         cout << endl;
//     }
// };

class CircularQueue
{
public:
    int *arr;
    int front;
    int rear;
    int cap;
    int size;
    CircularQueue(int capacity)
    {
        cap = capacity;
        arr = new int[capacity];
        front = rear = -1;
        size = 0;
    }

    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return size == cap;
    }

    void pushRear(int val)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (rear == cap - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = val;
        size++;
    }

    void pushFront(int val)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = cap - 1;
        }
        else
        {
            front--;
        }

        arr[front] = val;
        size++;
    }

    void popRear()
    {
        if (isEmpty())
        {
            cout << "Queue underflow" << endl;
            return;
        }
        rear = (rear - 1 + cap) % cap;
        size--;
    }

    void popFront()
    {
        if (isEmpty())
        {
            cout << "Queue underflow" << endl;
            return;
        }
        front = (front + 1) % cap;
        size--;
    }

    void printQ()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[(front + i) % cap] << " ";
        }
        cout << endl;
    }
};

class Queue
{
public:
    int *arr;
    int cap;
    int front;
    int rear;

    Queue(int capacity)
    {
        cap = capacity;
        arr = new int[cap];
        front = rear = -1;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return rear == cap - 1;
    }

    void enQueue(int val)
    {
        if (isFull())
        {
            cout << "Queue overflow" << endl;
            return;
        }
        if (isEmpty())
            front = rear = 0;
        else
            rear++;
        arr[rear] = val;
    }
    void deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow" << endl;
            return;
        }
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
    int peak()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    void printQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    // Queue q1;
    // q1.enQueue(5);
    // q1.enQueue(1);
    // q1.enQueue(3);
    // q1.enQueue(12);
    // q1.enQueue(9);
    // q1.enQueue(7);
    // q1.printQueue();
    // q1.deQueue();
    // q1.deQueue();
    // q1.deQueue();
    // q1.printQueue();
    // cout << q1.peak();

    // ======================================================================================== ========================================================================================

    // Deque q2 ;
    // q2.insertFront(5);
    // q2.insertFront(6);
    // q2.insertFront(8);
    // q2.printQueue();
    // q2.insertRear(9);
    // q2.insertRear(19);
    // q2.printQueue();
    // q2.popBack();
    // q2.printQueue();
    // q2.popFront();
    // q2.printQueue();

    // ======================================================================================== ========================================================================================

    CircularQueue q3(8);
    q3.pushRear(1);
    q3.pushRear(2);
    q3.pushRear(3);
    q3.pushRear(4);
    q3.printQ();
    q3.pushFront(0);
    q3.pushFront(-1);
    q3.printQ();
    q3.popFront();
    q3.printQ();
    q3.popRear();
    q3.printQ();

    return 0;
}