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
    TreeNode* bstFromPreorder(vector<int>& p) {
        if(p.size()==0)return NULL;
        TreeNode* ans=new TreeNode(p[0]);
        if(p.size()==1)return ans;
        vector<int>left,right;
        for(int i=1;i<p.size();i++){
            if(p[i]<p[0]){
                left.push_back(p[i]);
            }else right.push_back(p[i]);
        }
        ans->left=bstFromPreorder(left);
        ans->right=bstFromPreorder(right);
        return ans;
    }
};