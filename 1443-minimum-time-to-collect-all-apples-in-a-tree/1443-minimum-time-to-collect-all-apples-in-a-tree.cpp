class Solution {
public:
    int dfs( vector<vector<int>>& edges, vector<bool>&Apple,vector<vector<int>>&adj,int u,int par,vector<bool>&vis)
    {
        int ans=0;
        vis[u]=true;
        int t=0;
        for(auto it:adj[u]){
           if(it==par)continue;
              t= dfs(edges,Apple,adj,it,u,vis);
                if(t || Apple[it]){
                    ans+=2+t;
                }
            
        }
        return ans;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>&Apple) {
        
        int ans=0;
        vector<vector<int>>adj(n);
        vector<bool>vis(edges.size(),0);
        for(int i=0;i<edges.size();i++){
            
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        
        return dfs(edges,Apple,adj,0,-1,vis);;;
        
    }
};