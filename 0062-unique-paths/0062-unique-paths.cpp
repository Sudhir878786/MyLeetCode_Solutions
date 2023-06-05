class Solution {
public:
    int func(int i,int j, vector<vector<int>>&dp)
    {
        if(i<0 || j<0){
            return 0;
        }
        if(i==0 || j==0){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int l=func(i-1,j,dp);
        int r=func(i,j-1,dp);
        return dp[i][j]=l+r;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return func(m-1,n-1,dp);
    }
};