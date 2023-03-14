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
    string ans="";
    void func(TreeNode*root,string s)
    {
        if(!root)return;
        s+=char(97+root->val);
        if(!root->left and !root->right){
            reverse(begin(s),end(s));
            if(ans==""){
                ans=s;
            }
            else{
                ans=min(ans,s);
            }
        }
        
        
        func(root->left,s);
        func(root->right,s);
    }
    string smallestFromLeaf(TreeNode* root) {
        if(!root)return "";
        func(root,"");
        return ans;
    }
};