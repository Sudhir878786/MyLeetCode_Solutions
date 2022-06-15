class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int i, prev, n = a.size(), ans = 1;
        vector<int> dp(n, 1);
        for(i=0; i<n; i++) {
            for(prev=0; prev<i; prev++) {
                if(a[prev] < a[i]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};