/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
      Node* dfs(Node* node,unordered_map<Node*,Node*>&mp)
    {
       vector<Node*>ans;
        Node* clone=new Node(node->val);
        mp[node]=clone;
        for(auto it:node->neighbors){
            if(mp.find(it)!=mp.end()){
                ans.push_back(mp[it]);
            }else{
                ans.push_back(dfs(it,mp));
            }
           
        }
         clone->neighbors=ans;
         return clone;
    }
    Node* cloneGraph(Node* root) {
        if(!root)return NULL;
        unordered_map<Node*,Node*>mp;
        if(root->neighbors.size()==0){
            Node* clone=new Node(root->val);
            return clone;
        }
        return dfs(root,mp);
    }
};