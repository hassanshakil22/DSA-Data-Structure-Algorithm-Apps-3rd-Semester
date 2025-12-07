#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int val;
    Node *right;
    Node *left;
    Node(int val)
    {
        this->val = val;
        right = NULL;
        left = NULL;
    }
};

class BinaryTree
{
    Node *root;

public:
    BinaryTree()
    {
        root = NULL;
    }

    int ci = -1;
    Node *construct_preorder(int arr[])
    {
        ci++;
        if (arr[ci] == -1)
            return NULL;
        Node *root = new Node(arr[ci]);
        root->left = construct_preorder(arr);
        root->right = construct_preorder(arr);
        return root;
    }

    int heightOfTree(Node *root)
    {
        if (!root)
            return 0;

        int leftht = heightOfTree(root->left);
        int rightht = heightOfTree(root->right);
        return max(leftht, rightht) + 1;
    }
    int diameter = 0;
    int heightWithMaxDiam(Node *root)
    {
        if (!root)
            return 0;
        int leftheight = heightWithMaxDiam(root->left);
        int rightheight = heightWithMaxDiam(root->right);
        diameter = max(diameter, leftheight + rightheight);
        return max(leftheight, rightheight) + 1;
    }

    int maxDiameterOfBT(Node *root)
    {
        heightWithMaxDiam(root);
        return diameter;
    }

    //  int maxDiameterOfBT(Node *root)
    // {
    //     if (!root)
    //         return 0;
    //     int leftdiam = maxDiameterOfBT(root->left);
    //     int rightdiam = maxDiameterOfBT(root->right);
    //     int rootDiam = heightOfTree(root->left) + heightOfTree(root->right);
    //     return max(rootDiam, max(leftdiam, rightdiam));
    // }
    // void preOrderTraversal(Node* root){
    //     cout << " " << root->val ;
    //     if (root->left)
    //     preOrderTraversal(root->left);
    //     if (root->right)
    //     preOrderTraversal(root->right);
    // }

    void preOrderTraversal(Node *root)
    {
        if (root == NULL)
            return;

        cout << " " << root->val;
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
    void inOrderTraversal(Node *root)
    {
        if (root == NULL)
            return;

        inOrderTraversal(root->left);
        cout << " " << root->val;
        inOrderTraversal(root->right);
    }
    void postOrderTraversal(Node *root)
    {
        if (root == NULL)
            return;

        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << " " << root->val;
    }

    void levelOrderTraversal(Node *root)
    {
        queue<Node *> q;
        q.push(root);

        while (q.size() > 0)
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->val << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        cout << endl;
    }
};

int main()
{

    int arr[] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    BinaryTree b1;
    Node *root = b1.construct_preorder(arr);
    cout << "preorder" << root->val << endl;

    b1.preOrderTraversal(root);
    cout << "\n  inorder" << root->val << endl;
    b1.inOrderTraversal(root);
    cout << "\n  inorder" << root->val << endl;
    b1.postOrderTraversal(root);
    cout << "\n  level order" << root->val << endl;
    b1.levelOrderTraversal(root);

    cout << "\n root : " << root->val << endl;
    cout << "root->left : " << root->left->val << endl;
    cout << "root->right : " << root->right->val << endl;

    return 0;
}