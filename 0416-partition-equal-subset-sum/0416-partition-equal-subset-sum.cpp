class Solution {
public:
    bool func(int n,int sum,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(sum==0)return true;
        if(n==0)return nums[n]==sum;
        if(dp[n][sum]!=-1)return dp[n][sum];
        int nott=func(n-1,sum,nums,dp);
        int take=0;
        if(nums[n]<=sum){
            take=func(n-1,sum-nums[n],nums,dp);
        }
        return dp[n][sum] =nott|| take;
    }
    bool canPartition(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        if(total%2==1)return false;
        else {
            
            int sum=total/2;
            vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
            return func(n-1,sum,nums,dp);
        }
        return false;
    }
};