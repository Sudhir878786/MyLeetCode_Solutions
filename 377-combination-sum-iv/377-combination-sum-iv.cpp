// class Solution {
// public:
//     int combinationSum4(vector<int>& nums, int t) {
//         int ans=0;
//         if(t<0)return 0;
//         if(t==0)return 1;
        
//         for(int i=0;i<nums.size();i++){
//             ans+=combinationSum4(nums,t-nums[i]);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int solve(vector<int>& nums, int t,vector<int>&dp){
         int ans=0;
        
        if(t<0)return 0;
        if(t==0)return 1;
        if(dp[t]!=-1){
            return dp[t];
        }
        
        for(int i=0;i<nums.size();i++){
            ans+=solve(nums,t-nums[i],dp);
        }
        dp[t]=ans;
        return dp[t];
    }
    int combinationSum4(vector<int>& nums, int t) {
       vector<int>dp(t+1,-1);
        return solve(nums,t,dp);
    }
};