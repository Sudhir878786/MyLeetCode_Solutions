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
    // int func(TreeNode*root,int data){
    //     if(!root || root->val==data){
    //         return 0;
    //     }
    //     return max(func(root->left,data),func(root->right,data))+1;
    // }
    map<int,int>l,r,ans;
    int height(TreeNode*root){
        if(!root){
            return 0;
        }
        int a=height(root->left);
        int b=height(root->right);
        l[root->val]=a;
        r[root->val]=b;// store the max height from the cur node in map
        return max(a,b)+1;
    }
    void func(TreeNode*root,int maxx,int dep)
    {
        if(!root){
            return;
        }
        ans[root->val]=maxx;
        func(root->left,max(maxx,dep+r[root->val]),dep+1);
        func(root->right,max(maxx,dep+l[root->val]),dep+1);
        
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // vector<int>ans;
        // for(auto it:queries){
        //     ans.push_back(func(root,it)-1);
        // }
        // return ans;
        vector<int>res(queries.size());
        height(root);
        // now we go to left and take the max hight on the right
        func(root->left,r[root->val],1);
        func(root->right,l[root->val],1);
        for(int i=0;i<queries.size();i++){
            res[i]=ans[queries[i]];
        }
        return res;
    }
};