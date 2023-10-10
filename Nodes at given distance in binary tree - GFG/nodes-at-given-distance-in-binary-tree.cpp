//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    unordered_map<Node*,Node*>mp;
    Node*parent(Node*root,int tar)
    {
        if(!root)return NULL;
        Node*ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            if(cur->data==tar){
                ans=cur;
            }
            if(cur->left){
                q.push(cur->left);
                mp[cur->left]=cur;
            }
            if(cur->right){
                q.push(cur->right);
                mp[cur->right]=cur;
            }
        }
        return ans;
    }
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        // first store the parents of each node 
        Node*tar=parent(root,target);
        unordered_set<Node*>s;
        queue<Node*>q;
        q.push(tar);
        vector<int>ans;
        int lev=0;
        while(!q.empty()  and lev<=k){
            int n=q.size();
            if(lev==k){
                for(int i=0;i<n;i++){
                    ans.push_back(q.front()->data);
                    q.pop();
                }
                sort(ans.begin(),ans.end());
                return ans;
            }
            
            else{
                for(int i=0;i<n;i++){
                    auto cur=q.front();
                    q.pop();
                    if(s.find(cur)==s.end()){
                        s.insert(cur);
                    }
                    if(cur->left and s.find(cur->left)==s.end()){
                        q.push(cur->left);
                    }
                    if(cur->right and s.find(cur->right)==s.end()){
                        q.push(cur->right);
                    }
                    if(mp[cur] and s.find(mp[cur])==s.end()){
                        q.push(mp[cur]);
                    }
                }
            }
            lev++;
        }
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends