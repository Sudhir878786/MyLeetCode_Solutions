class Solution {
public:

    int maxProfit(int d, vector<int>& price) {
        int n=price.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2+1,vector<int>(d+1,0)));
    // return func(0,0,k,n,price,dp);
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int k=1;k<=d;k++){
                    if(buy==0){
                        dp[i][buy][k]=max(dp[i+1][0][k],-price[i]+dp[i+1][1][k]);
                    }
                    if(buy==1){
                        dp[i][buy][k]=max(dp[i+1][1][k],price[i]+dp[i+1][0][k-1]);
                    }
                }
            }
        }
        return dp[0][0][d];
    }
};

