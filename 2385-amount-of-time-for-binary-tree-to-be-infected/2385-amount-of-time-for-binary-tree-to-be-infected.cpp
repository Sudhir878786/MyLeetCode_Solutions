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
    unordered_map<TreeNode*,TreeNode*>mp;
    unordered_map<TreeNode*,bool>vis;
    // from target we can go left right parent   so we strore parent of each node   then find the start node  then do bfs from that start
    void findpar(TreeNode*root)
    {
        if(!root)return;
        if(root->left){
            mp[root->left]=root;
            findpar(root->left);
        }
        if(root->right){
            mp[root->right]=root;
            findpar(root->right);
        }
    }
    TreeNode* find(TreeNode*root,int start)
    {
        if(!root)return NULL;
        if(root->val==start){
            return root;
        }
        else{
            TreeNode*cur=find(root->left,start);
            if(!cur){
               cur=find(root->right,start);
            
            }
            return cur;
        }
        return NULL;
        
    }
    int amountOfTime(TreeNode* root, int start) {
        if(!root)return 0;
        findpar(root);
        auto tar=find(root,start);
        int ans=0;
        queue<TreeNode*>q;
        vis[tar]=true;
        q.push(tar);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto cur=q.front();
                q.pop();
                vis[cur]=true;
                if(cur->left and !vis[cur->left]){
                    q.push(cur->left);
                    vis[cur->left]=true;
                }
                if(cur->right and !vis[cur->right]){
                    q.push(cur->right);
                    vis[cur->right]=true;
                }
                if(mp[cur]and !vis[mp[cur]]){
                    q.push(mp[cur]);
                    vis[mp[cur]]=true;
                }
            }
            ans++;
        }
        return ans-1;
        
    }
};