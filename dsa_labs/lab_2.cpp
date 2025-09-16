#include <iostream>
using namespace std;
  // Insert at the end
    // void append(int val)
    // {
    //     Node *newNode = new Node(val);
    //     if (head == nullptr)
    //     {
    //         head = newNode;
    //         tail = newNode;
    //         return;
    //     }
    //     Node *temp = head;
    //     while (temp->next != nullptr)
    //     {
    //         temp = temp->next;
    //     }
    //     temp->next = newNode;
    //     tail = newNode;
    // }

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

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = tail = nullptr;
    }
  
    void append(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
};

void printList(Node *head)
{
    if (!head)
        return;
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp && temp != head);
    cout << endl;
}
// exc 1 :
Node *mergeTwoList(Node *list1_head, Node *list2_head)
{

    Node *dummy = new Node(0);
    Node *tail = dummy;

    while (list1_head && list2_head)
    {
        if (list1_head->data <= list2_head->data)
        {
            tail->next = list1_head;
            list1_head = list1_head->next;
        }
        else
        {
            tail->next = list2_head;
            list2_head = list2_head->next;
        }
        tail = tail->next;
    }
    if (list1_head)
        tail->next = list1_head;
    else
        tail->next = list2_head;

    return dummy->next;
}

// exc 2:
Node *deleteDuplicates(LinkedList list1)
{
    Node *current = list1.head;
    while (current && current->next)
    {
        if (current->data == current->next->data)
        {
            Node *deleteNode = current->next;
            current->next = current->next->next;
            delete deleteNode;
        }
        else
        {
            current = current->next;
        }
    }
    return list1.head;
}

// exc : 3
Node *mergeSort(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *rightHalf = slow->next;
    slow->next = nullptr;
    Node *leftHalf = head;

    Node *leftSorted = mergeSort(leftHalf);
    Node *rightSorted = mergeSort(rightHalf);

    return mergeTwoList(leftSorted, rightSorted);
}

// exc : 4
Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    while (curr)
    {
        Node *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    if (!head || !head->next)
        return true;
    Node *slow = head;
    Node *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *secHalf = reverseList(slow->next);
    Node *firstHalf = head;
    Node *secondHalfCopy = secHalf;
    bool palindrome = true;
    while (secHalf)
    {
        if (secHalf->data != firstHalf->data)
        {
            palindrome = false;
            break;
        }
        secHalf = secHalf->next;
        firstHalf = firstHalf->next;
    }
    slow->next = reverseList(secondHalfCopy);
    return palindrome;
}

class Stack
{
public:
    LinkedList data;

    Stack(int val)
    {
        data.append(val);
    }
    void print()
    {
        printList(data.head);
    }
    void push(int val)
    {
        data.append(val);
    }

    void pop()
    {
        Node *temp = data.head;
        data.head = data.head->next;
        delete temp;
    }
    int peek()
    {
        return data.head->data;
    }
};

class CircularQueue
{
public:
    LinkedList data;
    CircularQueue(int val)
    {
        data.append(val);
        data.tail->next = data.head;
    }
    void print()
    {
        printList(data.head);
    }
    void enqueue(int val)
    {
        data.append(val);
        data.tail->next = data.head;
    }
    void dequeue()
    {
        Node *temp = data.head;
        data.head = data.head->next;
        delete temp;
        data.tail->next = data.head;
    }
};

int main()
{
    LinkedList list1, list2;
    list1.append(1);
    list1.append(2);
    list1.append(3);
    list1.append(4);
    list1.append(3);
    list1.append(2);
    list1.append(1);
    printList(list1.head);
// exc 4
    // cout << "Is palindrome : " << isPalindrome(list1.head) << endl;

    printList(list1.head);

    // cout << "merged sort" << endl;
    // printList(mergeSort(list1.head));

    // 5,6

    // Stack s1(5);
    // s1.push(4);
    // s1.push(2);
    // s1.push(1);
    // s1.print();
    // cout << " Peaking " << s1.peek() << endl;
    // s1.pop();
    // s1.print();


    // CircularQueue c1(5);
    // c1.enqueue(2);
    // c1.enqueue(1);
    // c1.enqueue(6);
    // c1.enqueue(4);
    // c1.print(); // Should print: 5 2 1 6 4
    // c1.dequeue();
    // c1.print(); // Should print: 2 1 6 4
    // cout << "front: " << c1.data.head->data << " rear: " << c1.data.tail->data << endl;
    
    
    // Node *mergedHead = mergeTwoList(list1, list2);
    // printList(mergedHead);
    // Node *distinctHead = deleteDuplicates(list1);
    // printList(distinctHead);

    return 0;
}