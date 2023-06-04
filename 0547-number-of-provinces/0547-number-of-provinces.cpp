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
    int findCircleNum(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,nums,vis);
            }
        }
        return ans;
    }
};