class Solution
{
    public:	// count[i] store the total number of inc seq till i
        int findNumberOfLIS(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> dp(n + 1, 1), count(n + 1, 1);
            int ans = 0;
            int maxi = 0;
            for (int i = 0; i < n; i++)
            {
                for (int prev = 0; prev < i; prev++)
                {
                    if (nums[prev] < nums[i] and 1 + dp[prev] > dp[i])
                    {
                        dp[i] = dp[prev] + 1;
                        count[i] = count[prev];
                    }
                    else if (nums[prev] < nums[i] and 1 + dp[prev] == dp[i])
                    {
                        count[i] += count[prev];
                    }
                }
                maxi = max(maxi, dp[i]);
            }
            for (int i = 0; i < n; i++)
            {
                if (dp[i] == maxi)
                {
                    ans += count[i];
                }
            }
            return ans;
        }
};