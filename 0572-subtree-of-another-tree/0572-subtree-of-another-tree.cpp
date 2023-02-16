/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string func(TreeNode* cur,unordered_map<string,int>&mp)
    {
        if(!cur)return " ";
        string s=to_string(cur->val)+func(cur->left,mp)+ func(cur->right,mp);
        mp[s]++;
        return s;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        unordered_map<string,int>mp;
        string a=func(root,mp);
        string b=func(subRoot,mp);
        return mp[b]>1;
    }
};