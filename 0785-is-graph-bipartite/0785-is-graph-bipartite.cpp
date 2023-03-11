class Solution {
public:
    bool vis[105];
    int col[105];
    bool ans=true;
    void dfs(int cur,vector<vector<int>>&graph,int color)
    {
        if(vis[cur])return;
        vis[cur]=true;
        col[cur]=color;
        for(auto it:graph[cur]){
                
                dfs(it,graph,!color);
                if(color==col[it]){
                    ans=false;
                }
            
        }
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
         for(int i=0;i<graph.size();i++)
         {
             dfs(i,graph,0);
         }
        return ans;
    }
};