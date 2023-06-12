class Solution {
public:
     int helper(int i,int j,int n,vector<vector<int>> &triangle,vector<vector<int>>&dp)
    {
        if(i==n-1)
            return triangle[i][j];
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int move1 = triangle[i][j] + helper(i+1,j,n,triangle,dp);
        int move2 = triangle[i][j] + helper(i+1,j+1,n,triangle,dp);
        return dp[i][j]= min(move1,move2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(0,0,n,triangle,dp);
    }
};