#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// --------------------------------------- Q1 ---------------------------------------

// class Queue
// {
// private:
//     Node *rear;

// public:
//     Queue()
//     {
//         rear = nullptr;
//     }
//     void enqueue(int value)
//     {
//         Node *newNode = new Node(value);

//         if (rear == nullptr)
//         {
//             rear = newNode;
//             rear->next = rear;
//         }
//         else
//         {
//             newNode->next = rear->next; // first pointing the next of new node to rear's as that would point to front of the queue
//             rear->next = newNode;       // now rear->next will be new node whihch will be the one previous of new node
//             rear = newNode;
//         }
//     }

//     void dequeue()
//     {
//         if (rear == nullptr)
//         {
//             cout << "Queue Underflow!" << endl;
//             return;
//         }
//         Node *front = rear->next;

//         if (rear == front)
//         { // Only one element
//             delete front;
//             rear = nullptr;
//         }
//         else
//         {
//             rear->next = front->next;
//             delete front;
//         }
//     }
//     int peek()
//     {
//         if (rear == nullptr)
//         {
//             cout << "Queue is empty!" << endl;
//             return -1;
//         }
//         return rear->next->data;
//     }
//     bool isEmpty()
//     {
//         return (rear == nullptr);
//     }
//     void display()
//     {
//         if (rear == nullptr)
//         {
//             cout << "Queue is empty!" << endl;
//             return;
//         }

//         Node *temp = rear->next; // start from front
//         do
//         {
//             cout << temp->data << " ";
//             temp = temp->next;
//         } while (temp != rear->next);
//         cout << endl;
//     }
// };

// --------------------------------------- Q2 ---------------------------------------

// class Dequeue
// {
// private:
//     Node *rear;

// public:
//     Dequeue()
//     {
//         rear = nullptr;
//     }
//     void InsertFront(int value)
//     {
//         Node *newNode = new Node(value);

//         if (rear == nullptr)
//         {
//             rear = newNode;
//             rear->next = rear;
//         }
//         else
//         {
//             newNode->next = rear->next; // first pointing the next of new node to rear's as that would point to front of the queue
//             rear->next = newNode;             // now rear->next will be new node whihch will be the first node
//         }
//     }
//     void InsertRear(int value)
//     {
//         Node *newNode = new Node(value);

//         if (rear == nullptr)
//         {
//             rear = newNode;
//             rear->next = rear;
//         }
//         else
//         {
//             newNode->next = rear->next; // first pointing the next of new node to rear's as that would point to front of the queue
//             rear->next = newNode;       // now rear->next will be new node whihch will be the one previous of new node
//             rear = newNode;
//         }
//     }

//     void DeleteFront()
//     {
//         if (rear == nullptr)
//         {
//             cout << "Queue Underflow!" << endl;
//             return;
//         }
//         Node *front = rear->next;

//         if (rear == front)
//         { // Only one element
//             delete front;
//             rear = nullptr;
//         }
//         else
//         {
//             rear->next = front->next;
//             delete front;
//         }
//     }
//     void DeleteRear()
//     {
//         if (rear == nullptr)
//         {
//             cout << "Queue Overflow!" << endl;
//             return;
//         }
//         Node *temp = rear->next;
//         while (temp->next != rear)
//         {
//             temp = temp->next;
//         }
//         temp->next = rear->next;
//         delete rear;
//         rear = temp;
//     }

//     int GetFront()
//     {
//         if (rear == nullptr)
//         {
//             cout << "Queue is empty!" << endl;
//             return -1;
//         }
//         return rear->next->data;
//     }
//     int Getrear()
//     {
//         if (rear == nullptr)
//         {
//             cout << "Queue is empty!" << endl;
//             return -1;
//         }
//         return rear->data;
//     }
//     bool isEmpty()
//     {
//         return (rear == nullptr);
//     }
//     void display()
//     {
//         if (rear == nullptr)
//         {
//             cout << "Queue is empty!" << endl;
//             return;
//         }

