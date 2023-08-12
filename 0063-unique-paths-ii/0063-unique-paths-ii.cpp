class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>&nums,vector<vector<int>>&dp)
    {
        if(i>=nums.size()|| j>=nums[0].size()|| i<0 || j<0 || nums[i][j]==1){
            return 0;
        }
        if(i==nums.size()-1 and j==nums[0].size()-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=dfs(i+1,j,nums,dp);
        int b=dfs(i,j+1,nums,dp);
        return dp[i][j]=(a+b);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        if(nums[0][0]!=1){
           return dfs(0,0,nums,dp);
        }
        return 0;
    }
};