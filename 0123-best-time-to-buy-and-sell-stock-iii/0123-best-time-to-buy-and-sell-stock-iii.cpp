class Solution {
public:
    int func(int i,int buy,int k,vector<int>&p,vector<vector<vector<int>>>&dp)
    {
        if(k==0 || i==p.size()){
            return 0;
        }
        if(dp[i][buy][k]!=-1){
            return dp[i][buy][k];
        }
        int ans=0;
        if(buy==0){// buy
          ans=max(func(i+1,0,k,p,dp),-p[i]+func(i+1,1,k,p,dp));
        }
        if(buy==1){ // sell
            ans= max(func(i+1,1,k,p,dp),p[i]+func(i+1,0,k-1,p,dp));
        }
        return  dp[i][buy][k]= ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2+1,vector<int>(2+1,-1)));
        return func(0,0,2,prices,dp);
        
    }
};