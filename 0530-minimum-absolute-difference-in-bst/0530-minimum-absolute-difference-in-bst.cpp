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
    vector<int>in;
    void func(TreeNode* root)
    {
        if(!root)return ;
        func(root->left);
        in.push_back(root->val);
        func(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX;
        func(root);
        // sort(in.begin(),in.end());
        for(int i=1;i<in.size();i++){
            // cout<<in[i]<<" "<<endl;
            ans=min(ans,(in[i]-in[i-1]));
        }
        return ans;
    }
};