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


class Node{
  public:
    int minn, maxx,size;
    Node(int minn,int maxx,int size)
    {
        this->minn=minn;
        this->maxx=maxx;
        this->size=size;
    }
};
// intutioon 


// we traverse from the bottom to up and ccheck for the maximum BST size
// we find the min max node in the left and min node in the right
class Solution {
public:
    int ans=0;
    Node func(TreeNode*root)
    {
        if(!root){
            return Node(INT_MAX,INT_MIN,0);
        }
        
        auto left=func(root->left);  // bittom to top
        auto right=func(root->right);
        // if the cur tree is BST
        if(root->val>left.maxx and root->val<right.minn)
        {
            ans=max(ans,left.size+right.size+root->val);
            return Node(min(root->val,left.minn),max(root->val,right.maxx),left.size+right.size+root->val);
        }
        return Node(INT_MIN,INT_MAX,max(left.size,right.size));
        
    }
    int maxSumBST(TreeNode* root) {
        func(root);
        if(ans>0){
            return ans;
        }
        return 0;
      
    }
};