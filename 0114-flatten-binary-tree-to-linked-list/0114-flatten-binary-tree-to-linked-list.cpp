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
    void flatten(TreeNode* root) {
        // so  first we strore the right of the root in temp var  
        // we will move to the right most leaf by increasing a node variable 
        // then node of right will be concatenated with the temp;
        
        if(!root)return ;
        while(root){
            TreeNode*temp=root->right;
            root->right=root->left;
            root->left=NULL;
            TreeNode* node=root;
            while(node->right){
                node=node->right;
            }
            node->right=temp;
            
            
            root=root->right;
        }
    }
};