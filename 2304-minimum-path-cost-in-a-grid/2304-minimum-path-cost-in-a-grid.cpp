class Solution {
public:
    int func(vector<vector<int>>& grid, vector<vector<int>>& move,int i,int j,int n,int m,vector<vector<int>>&dp)
    {
        if(i==n-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=0;k<m;k++){
            ans=min(ans,grid[i][j]+move[grid[i][j]][k]+func(grid,move,i+1,k,n,m,dp));
        }
        return dp[i][j]= ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& move) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=INT_MAX;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<m;i++){
            ans=min(ans,func(grid,move,0,i,n,m,dp));
        }
        return ans;
    }
};