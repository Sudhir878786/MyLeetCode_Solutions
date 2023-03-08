class Solution {
public:

int dfs(vector<int>& cuts, int i, int j,vector<vector<int>>&dp) {
    if (j - i <= 1)
        return 0;
    if (!dp[i][j]) {
        dp[i][j] = dp[i][j];
    }
        for (auto k = i + 1; k < j; ++k)
            dp[i][j] = min(dp[i][j], 
                cuts[j] - cuts[i] + dfs(cuts, i, k,dp) + dfs(cuts, k, j,dp));
    
    return dp[i][j];
}
int minCost(int n, vector<int>& cuts) {
    int c=cuts.size();
       cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    
    vector<vector<int>> dp(c+2,vector<int>(c+2,0));
    
    for(int i=c; i>=1; i--){
        for(int j=1; j<=c; j++){
            
            if(i>j) continue;
            
            int mini = INT_MAX;
    
            for(int ind=i; ind<=j; ind++){
        
                int ans = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
        
                mini = min(mini, ans);
        
            }
    
            dp[i][j] = mini;
        }
    }
    
    return dp[1][c];


}
    
};