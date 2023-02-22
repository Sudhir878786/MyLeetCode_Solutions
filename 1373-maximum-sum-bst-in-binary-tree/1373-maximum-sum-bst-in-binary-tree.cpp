class NodeValue {
public: 
    int minNode, maxNode, maxSum;
    
    NodeValue(int minNode, int maxNode, int maxSum)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSum = maxSum;
    }
};

class Solution {
    
private:
    NodeValue maxSumBSTHelper(TreeNode* root)
    {
        if(!root) return NodeValue(INT_MAX, INT_MIN, 0);
        
        auto left = maxSumBSTHelper(root->left);
        auto right = maxSumBSTHelper(root->right);
        
        if(left.maxNode < root->val && root->val < right.minNode)
        {
            //if BT is BST
            sum = max(sum, root->val + left.maxSum + right.maxSum);
            
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), root->val + left.maxSum + right.maxSum);
            
        }
        
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));   
    }
    
public:
    int sum=0;
    int maxSumBST(TreeNode* root) 
    {
        maxSumBSTHelper(root);
        return sum>0 ? sum : 0;
        
    }
};