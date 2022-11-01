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
        int findBottomLeftValue(TreeNode *root)
        {
            queue<TreeNode*> q;
            q.push(root);
            TreeNode * curr;
            while (!q.empty())
            {
                curr = q.front();
                q.pop();
                if (curr->right != NULL) q.push(curr->right);
                if (curr->left != NULL) q.push(curr->left);
            }
            return curr->val;
        }
};