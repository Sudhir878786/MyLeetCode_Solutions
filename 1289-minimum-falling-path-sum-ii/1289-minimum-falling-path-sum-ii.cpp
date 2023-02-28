class Solution {
public:
   int solve(vector<vector<int>>& grid, int i, int j, int n, int m,vector<vector<int>>&dp){
        if(i==n-1)
            return grid[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int tempAns=INT_MAX;
        for(int k=0;k<m;k++){
            if(k!=j)
                tempAns=min(tempAns,grid[i][j]+solve(grid,i+1,k,n,m,dp));
        }
        
        return dp[i][j]=tempAns;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        int ans=INT_MAX;
        
        for(int i=0;i<m;i++)
            ans=min(ans,solve(grid,0,i,n,m,dp));
        
        return ans;
    }
};