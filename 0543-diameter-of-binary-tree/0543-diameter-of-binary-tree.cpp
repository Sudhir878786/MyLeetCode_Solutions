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
    int ans=0;
  // basically we need to itereate through the depth of the tree and cal corresponding diametere = left+right+1;
    int solve(TreeNode*inorder,int d)
{
	if(!inorder)return 0;
	int left=solve(inorder->left,d);
	int right=solve(inorder->right,d);
	ans=max(ans,left+right);
	return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* inorder) {
         solve(inorder,ans);
        return ans;
    }
};