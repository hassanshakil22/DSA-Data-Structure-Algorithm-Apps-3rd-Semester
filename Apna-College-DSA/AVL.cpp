#include <iostream>
#include <vector>
using namespace std;
class AVLTree
{
private:
    struct ListNode
    {
        int key;
        ListNode *next;
        ListNode(int k) : key(k) {}
    };
    struct Node
    {
        int key;
        Node *left;
        Node *right;
        int height;
        Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
    };
    Node *root;

    int height(Node *node)
    {
        return node ? node->height : 0;
    }
    int balanceFactor(Node *node)
    {
        return node ? height(node->left) - height(node->right) : 0;
    }
    void updateHeight(Node *node)
    {
        node->height = 1 + max(height(node->left), height(node->right));
    }
    Node *rotateRight(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }
    Node *rotateLeft(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }
    Node *balance(Node *node)
    {
        updateHeight(node);
        int balance = balanceFactor(node);
        // Left heavy
        if (balance > 1)
        {
            if (balanceFactor(node->left) < 0) // Left-Right case
                node->left = rotateLeft(node->left);
            return rotateRight(node); // Left-Left case
        }
        // Right heavy
        if (balance < -1)
        {
            if (balanceFactor(node->right) > 0) // Right-Left case
                node->right = rotateRight(node->right);
            return rotateLeft(node); // Right-Right case
        }
        return node; // Balanced
    }
    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }
    Node *insert(Node *node, int key)
    {

        if (!node)
            return new Node(key);
        else if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;
        // recursive insertion in a bst
        //  implement the code
        return balance(node);
    }
    Node *deleteNode(Node *root, int key)
    {
        // Perform standard BST delete
        if (!root)
            return root;
        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else
        {
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            Node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
        // Balance the node
        return balance(root);
    }

    void inOrder(Node *node)
    {
        if (!node)
            return;
        inOrder(node->left);
        cout << node->key << " ";
        inOrder(node->right);
    }

public:
    AVLTree() : root(nullptr) {}
    void insert(int key)
    {
        root = insert(root, key);
    }
    void deleteKey(int key)
    {
        root = deleteNode(root, key);
    }
    void inOrder()
    {
        inOrder(root);
        cout << endl;
    }
    // Node *buildFromSortedArray(int *nums, int start, int end)
    // {
    //     if (start > end)
    //         return nullptr;

    //     int mid = (start + end) / 2;
    //     Node *node = new Node(nums[mid]);

    //     node->left = buildFromSortedArray(nums, start, mid - 1);
    //     node->right = buildFromSortedArray(nums, mid + 1, end);

    //     updateHeight(node); // maintain AVL height metadata
    //     return node;        // no need to balance; construction guarantees it
    // }

    // [2,3,5,6,7]
    Node *buildFromSortedArray(int *arr, int start, int end)
    {
        if (start > end)
            return NULL;

        int mid = start + (end - start) / 2;
        Node *node = new Node(arr[mid]);
        node->left = buildFromSortedArray(arr, start, mid - 1);
        node->right = buildFromSortedArray(arr, mid + 1, end);

        updateHeight(node);
        return node;

    }
    Node *buildFromSortedList(ListNode *head, int n)
    {
        int *arr = new int[n];
        ListNode *curr = head;
        for (int i = 0; i < n; i++)
        {
            arr[i] = curr->key;
            curr = curr->next;
        }

        Node *root = buildFromSortedArray(arr, 0, n - 1);
        delete[] arr; // free memory
        return root;
    }
};
int main()
{
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(20); // Duplicate insertion
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    cout << "In-order traversal before deletion: ";
    tree.inOrder();
    tree.deleteKey(20);
    cout << "In-order traversal after deleting 20: ";
    tree.inOrder();
    return 0;
}
