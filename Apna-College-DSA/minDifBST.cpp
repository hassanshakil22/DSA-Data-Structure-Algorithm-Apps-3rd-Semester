

#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};
vector<int> sortedVector;
void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    sortedVector.push_back(root->val);
    inorder(root->right);
}   
int minDiffInBST(TreeNode *root)
{
    inorder(root);
    int minDiff = INT64_MAX;
    for (int i = 1; i < sortedVector.size(); i++)
    {
        int diff = sortedVector[i] - sortedVector[i - 1];
        minDiff = min(minDiff, diff);   
    }
    return minDiff;
}

#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};
int minDiffInBST(TreeNode *root)
{
    TreeNode *prev = NULL;
    if (!root)
        return INT32_MAX;
    int ans = INT32_MAX;
    if (root->left)
    {
        int leftmin = minDiffInBST(root->left);
        ans = min(leftmin, ans);
    }
}
