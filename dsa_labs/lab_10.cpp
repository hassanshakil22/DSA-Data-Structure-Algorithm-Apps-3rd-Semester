#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Q-1- ------------------------------------

struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
    Node(int k) : key(k), left(NULL), right(NULL), height(1) {}
};
int height(Node *n)
{
    if (n != nullptr)
    {
        return n->height;
    }
    else
    {
        return 0;
    }
}
int getbalance(Node *n)
{
    return n ? height(n->left) - height(n->right) : 0;
}
Node *rightrotation(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}
Node *leftrotation(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node *insert(Node *node, int key)
{
    if (!node)
        return new Node(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getbalance(node);
    if (balance > 1 && key < node->left->key)
        return rightrotation(node);
    if (balance < -1 && key > node->right->key)
        return leftrotation(node);
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftrotation(node->left);
        return rightrotation(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightrotation(node->right);
        return leftrotation(node);
    }
    return node;
}
Node *minimumnode(Node *node)
{
    Node *current = node;
    while (current->left)
        current = current->left;
    return current;
}

Node *deletenode(Node *root, int key)
{
    if (!root)
        return root;

    if (key < root->key)
        root->left = deletenode(root->left, key);
    else if (key > root->key)
        root->right = deletenode(root->right, key);
    else
    {
        if (!root->left || !root->right)
        {
            Node *temp = root->left ? root->left : root->right;
            if (!temp)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            delete temp;
        }
        else
        {
            Node *temp = minimumnode(root->right);
            root->key = temp->key;
            root->right = deletenode(root->right, temp->key);
        }
    }
    if (!root)
        return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getbalance(root);
    if (balance > 1 && getbalance(root->left) >= 0)
        return rightrotation(root);
    if (balance > 1 && getbalance(root->left) < 0)
    {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }
    if (balance < -1 && getbalance(root->right) <= 0)
        return leftrotation(root);
    if (balance < -1 && getbalance(root->right) > 0)
    {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }
    return root;
}
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

struct Tree1
{
    int val;
    Tree1 *left;
    Tree1 *right;
    Tree1(int x) : val(x), left(NULL), right(NULL) {}
};
Tree1 *BST(vector<int> &nums, int left, int right)
{
    if (left > right)
        return NULL;
    int mid = left + (right - left) / 2;
    Tree1 *root = new Tree1(nums[mid]);
    root->left = BST(nums, left, mid - 1);
    root->right = BST(nums, mid + 1, right);
    return root;
}
Tree1 *arraytobst(vector<int> &nums)
{
    return BST(nums, 0, nums.size() - 1);
}
void preorder(Tree1 *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Q-3- ------------------------------------
struct listnode
{
    int val;
    listnode *next;
    listnode(int x) : val(x), next(NULL) {}
};
struct Tree
{
    int val;
    Tree *left;
    Tree *right;
    Tree(int x) : val(x), left(NULL), right(NULL) {}
};
listnode *formiddle(listnode *head, listnode *tail)
{
    listnode *slow = head;
    listnode *fast = head;
    while (fast != tail && fast->next != tail)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Tree *listtotree(listnode *head, listnode *tail = NULL)
{
    if (head == tail)
        return NULL;
    listnode *mid = formiddle(head, tail);
    Tree *root = new Tree(mid->val);
    root->left = listtotree(head, mid);
    root->right = listtotree(mid->next, tail);
    return root;
}
void preorder(Tree *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Q-4- ------------------------------------

struct Tree4
{
    int val;
    Tree4 *left;
    Tree4 *right;
    Tree4(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    int diameter;
    int height(Tree4 *root)
    {
        if (!root)
            return 0;
        int lefth = height(root->left);
        int righth = height(root->right);
        diameter = max(diameter, lefth + righth);
        return 1 + max(lefth, righth);
    }
    int diameterOfBST(Tree4 *root)
    {
        diameter = 0;
        height(root);
        return diameter;
    }
};

int main()
{
    // A-1- ------------------------------------
    cout << "===================== Ans 1 ==================== " << endl;

    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    cout << "inorder traversal: " << endl;
    inorder(root);
    root = deletenode(root, 30);
    cout << endl
         << "After deletion: " << endl;
    inorder(root);
    return 0;

    // A-2- ------------------------------------
    cout << "===================== Ans 2 ==================== " << endl;

    vector<int> nums = {-10, -3, 0, 5, 9};
    Tree1 *root1 = arraytobst(nums);
    cout << "Preorder traverse: ";
    preorder(root1);
    return 0;

    // A-3- ------------------------------------
    cout << "===================== Ans 3 ==================== " << endl;
    listnode *head = new listnode(-10);
    head->next = new listnode(-3);
    head->next->next = new listnode(0);
    head->next->next->next = new listnode(5);
    head->next->next->next->next = new listnode(9);
    Tree *root2 = listtotree(head);
    cout << "Preorder traversal: ";
    preorder(root2);
    return 0;

    // A-4- ------------------------------------

    cout << "===================== Ans 4 ==================== " << endl;

    Tree4 *root4 = new Tree4(4);
    root4->left = new Tree4(2);
    root4->right = new Tree4(6);
    root4->left->left = new Tree4(1);
    root4->left->right = new Tree4(3);
    root4->right->right = new Tree4(7);
    Solution sol;
    cout << "Diameter is " << sol.diameterOfBST(root4);
    return 0;
}