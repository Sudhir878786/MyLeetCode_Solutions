class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        int ma=0;
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
            if(word1[i-1]==word2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                
            }
            dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i][j-1]});
                ma=max(ma,dp[i][j]);
                }
        }
        return m-ma+n-ma;
    }
};