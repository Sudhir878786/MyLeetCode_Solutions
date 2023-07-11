/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>ans;
    unordered_map<TreeNode*,TreeNode*>mp;
    set<TreeNode*>st;
    void findpar(TreeNode*root)
    {
        if(!root)return ;
        if(root->left){
            mp[root->left]=root;
            findpar(root->left);
        }
        if(root->right){
            mp[root->right]=root;
            findpar(root->right);
        }
    }
    void dfs(TreeNode*tar,int k)
    {
        if(st.find(tar)!=st.end()){
            return;
        }
        st.insert(tar);
        if(k==0){
            ans.push_back(tar->val);
            return;
        }
        if(tar->left){
            dfs(tar->left,k-1);
        }
        if(tar->right){
            dfs(tar->right,k-1);
        }
        TreeNode* par=mp[tar];
        if(par){
            dfs(par,k-1);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root)return ans;
        // we need to find the parent for backtracking from the target node;
        findpar(root);
        dfs(target,k);
        return ans;
    }
};