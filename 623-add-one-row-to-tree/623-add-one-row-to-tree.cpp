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
    void insert(TreeNode*root,int val,int depth,int i)  // taken i pointer to count the current level or depth of the tree
    {
        if(!root)return;   // base cases
        if(i==depth-1){     
            TreeNode* leftstore = root->left;      // remove the left node of root
            root->left = new TreeNode (val);          // create new node of val and add to left of the root
            root->left->left = leftstore;    // add the leftstore node to the left of new  node
            // similar approach for right subtree;
            TreeNode* rightstore = root->right;
            root->right = new TreeNode (val);
            root->right->right = rightstore;
        }
        else{
            insert(root->left,val,depth,i+1);
            insert(root->right,val,depth,i+1);
        }
        return;
        
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){  
            TreeNode* temp = new TreeNode (val);    // make new node of val
            temp->left=root;                        // connect the root to the left of the temp 
            return temp;
        }
        insert(root,val,depth,1);     
        return root;
    }
};