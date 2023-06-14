class Solution {
public:
     bool func(int i,vector<int>&nums,int sum,vector<vector<int>>&dp)
    {
        if(i==nums.size()){
            if(sum==0){
                return true;
            }else{
                return false;
            }
        }
         if(dp[i][sum]!=-1)return dp[i][sum];
        int nottake=func(i+1,nums,sum,dp);
        int take=0;
        if(nums[i]<=sum){
            take=func(i+1,nums,sum-nums[i],dp);
        }
        return dp[i][sum]=take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n(nums.size());
        int sum=accumulate(begin(nums),end(nums),0);
        if(sum%2==1)return false;
        else {
            int cursum=sum/2;
            vector<vector<int>>dp(n+1,vector<int>(cursum+1,-1));
            return func(0,nums,cursum,dp);
        }
        return false;
        
    }
};