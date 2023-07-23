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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*>ans;
        if(n%2==0){
            return {};
        }
        if(n==1){
            return {new TreeNode(0)};
        }
        for(int i=1;i<n;i+=2){
            auto left=allPossibleFBT(i);
            auto right=allPossibleFBT(n-i-1);
            for(auto it:left){
                for(auto x:right){
                    ans.push_back(new TreeNode(0,it,x));
                }
            }
        }
        return ans;
    }
};