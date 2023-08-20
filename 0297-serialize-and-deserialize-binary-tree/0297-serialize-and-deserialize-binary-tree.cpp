/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return " NULL";
        }
        string cur=" ";
        cur+=to_string(root->val)+serialize(root->left)+serialize(root->right);
        return cur;
        
    }
    TreeNode*func(stringstream &ss){
        string cur;
        ss >> cur;
        if(cur=="NULL"){
            return NULL;
        }
        TreeNode*ans=new TreeNode(stoi(cur));
        ans->left=func(ss);
        ans->right=func(ss);
        return ans;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return func(ss);
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));