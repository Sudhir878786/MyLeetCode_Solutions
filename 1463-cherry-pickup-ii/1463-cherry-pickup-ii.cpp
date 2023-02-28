class Solution {
public:
    int func(int i, int j1,int j2,int n,int m ,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp)
    {
        if(j2<0 || j1<0 || j1>=m|| j2>=m){
            return -1e9;
        }
        if(i==n-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int ans=INT_MIN;
        for(int a=-1;a<=+1;a++){
            for(int b=-1;b<=+1;b++){
                int cur=0;
                if(j1==j2){
                    cur=grid[i][j1]+func(i+1,j1+a,j2+b,n,m,grid,dp);
                }
                else{
                    cur=grid[i][j1]+grid[i][j2]+func(i+1,j1+a,j2+b,n,m,grid,dp);
                }
                ans=max(ans,cur);
                
            }
        }
        return  dp[i][j1][j2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>>dp(grid.size()+1,vector<vector<int>>(grid[0].size()+1,vector<int>(grid[0].size()+1,-1)));
        return func(0,0,grid[0].size()-1,grid.size(),grid[0].size(),grid,dp);
    }
};