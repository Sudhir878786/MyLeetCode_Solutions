class Solution {
public:
    int func(int i,int k,vector<int>&nums,vector<int>&dp)
    {
        int n=nums.size();
        if(i==nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int len=0;
        int maxi=INT_MIN;
        int ans=INT_MIN;
        // int sum=0;
        for(int j=i;j<min(i+k,n);j++){
            len++;
            maxi=max(nums[j],maxi);
        
           int sum=len*maxi+func(j+1,k,nums,dp);
            ans=max(ans,sum);
        }
        return  dp[i]= ans;
    }
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return func(0,k,nums,dp);
    }
};