//         Node *temp = rear->next; // start from front
//         do
//         {
//             cout << temp->data << " ";
//             temp = temp->next;
//         } while (temp != rear->next);
//         cout << endl;
//     }
// };

// --------------------------------------- Q3 ---------------------------------------

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = prev = nullptr;
    }
};
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;

    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at the end
    void insert(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        { // empty list
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
};
void displayForward(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *mergeTwoList(Node *list1_head, Node *list2_head)
{

    Node *dummy = new Node(0);
    Node *tail = dummy;

    while (list1_head && list2_head)
    {
        if (list1_head->data <= list2_head->data)
        {
            tail->next = list1_head;
            list1_head->prev = tail;
            list1_head = list1_head->next;
        }
        else
        {
            tail->next = list2_head;
            list2_head->prev = tail;
            list2_head = list2_head->next;
        }
        tail = tail->next;
    }
    if (list1_head)
    {
        tail->next = list1_head;
        list1_head->prev = tail;
    }
    else
    {
        tail->next = list2_head;
        list2_head->prev = tail;
    }
    Node *head = dummy->next;
    if (head)
        head->prev = nullptr;

    delete dummy;
    return head;
}

// --------------------------------------- Q4 ---------------------------------------

Node *reverseList(Node *head)
{
    Node *temp = nullptr;
    Node *curr = head;
    while (curr)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp)
        head = temp->prev;
    return head;
}
// --------------------------------------- Q5 ---------------------------------------

class BrowserHistory
{
public:
    vector<string> browsingHistory;
    int currentPage = 0;
    BrowserHistory(string homepage) { browsingHistory.push_back(homepage); }

    void visit(string url)
    {
        if (currentPage != browsingHistory.size() - 1)
        {
            browsingHistory.erase(browsingHistory.begin() + currentPage + 1,
                                  browsingHistory.end());
        }
        browsingHistory.push_back(url);
        currentPage = browsingHistory.size() - 1;
    }

    string back(int steps)
    {
        if (currentPage > steps - 1)
        {
            currentPage -= steps;
        }
        else
        {
            currentPage = 0;
        }
        return browsingHistory[currentPage];
    }

    string forward(int steps)
    {
        if (currentPage + steps < browsingHistory.size() - 1)
            currentPage += steps;
        else
        {
            currentPage = browsingHistory.size() - 1;
        }

        return browsingHistory[currentPage];
    }

    void printHistory()
    {
        cout << "browsing history : [";
        for (string i : browsingHistory)
        {
            cout << i << ",";
        }
        cout << " ]" << endl;
    }
};

int main()
{
    // --- ans 1 
    // Queue q;
    // q.enqueue(10);
    // q.enqueue(20);
    // q.enqueue(30);

    // cout << "Front: " << q.peek() << endl; // 10
    // q.dequeue();
    // cout << "Front after dequeue: " << q.peek() << endl; // 20

    // ------------------ a2

    // Dequeue q1;
    // q1.InsertFront(5);
    // q1.InsertFront(3);
    // q1.InsertRear(51);
    // q1.InsertRear(4);
    // q1.InsertFront(32);

    // cout << "Front: " << q1.GetFront() << endl; // 10
    // cout << "Rear: " << q1.Getrear() << endl;   // 10
    // q1.display();
    // q1.DeleteFront();
    // q1.DeleteRear();
    // q1.display();
    // --- ans 3
    DoublyLinkedList L;
    L.insert(2);
    L.insert(4);
    L.insert(6);
    L.insert(8);
    L.insert(10);
    DoublyLinkedList M;
    M.insert(1);
    M.insert(3);
    M.insert(5);
    M.insert(7);
    M.insert(9);
    displayForward(L.head);
    displayForward(M.head);
    Node *merged = mergeTwoList(M.head, L.head);
    displayForward(merged);
    // --- ans 4
    Node *desc = reverseList(merged);
    displayForward(desc);

    // --- ans 5

    BrowserHistory bh("google.com");
    bh.visit("googlepoogle");
    bh.visit("fb.com");
    bh.visit("insta.com");
    bh.printHistory();
    cout << bh.forward(1);
    cout << bh.back(2);
}
