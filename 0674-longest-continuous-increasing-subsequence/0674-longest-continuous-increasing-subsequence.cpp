class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        vector<int>dp(n+1,1);
        dp[0]=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                dp[i]=1+dp[i-1];
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};