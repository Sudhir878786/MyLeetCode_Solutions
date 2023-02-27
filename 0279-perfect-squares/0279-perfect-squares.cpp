class Solution {
public:
    int func(int cur,vector<int>&dp)
    {
         int ans=cur;
        if(dp[cur]!=-1)return dp[cur];
        for(int i=1;i*i<=cur;i++){
            int sq=i*i;
            ans=min(ans,1+func(cur-sq,dp));
        }
        return dp[cur]=ans;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return func(n,dp);
    }
};