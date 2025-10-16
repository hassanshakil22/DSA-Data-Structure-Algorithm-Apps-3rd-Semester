#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

class LL
{

public:
    Node *head;
    Node *tail;
    LL()
    {
        head = tail = nullptr;
    };

    void push(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        tail = newNode;
    }
    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

void llunion(Node *head1, Node *head2)
{
}

bool isPalindrome(Node *head)
{

    // tail = tail->prev
    // head = head->next


    //     S  
    //   1,2,3,4,3,2,1 
    //       F
    // 
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *prev = NULL;
    Node *curr = slow;
    while (curr)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    Node *first = head;
    Node *second = prev;

    while (second)
    {
        if (first->data != second->data)
        {
            return false;
        }
        first = first->next;
        second = second->next;
    }
    return true;
}

void sort(Node *head)
{
    bool swapped;
    Node *end = NULL;
    do
    {
        Node *temp = head;
        swapped = false;
        while (temp->next != end)
        {
            if (temp->data > temp->next->data)
            {
                swap(temp->data, temp->next->data);
                swapped = true;
            }
            temp = temp->next;
        }
        end = temp;
    } while (swapped);
}

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* intersection(Node* L1, Node* L2) {
    vector<int> v;
    Node* result = NULL;
    Node* tail = NULL;

    // Step 1: Store all elements of L1 in vector
    for (Node* curr = L1; curr != NULL; curr = curr->next)
        v.push_back(curr->data);

    // Step 2: Traverse L2 and check existence in vector
    for (Node* curr = L2; curr != NULL; curr = curr->next) {
        auto it = find(v.begin(), v.end(), curr->data);
        if (it != v.end()) {
            // Found in both lists → intersection
            Node* node = new Node(curr->data);
            if (!result) result = tail = node;
            else { tail->next = node; tail = node; }

            // Erase to prevent duplicate intersection
            v.erase(it);
        }
    }

    return result;
}


int main()
{
    LL l1;
    LL l2;
    l1.push(1);
    l1.push(2);
    l1.push(3);

    l2.push(2);
    l2.push(32);
    l2.push(43);
    l2.push(15);
    l2.push(4);
    l2.push(3);
    l2.push(2);

    l2.print();

    sort(l2.head);
    l2.print();

    cout << "is Palindrome " << isPalindrome(l2.head);
    return 0;
}