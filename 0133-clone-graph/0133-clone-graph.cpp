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
    	unordered_map<Node*,Node*>v;

    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
    if(!v.count(node)){
        v[node] = new Node(node->val, {});
        for(auto &i : node->neighbors){
            v[node]->neighbors.push_back(cloneGraph(i));
        }
    }    
    return v[node];
    }
};