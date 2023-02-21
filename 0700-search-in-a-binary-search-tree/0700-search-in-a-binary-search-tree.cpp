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
    TreeNode* searchBST(TreeNode* node, int val) {
        
        if(!node)return NULL;
        while(node and node->val!=val){
            if(node->val>val){
                node=node->left;
            }
            else{
                node=node->right;
            }            
        }
      
        return node;
        
    }
};