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

        void helper(TreeNode *root, int i, int l, map<int, vector<pair<int, int>>> &mp)
        {
            if (!root) return;
            mp[i].push_back({ l,
                root->val });
            helper(root->left, i - 1, l + 1, mp);
            helper(root->right, i + 1, l + 1, mp);
        }
    vector<vector < int>> verticalTraversal(TreeNode *root)
    {
        vector<vector < int>> res;
        map<int, vector<pair<int, int>>> mp;
        helper(root, 0, 0, mp);
        for (auto x: mp)
        {
            vector<int> v;
            sort(begin(x.second), end(x.second));
            for (auto i: x.second) v.push_back(i.second);
            res.push_back(v);
        }
        return res;
    }
};