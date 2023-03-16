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
    unordered_map<int,int>mp;
    TreeNode* func(vector<int>& inorder, vector<int>& postorder,int start,int end,int& cur)
    {
        if(start>end)return NULL;
        int ind=mp[postorder[cur]];
        TreeNode*ans=new TreeNode(postorder[cur--]);
        ans->right=func(inorder,postorder,ind+1,end,cur);
        ans->left=func(inorder,postorder,start,ind-1,cur);
        
        return ans;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int n=postorder.size()-1;
        return func(inorder,postorder,0,n,n);
    }
};