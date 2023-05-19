class Solution {
public:
    int col[101];
    bool vis[101];
    bool ans=1;
    void dfs(int cur,vector<vector<int>>&graph,int color)
    {
        if(vis[cur])return;
        vis[cur]=1;
        col[cur]=color;
        for(auto it:graph[cur]){
            dfs(it,graph,!color);
            if(col[it]==color){
                ans=0;
            }
        }
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        for(int i=0;i<n;i++){
            dfs(i,graph,0);
        }
        return ans;
    }
};