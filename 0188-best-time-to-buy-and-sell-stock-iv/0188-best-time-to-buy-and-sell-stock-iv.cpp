class Solution {
public:
    int func(int i,int buy,int k,int n,vector<int>&p,vector<vector<vector<int>>>&dp)
    {
        if(k==0||i==n)return 0;
        int prof=0;
        if(dp[i][buy][k]!=-1)return dp[i][buy][k];
        if(buy==0){
            prof=max(0+func(i+1,0,k,n,p,dp),-p[i]+func(i+1,1,k,n,p,dp));
        }
        if(buy==1){
            prof=max(0+func(i+1,1,k,n,p,dp),p[i]+func(i+1,0,k-1,n,p,dp));
        }
        return  dp[i][buy][k]= prof;
    }
    int maxProfit(int k, vector<int>& price) {
        int n=price.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
    return func(0,0,k,n,price,dp);
    }
};

