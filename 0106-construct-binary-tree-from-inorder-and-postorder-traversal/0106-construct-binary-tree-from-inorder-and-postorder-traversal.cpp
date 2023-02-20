class Solution {
public:
 unordered_map<int,int>m;
    TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int start,int end,int &post){
        if(start>end) return NULL;
         int inorderIndex = m[postorder[post]];

        TreeNode* root = new TreeNode(postorder[post--]);    
        
        //(postIndex)--;
      root->right=solve(inorder,postorder,inorderIndex+1,end,post);
        root->left=solve(inorder,postorder,start,inorderIndex-1,post);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for(int i=0;i<inorder.size();i++){
           m[inorder[i]] = i;
            
        }
        int post=postorder.size()-1;
        return solve(inorder,postorder,0,postorder.size()-1,post);
    }
};
