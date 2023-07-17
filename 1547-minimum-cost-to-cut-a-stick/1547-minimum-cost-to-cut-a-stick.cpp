class Solution {
public:
    int func(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
    {
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i;k<=j;k++){
            int cur=cuts[j+1]-cuts[i-1]+func(i,k-1,cuts,dp)+func(k+1,j,cuts,dp);
            ans=min(ans,cur);
        }
        return dp[i][j]= ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+2,vector<int>(c+2,-1));
        return func(1,c,cuts,dp);
    }
};