class Solution {
public:
    int func(vector<int>& cost, vector<int>& time,int i,int wall,vector<vector<int>>&dp)
    {
        if(wall<=0){
            return 0;
        }
        if(i<0){
            return 1e9;
        }
        if(dp[i][wall]!=-1){
            return dp[i][wall];
        }
        int nott=0+func(cost,time,i-1,wall,dp);
        int take=(cost[i]+func(cost,time,i-1,wall-time[i]-1,dp));
        return dp[i][wall]= min(take,nott);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return func(cost,time,n-1,n,dp);
    }
};