class Solution
{
    public:
//         int func(int i, int buy, int n, vector<int> &p, vector<vector< int>> &dp)
//         {

//             if (i >= n) return 0;
//             int prof = 0;
//             if (dp[i][buy] != -1) return dp[i][buy];

//             if (buy == 0)
//             {
//                 prof = max(0 + func(i + 1, 0, n, p, dp), -p[i] + func(i + 1, 1, n, p, dp));
//             }
//             if (buy == 1)
//             {
//                 prof = max(0 + func(i + 1, 1, n, p, dp), p[i] + func(i + 2, 0, n, p, dp));
//             }
//             return dp[i][buy] = prof;
//         }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector < int>> dp(n + 2, vector<int> (2+1, 0));
        // return func(0, 0, n, prices, dp);
        
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0){
                    dp[i][buy]=max(dp[i+1][0],-prices[i]+dp[i+1][1]);
                }
                if(buy==1){
                    dp[i][buy]=max(dp[i+1][1],prices[i]+dp[i+2][0]);
                }
            }
        }
        return dp[0][0];
    }
};