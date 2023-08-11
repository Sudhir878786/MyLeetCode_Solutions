class Solution {
public:
    int func(int i,vector<vector<int>>&nums,int tar,int ans,vector<vector<int>>&dp)
    {
        if(ans>tar){
            return 0;
        }
        if(ans==tar){
            return 1;
        }
        if(i==nums.size()){
            return tar==ans;
        }
        if(dp[i][ans]!=-1){
            return dp[i][ans];
        }
        
        int a=0+func(i+1,nums,tar,ans,dp)%1000000007;
        int b=0;
        for(int k=1;k<=nums[i][0];k++){
            b=(b+(func(i+1,nums,tar,ans+k*nums[i][1],dp)))%1000000007;
        }
        return  dp[i][ans]= (a+b)%1000000007;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n=types.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return func(0,types,target,0,dp);
    }
};