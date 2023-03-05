class Solution
{
    public:
        int func(int i, int n, int prev, vector<int> &nums, vector<vector< int>> &dp)
        {
            if (i == n) return 0;
            if (dp[i][prev + 1] != -1) return dp[i][prev + 1];
            int npic = 0 + func(i + 1, n, prev, nums, dp);
            int nott = 0;
            if (prev == -1 || nums[i] > nums[prev])
            {
                nott = 1 + func(i + 1, n, i, nums, dp);
            }
            return dp[i][prev + 1] = max(nott, npic);
        }
    int lengthOfLIS(vector<int> &nums)
    {
        int n=nums.size();
        vector<int>dp(n+1,1);
        int ans=1;
        for(int i=0;i<n;i++){
            for(int pre=0;pre<i;pre++){
                if(nums[i]>nums[pre]){
                    dp[i]=max( dp[i] ,1+dp[pre]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};