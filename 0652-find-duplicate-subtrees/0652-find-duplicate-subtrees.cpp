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
    vector<TreeNode*>ans;
    string func(TreeNode*root,unordered_map<string,int>&mp)
    {
        if(!root)return "";
        string s= "(";
        s+=func(root->left,mp);
        s+=to_string(root->val);
        s+=func(root->right,mp);
        s+=")";
       
        if(mp[s]==1){
            ans.push_back(root);
        }
         mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>mp;
        if(!root)return ans;
        func(root,mp);
        return ans;
    }
};