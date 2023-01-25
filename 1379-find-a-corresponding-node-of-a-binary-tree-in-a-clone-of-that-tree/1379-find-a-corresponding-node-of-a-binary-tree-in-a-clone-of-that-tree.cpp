/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */

class Solution
{
    public:
        unordered_map<TreeNode*, TreeNode*> m;
    void preOrder(TreeNode *original, TreeNode *cloned)
    {
        if (original == NULL) return;
        m[original] = cloned;
        preOrder(original->left, cloned->left);
        preOrder(original->right, cloned->right);
    }
    TreeNode* getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        preOrder(original, cloned);
        return m[target];
    }
};