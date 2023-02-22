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
    void mapIN(TreeNode* root,map<int,int>&mp)
    {
        if(!root)return;
        mp[root->val]++;
        mapIN(root->left,mp);
        mapIN(root->right,mp);
        
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        map<int,int>mp;
        mapIN(root,mp);
        int count=0;
        for(auto it:mp){
            // cout<<it.first<<" "<<it.second<<endl;
           count=max(count,it.second);
            
        }
        for(auto it:mp){
            if(it.second==count){
                ans.push_back(it.first);
            }
        }
        return ans;
        
    }
};