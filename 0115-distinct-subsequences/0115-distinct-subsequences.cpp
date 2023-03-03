class Solution {
public:
    
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int prime = 1e9+7;
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<m+1;i++){
        dp[0][i]=0;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            
            if(s[i-1]==t[j-1])
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%prime;
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    
    
    return dp[n][m];
    }
};