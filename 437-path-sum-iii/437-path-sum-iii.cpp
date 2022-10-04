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
    unordered_map<long ,long>mp;
    int count=0;
    void solve(TreeNode*root,int k,long sum)
    {
        
        if(!root)return; 
        sum+=root->val;         // cal the sum // adding root val
        if(sum==k)count++;          // if sum == target increase count
        if(mp.find(sum-k)!=mp.end()){  //  find in the map (sum-k)   
            count+=mp[sum-k];           // if found add in count
        }
        mp[sum]++;                     // add in map
        solve(root->left,k,sum);      
        solve(root->right,k,sum);
        mp[sum]--;                // we have to backtrack to find another path 
        return;
    }
   
    int pathSum(TreeNode* root, int k) {
        solve(root,k,0);        
        return count;
    }
};