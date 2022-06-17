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
    int count=0;
    int findcam(TreeNode* root){
        if(!root) return 1;
        int a = findcam(root->left);
        
        int b = findcam(root->right);
        if(a==0 || b==0){ count++;return 2;}
        if(a==1 and b==1)return 0;
        else return 1;
    }
    int minCameraCover(TreeNode* root) {
        int ans=findcam(root);
        if(ans==0)return count+1;
        return count;
        
        
    }
};