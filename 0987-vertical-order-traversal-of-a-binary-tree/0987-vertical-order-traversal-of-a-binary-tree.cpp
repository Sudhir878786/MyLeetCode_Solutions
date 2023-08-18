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
    void func(TreeNode*root,int ind,int lev,map<int,vector<pair<int,int>>>&mp)
    {
        if(!root){
            return;
        }
        mp[ind].push_back({lev,root->val});
        func(root->left,ind-1,lev+1,mp);
        func(root->right,ind+1,lev+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,vector<pair<int,int>>>mp;
        func(root,0,0,mp);
       
        for (auto x: mp)
        {
            vector<int> v;
            sort(begin(x.second), end(x.second));
            for (auto i: x.second) v.push_back(i.second);
            ans.push_back(v);
        }
        return ans;
    }
};