class Solution {
public:
    int func(int i,int n,int prev,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i==n)return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int npic=0+func(i+1,n,prev,nums,dp);
        int nott=0;
        if(prev==-1 || nums[i]>nums[prev]){
            nott=1+func(i+1,n,i,nums,dp);
        }
        return  dp[i][prev+1]=max(nott,npic);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return func(0,n,-1,nums,dp);
    }
};