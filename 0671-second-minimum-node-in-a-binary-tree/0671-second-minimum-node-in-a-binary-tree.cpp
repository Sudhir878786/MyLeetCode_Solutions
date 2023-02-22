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
    long long int ans=1e15;
    void func(TreeNode*root,int &curval)
    {
        if(!root)return ;
        if(root->val<ans and root->val>curval)
        {
            ans=root->val;
            return;
        }
        func(root->left,curval);
        func(root->right,curval);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)return 0;
        func(root,root->val);
        if(ans==1e15)return -1;
        return ans;
    }
};