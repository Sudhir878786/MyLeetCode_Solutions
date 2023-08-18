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
        if(!root)return 0;
        int ans=1;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            int start=q.front().second;
            int end=q.back().second;
            ans=max(ans,end-start+1);
            for(int i=0;i<n;i++){
                auto cur=q.front();
                q.pop();
                int ind=cur.second-start;
                if(cur.first->left){
                    q.push({cur.first->left,(long long)2*ind+1});
                }
                if(cur.first->right){
                    q.push({cur.first->right,(long long)2*ind+2});
                }
            }
            
        }
        return ans;
        
    }
};