/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int s = 0;
    void solve(TreeNode *root)
    {
        if (!root) return;
        if (root->left != NULL and root->left->left == nullptr and root->left->right == nullptr)
        {
            s += root->left->val;
        }
        solve(root->left);
        solve(root->right);
        return;
    }
    int sumOfLeftLeaves(TreeNode *root)
    {

        solve(root);
        return s;
    }
};