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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans =0;
        queue<pair<TreeNode* , int>>q;
        q.push({root,0});
        while(!q.empty()){
          int s= q.size();
          int start=q.front().second;
          int end=q.back().second;
          ans=max(ans,end-start+1);
          for(int i=0;i<s;i++){
            pair<TreeNode*,int>p=q.front();
            TreeNode* node = p.first;
            long long idx=p.second;
            q.pop();
            if(node->left) q.push({node->left, 2*idx+1});
            if(node->right) q.push({node->right, 2*idx+2});
            
          }
        }
        
      return ans;
        
    }
};