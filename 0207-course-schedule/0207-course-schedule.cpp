class Solution {
public:
    bool dfs( vector<int>adj[], vector<int>&vis,int id)
    {
         if(vis[id]==1)
            return true;
        if(vis[id]==0){
            vis[id]=1;
            for(auto edge : adj[id]){
                if(dfs(adj,vis,edge))
                    return true;
            }
        }
        vis[id] = 2;
        return false;
    }
    // so we will make a directed 
    bool canFinish(int n, vector<vector<int>>& p) {
        
        vector<int>adj[n];
        for(auto it:p){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
           
            
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(dfs(adj,vis,i)){
                return 0;
            }
        }
        return 1;
        
    }
};