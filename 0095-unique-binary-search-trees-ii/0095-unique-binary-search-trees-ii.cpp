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
    vector<TreeNode*>func(int s,int e)
    {
        vector<TreeNode*>ans;
        if(s>e){
            ans.push_back(NULL);
            return ans;
        }
        for(int i=s;i<=e;i++){
            auto l=func(s,i-1);
            auto r=func(i+1,e);
            for(auto left:l){
                for(auto right:r){
                    TreeNode*cur=new TreeNode(i,left,right);
                    ans.push_back(cur);
                }
            }
        }
        return ans;
        
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)return vector<TreeNode*>();
        return func(1,n);
    }
};