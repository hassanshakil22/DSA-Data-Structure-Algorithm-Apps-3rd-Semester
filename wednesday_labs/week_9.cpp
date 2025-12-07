#include <iostream>
#include <stack>
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

    void deleteNode(int key)
    {
        root = deleteRec(root, key);
    }

    void inorder()
    {
        inorderRec(root);
        cout << endl;
    }

    
    void preorder()
    {
        if (root == NULL)
            return;

        stack<TreeNode *> st;
        st.push(root);

        cout << "Preorder Traversal: ";
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();

            cout << node->val << " ";

            // Push right child first so left is processed first
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
        cout << endl;
    }

    void postorder()
    {
        if (root == NULL)
            return;

        stack<TreeNode *> st1, st2;
        st1.push(root);

        while (!st1.empty())
        {
            TreeNode *node = st1.top();
            st1.pop();
            st2.push(node);

            if (node->left)
                st1.push(node->left);
            if (node->right)
                st1.push(node->right);
        }

        cout << "Postorder Traversal: ";
        while (!st2.empty())
        {
            cout << st2.top()->val << " ";
            st2.pop();
        }
        cout << endl;
    }

private:
    // Recursive insertion
    TreeNode *insertRec(TreeNode *node, int key)
    {
        if (node == NULL)
            return new TreeNode(key);
        if (key < node->val)
            node->left = insertRec(node->left, key);
        else if (key > node->val)
            node->right = insertRec(node->right, key);
        return node;
    }

    // Recursive deletion
    TreeNode *deleteRec(TreeNode *node, int key)
    {
        if (node == NULL)
            return node;

        if (key < node->val)
            node->left = deleteRec(node->left, key);
        else if (key > node->val)
            node->right = deleteRec(node->right, key);
        else
        {
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

            TreeNode *temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = deleteRec(node->right, temp->val);
        }
        return node;
    }

    // Minimum value node
    TreeNode *minValueNode(TreeNode *node)
    {
        TreeNode *current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    // Inorder (recursive)
    void inorderRec(TreeNode *root)
    {
        if (root != NULL)
        {
            inorderRec(root->left);
            cout << root->val << " ";
            inorderRec(root->right);
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

    bst.preorder();  // 🔹 Preorder using stack
    bst.postorder(); // 🔹 Postorder using stack

    cout << "Delete 20\n";
    bst.deleteNode(20);

    cout << "Inorder traversal after deleting 20: ";
    bst.inorder();

    bst.preorder();
    bst.postorder();
}
