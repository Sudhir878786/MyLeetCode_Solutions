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
    void solve(TreeNode*root,vector<int>&s,int& count)
    {
        if(!root)return;
        s[root->val]++;
        solve(root->left,s,count);
        solve(root->right,s,count);
        
        if(root->left == NULL and root->right==NULL){
            int odd=0;
            for(int i=1;i<=9;i++){
                
                if(s[i]%2!=0)odd++;
                
            }
            if(odd==1 || odd== 0){
                    count++;
                }
        }
        s[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int count=0;
        vector<int>s(10,0);
        solve(root,s,count);
        return count;
        
    }
};