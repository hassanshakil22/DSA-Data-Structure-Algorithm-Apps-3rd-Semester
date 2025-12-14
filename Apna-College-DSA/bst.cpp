#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : val(value), left(NULL), right(NULL) {}
};
class BinarySearchTree
{
public:
    TreeNode *root;
    BinarySearchTree() : root(NULL) {}
    void insert(int key)
    {
        root = insertRec(root, key);
    }
    void search(int key)
    {
        if (searchRec(root, key))
        {
            cout << "Found : " << key << endl;
        }
    }
    void deleteNode(int key)
    {
        root = deleteRec(root, key);
    }
    void inorder()
    {
        inorderRec(root);
        cout << endl;
    }

public:
    bool searchRec(TreeNode *node, int val)
    {

        if (node == NULL)
            return false;

        if (node->val == val)
            return true;

        if (val < node->val)
            return searchRec(node->left, val);
        else
            return searchRec(node->right, val);
    }

    // Recursive function to insert a node
    TreeNode *insertRec(TreeNode *root, int key)
    {
        // Base case: if the tree is empty, create a new root
        if (root == NULL)
            return new TreeNode(key);
        // Otherwise, recur down the tree
        else if (key < root->val)
            root->left = insertRec(root->left, key);
        else if (key > root->val)
            root->right = insertRec(root->right, key);
        return root;
    }
    // Recursive function to delete a node
    TreeNode *deleteRec(TreeNode *node, int key)
    {
        // Base case: if the tree is empty
        if (node == NULL)
            return node;
        // Recur down the tree
        // left
        if (key < node->val)
            node->left = deleteRec(node->left, key);
        // right
        else if (key > node->val)
            node->right = deleteRec(node->right, key);
        // found
        else
        {
            // Node with only one child or no child

            // which ever is the not null we'll return it back to the parent's node's(left/right)
            if (node->left == NULL)
            {
                TreeNode *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                TreeNode *temp = node->left;
                delete node;
                return temp;
            }
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            TreeNode *is = getIOsuccessor(node->right);
            // Copy the inorder successor's content to this node
            node->val = is->val;
            // Delete the inorder successor
            node->right = deleteRec(node->right, is->val);
        }
        return node;
    }
    // Find the node with the minimum value (used for deleting nodes)
    TreeNode *getIOsuccessor(TreeNode *node)
    {
        TreeNode *current = node;
        while (current && current->left) // check both current and its left sp we dont go to null
            current = current->left;
        return current;
    }
    // Inorder traversal function
    void inorderRec(TreeNode *root)
    {
        if (root != NULL)
        {
            inorderRec(root->left);
            cout << root->val << " ";
            inorderRec(root->right);
        }
    }
    void preorderTraversalStack(TreeNode *root)
    {
        if (!root)
            return;

        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();

            cout << curr->val << " ";

            // Push right first so left is processed first
            if (curr->right)
                st.push(curr->right);
            if (curr->left)
                st.push(curr->left);
        }
    }

    void postorderTraversalStack(TreeNode *root)
    {
        if (!root)
            return;

        stack<TreeNode *> st1, st2;
        st1.push(root);

        while (!st1.empty())
        {
            TreeNode *curr = st1.top();
            st1.pop();
            st2.push(curr);

            if (curr->left)
                st1.push(curr->left);
            if (curr->right)
                st1.push(curr->right);
        }

        while (!st2.empty())
        {
            cout << st2.top()->val << " ";
            st2.pop();
        }
    }
    void levelOrderTraversal(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (q.size() > 0)
        {
            TreeNode *curr = q.front();
            q.pop();
            cout << curr->val << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        cout << endl;
    }

public:
    void preOrderTraversal(TreeNode *root)
    {
        if (root)
        {
            cout << root->val << " ";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }
    void postOrderTraversal(TreeNode *root)
    {
        if (root)
        {
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            cout << root->val << " ";
        }
    }
};
int main()
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder traversal of the tree: ";
    bst.inorder();
    cout << "Delete 20\n";
    // bst.deleteNode(20);
    // cout << "pre traversal";
    // bst.preOrderTraversal(bst.root);
    // cout << "post traversal ";
    // bst.inorder();
    cout << "level traversal";
    bst.levelOrderTraversal(bst.root);
}
