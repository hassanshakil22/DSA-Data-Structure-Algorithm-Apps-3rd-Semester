

#include <iostream>
#include <vector>
#include <stack>

#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

Node *buildTreeFromPreorder(vector<int> &preorder)
{
    if (preorder.empty() || preorder[0] == -1)
        return nullptr;

    Node *root = new Node(preorder[0]);
    stack<pair<Node *, int>> st;
    st.push({root, 0});

    int i = 1;
    while (i < preorder.size())
    {
        Node *curr = st.top().first;
        int &state = st.top().second;

        if (preorder[i] == -1)
        {
            state++;
            if (state == 2)
                st.pop();
            i++;
        }
        else
        {
            Node *newNode = new Node(preorder[i]);
            if (state == 0)
                curr->left = newNode;
            else
                curr->right = newNode;

            state++;
            st.push({newNode, 0});
            i++;
        }
    }
    return root;
}
static int idx0;

Node *buildTreeFromPostorder(vector<int> &postorder)
{
    if (idx0 < 0 || postorder[idx0] == -1)
    {
        idx0--;
        return nullptr;
    }

    Node *root = new Node(postorder[idx0]);
    idx0--;

    root->right = buildTreeFromPostorder(postorder);
    root->left = buildTreeFromPostorder(postorder);

    return root;
}

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
static int idx = -1;

class employeeNode
{
public:
    int id;
    string name, department;
    employeeNode *left;
    employeeNode *right;

    employeeNode(int empId, string empName, string empDept)
    {
        id = empId;
        name = empName;
        department = empDept;
        left = right = nullptr;
    }
};
class EmployeeBST
{
public:
    employeeNode *insert(employeeNode *root, int id, string name, string dept)
    {
        if (!root)
            return new employeeNode(id, name, dept);

        if (id < root->id)
            root->left = insert(root->left, id, name, dept);
        else
            root->right = insert(root->right, id, name, dept);

        return root;
    }

    employeeNode *minValueNode(employeeNode *node)
    {
        employeeNode *current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    employeeNode *del(employeeNode *root, int id, string name, string dept)
    {
        if (!root)
            return root;

        if (id < root->id)
            root->left = del(root->left, id, name, dept);
        else if (id > root->id)
            root->right = del(root->right, id, name, dept);

        else
        {
            if (root->left == NULL)
            {
                employeeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                employeeNode *temp = root->left;
                delete root;
                return temp;
            }

            employeeNode *temp = minValueNode(root->right);

            root->id = temp->id;
            root->name = temp->name;
            root->department = temp->department;

            root->right = del(root->right, temp->id, temp->name, temp->department);
        }
        return root;
    }

    void inOrderTraversal(employeeNode *root)
    {
        if (!root)
            return;
        inOrderTraversal(root->left);
        cout << "ID: " << root->id
             << " | Name: " << root->name
             << " | Department: " << root->department << endl;
        inOrderTraversal(root->right);
    }

    void findMin(employeeNode *root)
    {
        if (!root)
        {
            cout << "Tree is empty.\n";
            return;
        }
        employeeNode *current = root;
        while (current->left)
            current = current->left;
        cout << "\nEmployee with Smallest ID:\n";
        cout << "ID: " << current->id
             << " | Name: " << current->name
             << " | Department: " << current->department << endl;
    }

    // ✅ Find the employee with the largest ID
    void findMax(employeeNode *root)
    {
        if (!root)
        {
            cout << "Tree is empty.\n";
            return;
        }
        employeeNode *current = root;
        while (current->right)
            current = current->right;
        cout << "\nEmployee with Largest ID:\n";
        cout << "ID: " << current->id
             << " | Name: " << current->name
             << " | Department: " << current->department << endl;
    }

    int countnodes(employeeNode *root)
    {
        if (!root)
            return 0;
        countnodes(root->left);
        countnodes(root->right);

        return 1 + countnodes(root->left) + countnodes(root->right);
    }

    employeeNode *lowestCommonAncestor(employeeNode *root, employeeNode *p, employeeNode *q)
    {
        if (!root)
            return nullptr;

        if (p->id < root->id && q->id < root->id)
            return lowestCommonAncestor(root->left, p, q);

        else if (p->id > root->id && q->id > root->id)
            return lowestCommonAncestor(root->right, p, q);

        else
            return root;
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int minDiffInBST(TreeNode *root)
    {
        int minDiff = INT_MAX;
        int prev = -1;
        inOrder(root, prev, minDiff);
        return minDiff;
    }

private:
    void inOrder(TreeNode *node, int &prev, int &minDiff)
    {
        if (!node)
            return;

        inOrder(node->left, prev, minDiff);

        if (prev != -1)
        {
            minDiff = min(minDiff, node->val - prev);
        }
        prev = node->val;

        inOrder(node->right, prev, minDiff);
    }
};

int main()
{
    // =============================================
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root0 = buildTreeFromPreorder(preorder);

    cout << "Root: " << root0->data << endl;
    cout << "Left Child: " << root0->left->data << endl;
    cout << "Right Child: " << root0->right->data << endl;

    vector<int> postorder = {-1, -1, 2, -1, -1, 4, -1, -1, 5, 3, 1};

    idx = postorder.size() - 1;
    Node *root = buildTreeFromPostorder(postorder);

    cout << "Root: " << root->data << endl;
    if (root->left)
        cout << "Left Child: " << root->left->data << endl;
    if (root->right)
        cout << "Right Child: " << root->right->data << endl;

    // =============================================

    EmployeeBST tree;
    employeeNode *root1 = nullptr;

    // Insert employees
    root1 = tree.insert(root1, 50, "Alice", "HR");
    root1 = tree.insert(root1, 30, "Bob", "Finance");
    root1 = tree.insert(root1, 70, "Charlie", "IT");
    root1 = tree.insert(root1, 20, "David", "Marketing");
    root1 = tree.insert(root1, 60, "Eve", "Finance");

    cout << "In-Order Traversal (Ascending by ID):\n";
    tree.inOrderTraversal(root1);

    tree.findMin(root1);
    tree.findMax(root1);

    root1 = tree.del(root1, 70, "Charlie", "IT");
    tree.findMax(root1);

    cout << "Total nodes = " << tree.countnodes(root1);

    employeeNode *p = root1->left->left;
    employeeNode *q = root1->left->right;
    employeeNode *lca = tree.lowestCommonAncestor(root1, p, q);

    cout << "LCA of " << p->id << " and " << q->id << " is Employee ID: "
         << lca->id << " (" << lca->name << ", " << lca->department << ")" << endl;

    TreeNode *root5 = new TreeNode(4);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(6);
    root5->left->left = new TreeNode(1);
    root5->left->right = new TreeNode(3);

    Solution sol;
    int result = sol.minDiffInBST(root5);
    cout << "Minimum difference in BST: " << result << endl;

    return 0;
}
