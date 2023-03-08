class Solution {
public:
    void dfs(int i,vector<vector<int>>&adj,vector<int>&vis)
    {
        vis[i]=1;
        for(int j=0;j<adj[i].size();j++){
            if(adj[i][j] and !vis[j] ){
                dfs(j,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
        int ans=0;
        vector<int>vis(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,adj,vis);
                
            }
        }
        return ans;
    }
};