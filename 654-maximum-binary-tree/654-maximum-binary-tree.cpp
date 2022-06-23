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
   TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        int end = n-1;
        return divide(nums,st,end);
    }
   
    TreeNode* divide(vector<int> &nums,int st,int end)
    {
        if(st>end)
        {
            return NULL;
        }
        int id = 0;
        int maxi = INT_MIN;
        for(int i=st;i<=end;i++)
        {
            if(nums[i] > maxi)
            {
                maxi = nums[i];
                id = i;
            }
        }
        TreeNode* root = new TreeNode(maxi);
        root->left = divide(nums,st,id-1);
        root->right = divide(nums,id+1,end);
        return root;
    }
};