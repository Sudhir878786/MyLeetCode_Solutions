class Solution {
public:
    int ans=1;
    int dist[100005];
    void dfs(int src,vector<vector<int>>&child,vector<int>&parent,string &s)
    {
        dist[src]=1;
        for(auto it:child[src]){
             dfs(it,child,parent,s);
            if(s[src]!=s[it]){
               
                ans=max(ans,dist[src]+dist[it]);
                dist[src]=max(dist[src],dist[it]+1);
            }
        }
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vector<vector<int>>child(n);
        for(int i=1;i<n;i++){
            child[parent[i]].push_back(i);
        }
      
       dfs(0,child,parent,s);
        return ans;
        
        
    }
};