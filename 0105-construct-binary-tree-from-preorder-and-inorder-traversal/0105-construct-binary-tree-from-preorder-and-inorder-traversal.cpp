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
        unordered_map<int, int> mp;
    int rootidx = 0;
    TreeNode* func(vector<int> &preorder, vector<int> &inorder, int start, int end)
    {
        if (start > end) return 0;

        TreeNode *ans = new TreeNode(preorder[rootidx++]);
        if (start == end) return ans;
        int mid = mp[ans->val];
        cout<<mid<<endl;

        ans->left = func(preorder, inorder, start, mid - 1);
        ans->right = func(preorder, inorder, mid + 1, end);
        return ans;
    }
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return func(preorder, inorder, 0, inorder.size() - 1);
    }
};